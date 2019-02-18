package club.anlan.test;

import club.anlan.beans.Address;
import club.anlan.beans.Goods;
import club.anlan.beans.Order;
import club.anlan.beans.User;
import club.anlan.util.hbnUtils;
import org.hibernate.Criteria;
import org.hibernate.Session;
import org.hibernate.criterion.Criterion;
import org.hibernate.criterion.Expression;
import org.hibernate.criterion.Projections;
import org.hibernate.query.NativeQuery;
import org.junit.Test;

import javax.management.Query;
import java.util.List;
import java.util.Set;


public class TestHibernate {
    @Test
    public void testSave(){
        Session session = hbnUtils.getSession();

        try {
            session.beginTransaction();
            User user1 = new User(0,"小明",16,"123456");
            User user2 = new User(0,"小红",17,"123456");
            User user3 = new User(0,"小绿",18,"123456");

            Address address1 = new Address("四川");
            Address address2 = new Address("上海");
            Address address3 = new Address("北京");

            Goods goods1 = new Goods("苹果",5.5);
            Goods goods2 = new Goods("香蕉",4.5);
            Goods goods3 = new Goods("菠萝",3.5);
            Goods goods4 = new Goods("橘子",2.5);

            // 1号人物有2张订单，分别是1 2订单
//            Order order1 = new Order(1,5.5,10,55,user1);
//            Order order2 = new Order(2,4.5,10,45,user1);
//            Order order3 = new Order(3,3.5,10,35,user2);
//            Order order4 = new Order(4,2.5,10,25,user3);
            Order order1 = new Order(1,5.5,10,55);
            Order order2 = new Order(2,4.5,10,45);
            Order order3 = new Order(3,3.5,10,35);
            Order order4 = new Order(4,2.5,10,25);


            //3号商品在4张订单中，分别是1 2 3 4
            order1.addGoods(goods1);
            order2.addGoods(goods2);
            order3.addGoods(goods3);
            order4.addGoods(goods4);
            order1.addGoods(goods3);
            order2.addGoods(goods3);
            order4.addGoods(goods3);

            //1号用户有两个订单
            user1.addOrder(order1);
            user1.addOrder(order2);
            user2.addOrder(order3);
            user3.addOrder(order4);


            user1.setAddress(address1); //1号人物有一个地址 ，是1号
            user2.setAddress(address2);
            user3.setAddress(address3);

            session.save(user1);
            session.save(user2);
            session.save(user3);

            session.getTransaction().commit();
        } catch (Exception e) {
            e.printStackTrace();
            session.getTransaction().rollback();
        }
    }

    // 实验4

    @Test
    public void testQuery1(){ //删除1号用户
        Session session = hbnUtils.getSession();

        try {
            session.beginTransaction();

            String sqlString="select * from user where username = '小明'";
            List<User> list = session.createSQLQuery(sqlString).addEntity(User.class).list();
            for(User user:list)
            {

                System.out.print(user.toString());
                session.delete(user);
            }
            session.getTransaction().commit();
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            session.getTransaction().rollback();
        }
    }

    @Test
    public void testQuery2(){   //删除1号商品
        Session session = hbnUtils.getSession();

        try {
            session.beginTransaction();

            String sqlString="select * from goods where id = 1";
            List<Goods> list = session.createSQLQuery(sqlString).addEntity(Goods.class).list();
            for(Goods goods:list)
            {
                System.out.print(goods.toString());
                // 取消级联
                String sqlString2="select * from t_order";
                List<Order> list2 = session.createSQLQuery(sqlString2).addEntity(Order.class).list();
                for(Order order:list2){
                    order.removeGoods(goods);
                }
                session.delete(goods);
            }
            session.getTransaction().commit();
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            session.getTransaction().rollback();
        }
    }

    // 实验5
    @Test
    public void testHql(){
        Session session = hbnUtils.getSession();

        try{
            session.beginTransaction();
            // 查询指定用户名的所有信息
            String hql1 = "from User where username=:tname";
            List<User> listUser = session.createQuery(hql1).setString("tname","小明").list();
            for(User user:listUser){
                System.out.println("查询指定用户名的所有信息:");
                System.out.println(user);
            }
            // 查询指定用户名的用户名和密码
            String hql2 = "select username,password from User where username=:tname";
            List<Object[]> list = session.createQuery(hql2).setString("tname","小明").list();
            for(Object[] item:list){
                System.out.println("查询指定用户名的用户名和密码:");
                System.out.println(item[0]+" "+item[1]);
            }
            // 根据用户名查询用户姓名以及该用户的订单
            // lazy = false 立即查询
            // lazy = true 延时查询
            String hql3 = "select u.username,o from User u ,Order o where u.username=:tname and u = o.user";
            List<Object[]> list3 = session.createQuery(hql3).setString("tname","小明").list();
            System.out.println("根据用户名查询用户姓名以及该用户的订单:");
            for(Object[] item:list3){
                System.out.println(item[0]+" "+item[1]);
            }
            //利用多表连接完成订单表和订单项表或者商品表的连接查询，查询属于某一订单的全部订单商品信息。
            String sql4 = "select ogd.goods_id from t_order o left outer join ordergoods_double ogd on o.id=ogd.order_id and o.id=1";
            NativeQuery query = session.createSQLQuery(sql4);
            List<Object> list4 = ((org.hibernate.query.Query) query).list();
            System.out.println("利用多表连接完成订单表和订单项表或者商品表的连接查询，查询属于某一订单的全部订单商品信息。");
            for(Object o:list4){
                System.out.println(o);
            }

            //利用内置的操作方法qbc完成对用户名当中包含了“小”字的所有用户进行查询。
            Criteria criteria = session.createCriteria(User.class);
            Criterion criterion1= Expression.like("username", "小%") ;
            criteria=criteria.add(criterion1);
            List result=criteria.list();
            List<User> list5 = criteria.list();
            System.out.println("利用内置的操作方法qbc完成对用户名当中包含了“小”字的所有用户进行查询。");
            for(User student:list5){
                System.out.println(student);
            }

            // load加载的操作练习，加载用户为小明的所有订单记录
            Set<Order> orders = session.load(User.class,1).getOrders();
            System.out.println("load加载的操作练习，加载用户为小明的所有订单记录");
            for(Order o:orders){
                System.out.println(o);
            }
            session.getTransaction().commit();
        }
        catch (Exception e){
            System.out.println(e);
            session.getTransaction().rollback();
        }
    }

}
