    #include<iostream>
    #include<algorithm>
    using namespace std;

    int main(){
        int N, sum;
        int a[11], b[11];
        while(cin>>N>>sum){
            for (int i = 0; i < N;i++){
                a[i] = i + 1;
            }
            do{
                for (int i = 0; i < N;i++){
                    b[i] = a[i];
                }
                for (int i = N; i > 1;i--){
                    for (int j = 0; j < i - 1;j++){
                        b[j] = b[j] + b[j + 1];
                    }
                }
                if(b[0]==sum)
                    break;
            }
            while(next_permutation(a, a + N));
            for (int i = 0; i < N;i++){
            cout << a[i] << " ";
        }
        cout << endl;
        }
        return 0;
    }