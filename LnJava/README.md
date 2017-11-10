* vscode里面调用jdk编译应该是需要包的整个路径，所以我直接注释了。
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
