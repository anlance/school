package club.anlan.beans;

import java.util.HashSet;
import java.util.Set;

public class Goods {
    private Integer id;
    private String name;
    private double unitPrice;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getUnitPrice() {
        return unitPrice;
    }

    public void setUnitPrice(double unitPrice) {
        this.unitPrice = unitPrice;
    }

    public Goods(){

    }

    public Goods(String name, double unitPrice){
        this.name = name;
        this.unitPrice = unitPrice;
    }

}
