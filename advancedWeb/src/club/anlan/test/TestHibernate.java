package club.anlan.test;

import club.anlan.beans.Student;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;
import org.junit.Test;

import java.util.List;


public class TestHibernate {
    @Test
    public void testSave(){
        Configuration configure = new Configuration().configure();
        SessionFactory sessionFactory = configure.buildSessionFactory();
        Session session = sessionFactory.getCurrentSession();

        try {
            session.beginTransaction();
            Student student = new Student(1,"天下第一",23, "dddd");
            session.save(student);
            session.getTransaction().commit();
        } catch (Exception e) {
            e.printStackTrace();
            session.getTransaction().rollback();
        }
    }

    @Test
    public void testQuery(){
        Configuration configure = new Configuration().configure();
        SessionFactory sessionFactory = configure.buildSessionFactory();
        Session session = sessionFactory.getCurrentSession();

        try {
            session.beginTransaction();
            String sqlString="select * from student";
            List<Student> list = session.createSQLQuery(sqlString).addEntity(Student.class).list();
            for(Student student:list)
            {
                System.out.println(student.toString());
            }
//            session.getTransaction().commit();
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            session.getTransaction().rollback();
        }
    }
}
