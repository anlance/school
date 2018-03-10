# include<iostream>
using namespace std;

int l, r, a;

int main(){
    while(cin>>l>>r>>a){
        int res = 0;
        int tempa = 0;
        int tempb = 0;
        if(l>=r){
            tempa = l - r;
            if(tempa>=a){
                res = 2 * (r + a);
            }
            else{
                tempb = a - tempa;
                res = 2 * r + tempb / 2 * 2 + 2 * tempa;
            }
        }
        else{
            tempa = r - l;
            if(tempa>=a){
                res = 2 * (l + a);
            }
            else{
                tempb = a - tempa;
                res = 2 * l + tempb / 2 * 2 + 2 * tempa;
            }
        }
        cout << res << endl;
    }
}