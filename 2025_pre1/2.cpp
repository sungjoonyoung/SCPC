#include<iostream>
using namespace std;
void solve(void){
    long long N,L;
    cin>>N>>L;
    long long answer=0;
    long long tmp=0;
    long long maxnum=-1;
    while(N--){
        long long in;
        cin>>in;
        answer+=min(in,L-in)*2;
        tmp+=in*2;
        maxnum=max(maxnum,min(in,L-in)*2);
    }
    cout<<min(tmp,answer-maxnum+L)<<"\n";
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