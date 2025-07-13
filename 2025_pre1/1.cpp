#include<iostream>
using namespace std;
int arr[100'000];
void solve(void){
    int N;
    cin>>N;
    int a,b;
    a=b=0;
    for(int i=0;i<N;i++)cin>>arr[i];
    int count=0;
    for(int i=0;i<N;i++){
        int in=arr[i];
        if(in==500){
            a++;
            count++;
        }
        else if(in==1000 && a){
            a--;
            b++;
            count++;
        }
        else if(in==5000 && a && (a*500+b*1000>=4500)){
            count++;
            if(b>=4){
                b-=4;
                a--;
            }
            else{
                in-=1000*b;
                in-=500;
                b=0;
                a-=in/500;
            }

        }
        else break;
    }
    cout<<count<<"\n";
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        cout<<"Case #"<<i<<"\n";
        solve();
    }
}