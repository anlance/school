* **`vscode里面调用jdk编译应该是需要包的整个路径，所以我直接注释了。`**
* ### chapter4
    * 看了一圈，没什么好修改的hhh.<br>
* ### chapter5
    * ~~在第二个关于面积的实验中，始终有关于%10.3f的异常，就算我把代码复制到eclipse下也是，但室友的复制到eclipse下就没问题.~~<br>
    * hhh上面的异常是因为我用的`"ssss \n %10.3f"+theArea`而不是`"ssss \n %10.3f",theArea`;<br>
* ### chapter6
    * 某本书上写的： `接口就是一份契约，由类实现契约。契约中我编写了某些大的方针与前提，而签了约的类可以具体问题具体分析来实现自己的功能`<br>
    * ![interface](https://github.com/anlance/anlance/blob/master/SeaLong/picture/interface.png)<br>
    * 手机(打印机)就是USB接口的子类，这样，电脑上应用了这个接口之后，这些子类都可以在电脑上使用，但是只能做接口权限内能做的事情。<br>
* ### chapter7
    * 第一个数组实验，改变了c、d的元素，不输出来看看是什么意思=.=|||所以我输出了<br>
    * java中的循环是真的不错,大爱这个foreach语法(虽然不灵活)
      ```java
      for(Employee i:employee){//从0开始
            this.salaries += this.salaries+i.earnings();
        }
      ```
* ### chapter8
    * 内部类，编译生成的class文件名为`外嵌类名$内部类名.class`<br>
    * 异常类，感觉有点if-else + search 来做到的（虽然实际比这难得多）<br>
* ### chapter9
    * public static String toString(int i, int p) (返回 i 的 p 进制表示)<br>
      ```java
      System.out.println("2:"+Integer.toString(12345,2));
      ```
      Integer 类在对象中包装了一个基本类型 int 的值。**Integer 类型的对象包含一个 int 类型的字段.**
      此外，该类提供了多个方法，能在 int 类型和 String 类型之间互相转换，还提供了处理 int 类型时非常有用的其他一些常量和方法。<br>
* ### chapter14
    * 修改，客户可退出（且服务器不关闭）(算小小的优化了一下这该死的书上的代码了吧)
* ### **2017-11-15（完结撒花）**
-----------------------------------------------------------------------

