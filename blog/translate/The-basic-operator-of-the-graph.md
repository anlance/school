
This is a course design of our computer problem solving course,we finished the work in the environment of final review. Although it waws not a satifactorty answer, the degree of complation was still relatively high.
I'm going to summarize and restore what I've done.

### title

Understand the basic concept of graph theory, the matrix representation of graphs, the connectively of graphs, the traversal of graphs, and obtain the connected branches of graphs. Implement the following functions:<br>
Divisiong of label suggestion:<br>
1. Input the edge of an undirected simple graph in the form of a pair of nodes, establish the adjacent matrix of this graph, and determine whether the graph is connected. (1 person)
2. Calculate the distance between any two points. (1 person)
3. Output each commected branche from the disconnected graph. (1 person)
4. Build the system structure. (1 person)

### process and analysis

I was responsible for system construction (actually, the establishment of the graphical interface). Considering the relationship between QT and C++, I naturally chose QT to develope the graphical interface.

#### the first pit (biginner)

When learning something new, try to choose a related documentation or realted books rather than video beacse vedio is too slow.
QT can directly design UI, buttons, input components, display components, and so on. But based on my analysis, there are at least seven or eight inerface.
So I have to do it in code. (what would I do if I had to  if all the UI were coming by designing directly ==)
![interface](http://blog-1253928653.file.myqcloud.com/Image/GraphOperator/flowPath.jpg)<br>

#### the second pit (components design)

For these components settings, define as few components as possible ti make the entire code less cluttered.
At that time took simple `if-else` to achieve a goal,such as:

```c++
void Dialog::setNextBtn(QString text, int x, int y, int width, int hight, QString image)
{
    nextBtn = new QPushButton(this);
    nextBtn->setText(text);
    nextBtn->setGeometry(QRect(x, y, width, hight));
    nextBtn->setStyleSheet(image);
    if(text == tr("下一步"))
        connect(nextBtn, &QPushButton::clicked, this, &Dialog::next_clicked);
    else if(text == tr("上一步"))
        connect(nextBtn, &QPushButton::clicked, this, &Dialog::last_clicked);
    else if(text == tr("bfs显示"))
        connect(nextBtn, &QPushButton::clicked, this, &Dialog::bfsOutput_clicked);
    else if(text == tr("dfs显示"))
        connect(nextBtn, &QPushButton::clicked, this, &Dialog::dfsOutput_clicked);
    else if(text == tr("显示距离"))
        connect(nextBtn, &QPushButton::clicked, this, &Dialog::floydOutput_clicked);
}
```

Now looking back, I realized  `switch` statement may enhanse the readability and efficiency.

#### the third pit (ouput)

With the output component, if course, accurate output and standardized display should also be required.
I take `streams` and `string` to manipulate at the same time for accurate output, such as:

```c++
void adjacencyWGraph::outputWithAdjacency(string &s)const
{
    stringstream ss;
    string temp;
    s += " ";
    for (int i = 0; i < n; i++) {
        for(int k = 0; k < maxLength+2-1; k++){
            s += " ";
        }

        ss.clear();
        ss << vertex[i];
        ss >> temp;
        s += temp;
    }
    s += "\r";
    for (int i = 1; i <= n; i++) {
        ss.clear();
        ss << vertex[i - 1];
        ss >> temp;
        s += temp;
        for(int k = 0; k < maxLength+2-1; k++){
            s += " ";
        }
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != INT_MAX) {
                ss.clear();
                ss << a[i][j];
                ss >> temp;
                s += temp;
                for(int k = 0; k < maxLength+2-(int)temp.length(); k++){
                    s += " ";
                }
            }
            else {
                s += "∞";
                for(int k = 0; k < maxLength; k++){
                    s += " ";
                }
            }
        }
        s += "\r";
    }
    //cout<<s<<endl;
}
```

Therein `maxLength` is as far as possible to achieve the standarization of output and by getting the maximum string length of the input ( or weights of the length of the sting).
The function is as follows:

```c++
void adjacencyWGraph::getMaxLength()
{
    stringstream ss;
    this->maxLength = 2;
    string temp;
    int length;
    for(int i=0;i<n;i++){
        temp = vertex[i];
        length = temp.length();
        if(length>maxLength){
            maxLength = length;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
             if (a[i][j] != INT_MAX) {
                 ss.clear();
                 ss << a[i][j];
                 ss >> temp;
                 length = temp.length();
                 if(length>maxLength){
                     maxLength = length;
                 }
            }
        }
    }
}
```

#### the fourth pit (exception)

We've taken into account the need to throw an exception, which in this case prompts the user for an error when input is illegal and tells him to retype it in the correct format.
Dut to the time factor, I did not complate this function, but gave a format specification interface and the default text to prompt the user to input correctly.

#### the fifth pit (QTextBrowser)

This is sinkhole, I over and over use baidu, google is still unsolved.
When the input graph has too many vertices (probably more than 15), the output in matrix form cannot be seen on the interface, the excessive vertex character will be listed in the second line. (at that time, even the slider was made, but there is not a button to slide ==). But it's nice to know that copying and pasting into a text document does not break a line, and the format is correct.

#### the sixth pit (layout)

Only the main menu interface is grid layout.

#### the seventh pit (draw)

Originaly, I want to use the 2D drawing function of QT to output the result, but finally, of course, nothing was done.

### effect picture

#### main menu interface

![main menum interface](http://blog-1253928653.file.myqcloud.com/Image/GraphOperator/main.png)<br>

#### manual menu interface

![manual menu interface](http://blog-1253928653.file.myqcloud.com/Image/GraphOperator/handIn.png)<br>

#### the full effect 

![the full effect ](http://blog-1253928653.file.myqcloud.com/Image/GraphOperator/output2.png)<br>

#### code link

* [GraphOperator](https://github.com/anlance/anlance/tree/master/GraphOperator)