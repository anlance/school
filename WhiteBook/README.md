* ## BFS   DFS   qiongjie
    * 宽度优先、深度优先、穷竭 方面的书上的题，待整理<br>
* ## Chapter_mid 
    * 书上的代码<待整理><br>
* ## DoOne_OneDay
    * 一些常见的算法，加深熟练度
*   ## USACO
    * ### Section1.2
    * ### Section1.3
        * #### `milk2.cpp`<br>
            * 适合：解决这种多段性质的<br>
            * ![milk2](https://github.com/anlance/anlance/blob/master/WhiteBook/USACO/picture/milk2.png)<br>
            * 核心：1) 先按照起点排序;  2) 先比较下组起点的位置;  3) 再比较下组终点的位置.<br>
        * #### `transform.cpp`<br>
            * 这道题只需模拟每个状态即可，我总想重用代码，结果后来就云里雾里了<br>
        * #### `namenum.cpp`、`palsuare.cpp`、`dualpal.cpp`<br>
            * 字符串、数字的转换、进制的转换、回文数的判断
                ```c++
                //i*i
                if(temp/N!=0){  //temp转换成N进制
                    while(temp/N!=0){
                        pa += pp[temp % N];
                        temp = temp / N;
                    }
                }
                pa += pp[temp % N]; //易忽略
                reverse(pa.begin(), pa.end());  //字符串的反转
                ```
            * 双回文数中，把判断条件用int表示即可<br>
            * 这几道题做下来，感觉就是：**每道题应该想清楚数据初始化的地方！**<br>
    * ### Section1.4
        * #### `milk.cpp` `barn1.cpp`
            * **贪心算法**<br>
            * 贪心，尤其要注意排序，排序的长度、方式等等；还有就是每次比较的起点和终点<br>
            * 注意不只是开始和结果有因果关系，过程中也有很多关系，可以直接在过程中动手，避免初始数据的过于庞大<br>