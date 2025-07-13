#include<iostream>
using namespace std;
long long fact[100'005];
void solve(void){
    string str;
    cin>>str;
    long long answer=0;
    for(int i=0;i<str.size();i++){
        long long tmp= (int)str[i]-'0';
        if(tmp>2){
            answer+=3*fact[str.size()-i-1];

            answer%=1'000'000'007;
            break;
        }
        
        answer+=(tmp)*fact[str.size()-i-1]%1'000'000'007;
        answer%=1'000'000'007;
        if(i+1==str.size()){
            answer++;
            answer%=1'000'000'007;
        }

    }
    answer=1'000'000'007+answer;
    
    answer%=1'000'000'007;
    cout<<answer<<"\n";
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fact[0]=1;
    for(int i=1;i<100'005;i++)fact[i]=(fact[i-1]*3)%1'000'000'007;
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        cout<<"Case #"<<i<<"\n";
        solve();
    }
}