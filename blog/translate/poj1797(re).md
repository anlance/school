


Although this code was RuntimeError, I steped through one pit after another during the whole afternoon of debug(), so record it.

## title

### general idea

There are n cities, m roads, and there's one bearing capacity on each road. Now the maximum bearing capacity is required from city 1 to city n.

### train of thought

* Establish an adjacency table at the starting point and use a queue to store all points with a starting point of 1;
* Take one point (point 1) from the queue and put the point (point 2) starting at the end of the pick point (point 1) into the queue. Then keep looking until the final point is reached (save the minium capacity of each time) or there is no next point.
* extract the maximum in all minimum capacity you saved.

## code

### definition

``` c++
struct Node{
    int to;
    int cost;
};
struct helpNode{
    int from, to;
    int cost;
};
bool cmp(helpNode a, helpNode b){
    return a.from < b.from;
}
vector<vector<Node> > start;
vector<Node> save;
vector<Node> kong;
int T, N, M;
```

### function to find the maximum capacity

``` c++
int doit(){
    queue<Node> Q;
    for (int i = 0; i < start[1].size();i++){
        Q.push(start[1][i]);
    }
    Node temp, next;
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        if(temp.to==N){
            save.push_back(temp);
        }
        int x = temp.to;
        for (int i = 0; i < start[x].size();i++){
            next = start[x][i];
            if(temp.cost<next.cost){
                next.cost = temp.cost;
            }
            Q.push(next);
        }
    }
    int max = 0;
    for (int i = 0; i < save.size();i++){
        if(max<save[i].cost){
            max = save[i].cost;
        }
    }
    return max;
}
```

### Main function (process the input)

``` c++
int main(){
    cin >> T;
    for (int i = 1; i < T + 1;i++){
        cin >> N >> M;
        save.clear();
        start.clear();
        kong.clear();
        helpNode temp;
        Node tt;
        vector<helpNode> help;
        int len = start.size();
        for (int j = 0; j < M;j++){
            cin >> temp.from >> temp.to >> temp.cost;
            if(temp.from>temp.to){
                swap(temp.from, temp.to);
            }
            //start[x].push_back(temp);
            help.push_back(temp);   //store all the input points
        }
        sort(help.begin(), help.end(), cmp);    //sort from the smalles to the biggest
        temp = help[help.size() - 1];
        help.push_back(temp);   //add the last element to make the last two must be the same
        int number = 0;
        for (int k = 0; k < help.size()-1;k++){
                number = help[k].from;
                tt.to = help[k].to;
                tt.cost = help[k].cost;
                if(help[k+1].from==help[k].from){
                    save.push_back(tt);     //put the points from the same starting point in an array
                }
                else{
                    int n = number - start.size();
                    while(n!=0){
                        start.push_back(kong);
                        n--;
                    }
                    save.push_back(tt);     //if different,save in help[k];
                    start.push_back(save);
                    save.clear();
                }
        }
        start.push_back(save);  //save the last group points that starting points were same
        save.clear();
        int result = doit();
        cout << "Scenario #" << i << ":" << endl;
        cout << result << endl;
    }
    cout << endl;
    return 0;
}
```

## summary

### vector 

More proficient use of vector, especially two-dimensional dynamic vector. Both dimensions are dynamically growing and meet the requirements of the graph, that is, some one-dimensional array elements need to be empty.

### initalize

* This is a pretty important process. Every time you need to use a queue, an array, or an adjacency matrix and you need to think about whether you need to initialize, and how.
* In particular, note if the current value is stored after each loop.