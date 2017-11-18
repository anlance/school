  **知命不惧 · 日日自新**
  ================
 ##### **_`大二上`的一些学习记录_**<br>

 -----------------------------------------------------------<br>
> 先生，不唱第二部分吗<br>
> 我还没教你独唱部分呢<br>
> 可我已经会唱了<br>

-----------------------------------------------------------<br>
 ## [CSAPP](https://github.com/anlance/anlance/tree/master/CSAPP)
   * 深入理解计算机系统书上的例题以及习题代码（部分）<br>
 ## [Cf](https://github.com/anlance/anlance/tree/master/Cf)
   * do *codeforces*  `C++`实现<br>
 ## [JsGame](https://github.com/anlance/anlance/tree/master/JsGame)
   * 周末在B站上看的萧井陌的视频，跟着写写<br>
 ## [LnJava](https://github.com/anlance/anlance/tree/master/LnJava)
   * **`CDUT`** 2016级 _《java程序设计使用教程》(第二版 )_  课后实验代码<br>
   * 部分输出的内容作了一些小修改<br>
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
          * 修改，客户可退出（且服务器不关闭）(算小小的优化了一下这该死的书上的代码了吧)<br>
          **2017-11-15（完结撒花）**
          -----------------------------------------------------------------------

 ## [SeaLong](https://github.com/anlance/anlance/tree/master/SeaLong)
   * 放了一些奇妙的东西<pr>
 ## [WhiteBook](https://github.com/anlance/anlance/tree/master/WhiteBook)
   * _挑战程序设计竞赛(第二版)_ <br>
   * ~~换个方式，先看一遍，通看之后再来一遍~~<br>
   * 做`USACO`一起书上的,先做再看再做.
 ## [osExperiment](https://github.com/anlance/anlance/tree/master/osExperiment)
   * **`CDUT`** 2016级**操作系统**实验<br>