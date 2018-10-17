package club.anlan.beans;

public class Student {
    private Integer id;
    private Integer role;
    private String username;
    private String password;
    private Integer age;

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

    public Student(){
    }


    public Student(Integer role, String username, Integer age,String password){
        this.role = role;
        this.username = username;
        this.age = age;
        this.password = password;
    }


    @Override
    public String toString() {
        System.out.println("role="+role+", id="+id+", username="+username+", age="+age);
        return super.toString();
    }
}
