package chapter7;
//CompanySalary.java

abstract class Employee{
    public abstract double earnings();
}
class YeatWorker extends Employee{
    public double earnings(){
        return 12000;
    }
}
class MonthWorker extends Employee{
    public double earnings(){
        return 12*6730;
    }
}
class Company{
    Employee employee[];
    double salaries = 0;
    Company(Employee [] employee){
        this.employee = employee;
    }
    public double salariesPay(){
        this.salaries = 0;
        for(Employee i:employee){
            this.salaries += this.salaries+i.earnings();
        }
        return this.salaries;
    }
}
public class CompanySalary{
    public static void main(String []args){
        Employee []employee = new Employee[129];
        for (int i=0;i<employee.length;i++){
            if(i%2==0)
                employee[i] = new YeatWorker();
            else
                employee[i] = new MonthWorker();
        }
        Company company = new Company(employee); 
        System.out.println("公司薪水总额："+company.salariesPay()+"元");
    }
}