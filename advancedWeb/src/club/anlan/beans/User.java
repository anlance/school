package club.anlan.beans;

import club.anlan.dao.UserDao;

import java.util.HashSet;
import java.util.Set;

public class User implements UserDao {
    private Integer id;
    private Integer role;
    private String username;
    private String password;
    private Integer age;
    private Address address;
    private Set<Order> orders;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getRole() {
        return role;
    }

    public void setRole(Integer role) {
        this.role = role;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }

    public Address getAddress() {
        return address;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public Set<Order> getOrders() {
        return orders;
    }

    public void setOrders(Set<Order> orders) {
        this.orders = orders;
    }

    public User(){
    }


    public User(Integer role, String username, Integer age,String password){
        this.role = role;
        this.username = username;
        this.age = age;
        this.password = password;
        this.orders = new HashSet<Order>();
    }



    public User(Integer role, String username, Integer age,String password, Set<Order> orders){
        this.role = role;
        this.username = username;
        this.age = age;
        this.password = password;
        this.orders = orders;
    }

    @Override
    public String toString() {
        return ("role="+role+", id="+id+", username="+username+", age="+age);
    }

    public void addOrder(Order order){
        this.getOrders().add(order);
    }

    public void removeOrder(Order order){
        this.getOrders().remove(order);
    }

    @Override
    public void insert() {
        System.out.println("持久化以上数据");
    }
}
