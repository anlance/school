package club.anlan.beans;


import java.util.HashSet;
import java.util.Set;

public class Order {
    private Integer id;
    private Integer goodsNum;
    private double oneGoodsUnitPrice;
    private Integer oneGoodsNum;
    private double totalPrice;
    private User user;
    private Set<Goods> goodsMore;


    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getGoodsNum() {
        return goodsNum;
    }

    public void setGoodsNum(Integer goodsNum) {
        this.goodsNum = goodsNum;
    }

    public double getOneGoodsUnitPrice() {
        return oneGoodsUnitPrice;
    }

    public void setOneGoodsUnitPrice(double oneGoodsUnitPrice) {
        this.oneGoodsUnitPrice = oneGoodsUnitPrice;
    }

    public Integer getOneGoodsNum() {
        return oneGoodsNum;
    }

    public void setOneGoodsNum(Integer oneGoodsNum) {
        this.oneGoodsNum = oneGoodsNum;
    }

    public double getTotalPrice() {
        return totalPrice;
    }

    public void setTotalPrice(double totalPrice) {
        this.totalPrice = totalPrice;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public Set<Goods> getGoodsMore() {
        return goodsMore;
    }

    public void setGoodsMore(Set<Goods> goodsMore) {
        this.goodsMore = goodsMore;
    }

    public Order(){

    }

    public Order(Integer goodsNum, double oneGoodsUnitPrice, Integer oneGoodsNum, double totalPrice){
        this.goodsNum = goodsNum;
        this.oneGoodsUnitPrice = oneGoodsUnitPrice;
        this.oneGoodsNum = oneGoodsNum;
        this.totalPrice = totalPrice;
        this.goodsMore = new HashSet<Goods>();
    }

    public Order(Integer goodsNum, double oneGoodsUnitPrice, Integer oneGoodsNum, double totalPrice, User user){
        this.goodsNum = goodsNum;
        this.oneGoodsUnitPrice = oneGoodsUnitPrice;
        this.oneGoodsNum = oneGoodsNum;
        this.totalPrice = totalPrice;
        this.user = user;
        this.goodsMore = new HashSet<Goods>();
    }

    public Order(Integer goodsNum, double oneGoodsUnitPrice, Integer oneGoodsNum, double totalPrice, User user, Set<Goods> goodsMore){
        this.goodsNum = goodsNum;
        this.oneGoodsUnitPrice = oneGoodsUnitPrice;
        this.oneGoodsNum = oneGoodsNum;
        this.totalPrice = totalPrice;
        this.user = user;
        this.goodsMore = goodsMore;
    }

    public void addGoods(Goods goods){
        this.getGoodsMore().add(goods);
    }

    public void removeGoods(Goods goods){
        this.getGoodsMore().remove(goods);
    }

    public void clearAll(){
        this.goodsMore = new HashSet<Goods>();
    }

    @Override
    public String toString() {
        return "id: "+getId()+" goodsNum: "+ getGoodsNum()+ "totalPrice: " + totalPrice +" user"+ getUser();
    }
}
