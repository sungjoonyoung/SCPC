#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;
long long exr[200'000];
long long exb[200'000];
void solve(void){
    int N,R;
    cin>>N>>R;
    vector<int> redh,reds,blueh,blues;
    for(int i=0;i<N-R;i++){
        int in;cin>>in;
        blueh.push_back(in);//blue
    }
    for(int i=0;i<R;i++){
        int in;cin>>in;
        redh.push_back(in);
    }
    for(int i=0;i<N-R-1;i++){
        int in;cin>>in;
        blues.push_back(in);
    }
    for(int i=0;i<R+1;i++){
        int in;cin>>in;
        reds.push_back(in);
    }
    sort(blueh.begin(),blueh.end());
    sort(redh.begin(),redh.end());
    sort(blues.begin(),blues.end());
    sort(reds.begin(),reds.end());

    //블루 하우스가 블루 샵보다 많아.
    long long tmp=0;
    for(int i=0;i<blues.size();i++)tmp+=abs(blueh[i]-blues[i]);
    exb[blueh.size()-1]=tmp;
    for(int i=blues.size()-1;i>=0;i--){ //i의 블루 하우스를 버리는 겨
        tmp-=abs(blueh[i]-blues[i]);
        tmp+=abs(blueh[i+1]-blues[i]);
        exb[i]=tmp;
    }
    //래드 하우스가 래드 샵보다 적어
    tmp=0;
    for(int i=0;i<redh.size();i++)tmp+=abs(redh[i]-reds[i]);
    exr[reds.size()-1]=tmp;
    for(int i=redh.size()-1;i>=0;i--){ //i의 레드샵를 버리는 겨
        tmp-=abs(redh[i]-reds[i]);
        tmp+=abs(redh[i]-reds[i+1]);
        exr[i]=tmp;
    }

    
    long long answer=2'000'000'000'000'000'000;
    for(int i=0;i<blueh.size();i++){
        int bh=blueh[i];
        
        int ind=lower_bound(reds.begin(),reds.end(),bh)-reds.begin();
        for(int n=-1;n<2;n++){
            int nx=ind+n;
            if(nx<0 or nx>=reds.size())continue;
            answer=min(answer,(long long)abs(bh-reds[nx])+exr[nx]+exb[i]);
        }
    }
    cout<<answer<<"\n";

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