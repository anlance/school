#include<iostream>
#include<cstring>
using namespace std;

int room[205];

int doit(int start,int end){
    int m = 0;
    for (int i = start; i < end+1;i++){
        if(m<room[i]){
            m = room[i];
        }
    }
    return m;
}

int main(){
    int T, N;
    int a, b;
    cin >> T;
    for (int i = 0; i < T;i++){
        cin >> N;
        int min = 201, max = 1;
        memset(room, 0, sizeof(room));
        for (int k = 0; k < N;k++){
            cin >> a >> b;
                if(a>b){
                    swap(a, b);
                }
                if(a%2==0){
                    a = a / 2;
                }
                else{
                    a = (a + 1) / 2;
                }
                if(b%2==0){
                    b = b / 2;
                }
                else{
                    b = (b + 1) / 2;
                }
                for (int j = a; j < b + 1;j++){
                    room[j]++;
                }
                if (a < min)
                {
                    min = a;
                }
                if(b>max){
                    max = b;
                }
        }
        int result = doit(min, max)*10;
        cout << result << endl;
    }
    return 0;
}