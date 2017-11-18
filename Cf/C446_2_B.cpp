#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

//两个方法，上面更快

/*
long N;
struct People{
    int L;
    bool flag;
};
People a[1000001];
int main(){
    while(cin>>N){
        long mi = 1000001;
        int count = 0;
        for (int i = 0; i < N;i++){
            scanf("%d", &a[i].L);
            a[i].flag = true;
        }
        mi = N-1;
        int x = mi;
        for (int i = N - 1; i > 0;i--){
            int temp = a[i].L;
            if(mi<=i-temp){
                //cout << "s" << endl;
                //break;
            }
            else{
                if(mi>=i){
                    mi = i;
                    //cout << "xmi" << mi << ".." << endl;
                }
                int time = mi-(i-temp);
                for (int j = mi; j >=0&&time>=0;j--){
                    //cout <<i <<"--" << i - j << "--";
                    time--;
                    if(j!=mi){
                        a[j].flag = false;
                        //cout << j << "---";
                        if(x>=j){
                            x = j;
                        }
                    }
                }
            }
            mi = x;
            //cout << "mi" << mi << endl;
        }
        for (int i = 0; i < N;i++){
            if(a[i].flag==true){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
*/


long N;
struct People{
    int L;
    long long kill;
};
People a[1000001];
int main(){
    while(cin>>N){
        for (int i = 0; i < N;i++){
            scanf("%d",&a[i].L);
            a[i].kill = 0;
        }
        long long flag = N - 1;
        long long kills = 0;
        for (int i = N - 1; i >= 0;i--){
            long long  temp = i - a[i].L;
            if(temp<0){
                temp = 0;
            }
            if(flag>temp){
                if(flag>i){
                    a[i].kill = i - temp;
                    kills += a[i].kill;
                    flag = temp;
                }else{
                    a[i].kill = flag - temp;
                    kills += a[i].kill;
                    flag = temp;
                }
            }
        }
        cout << N - kills << endl;
    }

    //超时
    /*long mi = 1000001;
        int count = 0;
        for (int i = 0; i < N;i++){
            cin >> a[i].L;
            a[i].flag = true;
        }
        mi = N-1;
        int x = mi;
        for (int i = N - 1; i > 0;i--){
            int temp = a[i].L;
            if(mi<=i-temp){
                //cout << "s" << endl;
                //break;
            }
            else{
                if(mi>=i){
                    mi = i;
                    //cout << "xmi" << mi << ".." << endl;
                }
                int time = mi-(i-temp);
                for (int j = mi; j >=0&&time>=0;j--){
                    //cout <<i <<"--" << i - j << "--";
                    time--;
                    if(j!=mi){
                        a[j].flag = false;
                        //cout << j << "---";
                        if(x>=j){
                            x = j;
                        }
                    }
                }
            }
            mi = x;
            //cout << "mi" << mi << endl;
        }
        for (int i = 0; i < N;i++){
            if(a[i].flag==true){
                count++;
            }
        }
        cout<<count<<endl;
    }*/
    return 0;
}