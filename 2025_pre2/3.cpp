#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
void solve(void){
    int N;
    cin>>N;
    vector<pair<int,int>> v;
    vector<int> bigv,smlv;
    v.resize(N);
    int bignum=-1;
    int smlnum=2'000'000'000;
    for(int i=0;i<N;i++){
        cin>>v[i].first>>v[i].second;
        bignum=max(bignum,v[i].second);
        smlnum=min(smlnum,v[i].second);
    }
    for(auto c:v){
        if(c.second==bignum)bigv.push_back(c.first);
        else smlv.push_back(c.first);
    }
    sort(bigv.begin(),bigv.end());
    sort(smlv.begin(),smlv.end());
    int maxnum=0;
    for(int i=0;i<bigv.size();i++)for(int j=0;j<smlv.size();j++){
        int bs=bigv[i]-bignum;
        int be=bigv[i]+bignum;

        int ss=smlv[j]-smlnum;
        int se=smlv[j]+smlnum;

        bs=max(bs,ss);
        be=min(be,se);
        if(be<bs)continue;
        if(!(bs<=bigv[i] and bigv[i]<=be))continue;
        if(!(bs<=smlv[j] and smlv[j]<=be))continue;
        int tmp=0;
        tmp+=upper_bound(bigv.begin(),bigv.end(),be)-bigv.begin();
        tmp-=lower_bound(bigv.begin(),bigv.end(),bs)-bigv.begin();

        tmp+=upper_bound(smlv.begin(),smlv.end(),be)-smlv.begin();
        tmp-=lower_bound(smlv.begin(),smlv.end(),bs)-smlv.begin();
        maxnum=max(maxnum,tmp);
    }
    cout<<maxnum<<"\n";
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    cin>>T;
    for(int i=1;i<=T;i++){
        cout<<"Case #"<<i<<"\n";
        solve();
    }
}


// #include<iostream>
// #include<cmath>
// #include<vector>
// #include<algorithm>
// #include<vector>
// #define ll long long
// using namespace std;
// void solve(void){
//     int N;
//     cin>>N;
//     vector<pair<int,int>> v;
//     vector<int> bigv,smlv;
//     v.resize(N);
//     int bignum=-1;
//     int smlnum=2'000'000'000;
//     for(int i=0;i<N;i++){
//         cin>>v[i].first>>v[i].second;
//         bignum=max(bignum,v[i].second);
//         smlnum=min(smlnum,v[i].second);
//     }
//     for(auto c:v){
//         if(c.second==bignum)bigv.push_back(c.first);
//         else smlv.push_back(c.first);
//     }
//     sort(bigv.begin(),bigv.end());
//     sort(smlv.begin(),smlv.end());
//     int maxnum=0;
//     //밑이 큰놈 그리고 위에가 커
//     for(auto l:bigv){
//         int tmp=0;
//         tmp+=upper_bound(bigv.begin(),bigv.end(),l+bignum)-bigv.begin();
//         tmp-=lower_bound(bigv.begin(),bigv.end(),l)-bigv.begin();
//         //특히 작은 게 지장 없을 때
//         if(smlnum*2>=bignum){
//             tmp+=upper_bound(smlv.begin(),smlv.end(),l+smlnum)-smlv.begin();
//             tmp-=lower_bound(smlv.begin(),smlv.end(),l+bignum-smlnum)-smlv.begin();
//         }
//         maxnum=max(maxnum,tmp);
//     }
//     //밑이 작은 놈 그리고 위가 작아
//     for(auto l:smlv){
//         int tmp=0;
//         tmp+=upper_bound(bigv.begin(),bigv.end(),l+smlnum)-bigv.begin();
//         tmp-=lower_bound(bigv.begin(),bigv.end(),l)-bigv.begin();
        
//         tmp+=upper_bound(smlv.begin(),smlv.end(),l+smlnum)-smlv.begin();
//         tmp-=lower_bound(smlv.begin(),smlv.end(),l)-smlv.begin();
//         maxnum=max(maxnum,tmp);
//     }

//     if(smlnum*2<bignum){
//         int ind0=0;
//         int ind1=0;
//         while(ind0<bigv.size() and ind1<smlv.size()){
//             int bign=bigv[ind0];
//             int smln=smlv[ind1];
//             if(bign<smln-smlnum){ind0++;continue;}
//             if(bign>smln){ind1++;continue;}
//             // if(smln-smlnum<=bign and bign=smln)
//             int tmp=0;
//             tmp+=upper_bound(smlv.begin(),smlv.end(),bign+smlnum)-smlv.begin();
//             tmp-=lower_bound(smlv.begin(),smlv.end(),smln)-smlv.begin();

//             tmp+=upper_bound(bigv.begin(),bigv.end(),smln+smlnum)-bigv.begin();
//             tmp-=lower_bound(bigv.begin(),bigv.end(),bign)-bigv.begin();
//             maxnum=max(maxnum,tmp);
//             ind0++;
//         }
//     }

    
//     // for(;ind0<bigv.size();ind0++){
//     //     int bign=bigv[ind0];
//     //     int smln=smlv[ind1];
//     //     if(bign<smln-smlnum){continue;}
//     //     int tmp=0;
//     //     tmp+=upper_bound(smlv.begin(),smlv.end(),smln+smlnum)-smlv.begin();
//     //     tmp-=lower_bound(smlv.begin(),smlv.end(),smln)-smlv.begin();

//     //     tmp+=upper_bound(bigv.begin(),bigv.end(),smln+smlnum)-bigv.begin();
//     //     tmp-=lower_bound(bigv.begin(),bigv.end(),bign)-bigv.begin();
        
//     //     maxnum=max(maxnum,tmp);
//     // }
//     // for(;ind1<smlv.size();ind1++){
//     //     int bign=bigv[ind0];
//     //     int smln=smlv[ind1];
//     //     if(bign>smln+smlnum){ind1++;continue;}
//     //     int tmp=0;
//     //     tmp+=upper_bound(smlv.begin(),smlv.end(),smln+smlnum)-smlv.begin();
//     //     tmp-=lower_bound(smlv.begin(),smlv.end(),smln)-smlv.begin();

//     //     tmp+=upper_bound(bigv.begin(),bigv.end(),smln+smlnum)-bigv.begin();
//     //     tmp-=lower_bound(bigv.begin(),bigv.end(),bign)-bigv.begin();
        
//     //     maxnum=max(maxnum,tmp);
//     // }
//     cout<<maxnum<<"\n";
// }
// int main(void){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int T=1;
//     cin>>T;
//     for(int i=1;i<=T;i++){
//         cout<<"Case #"<<i<<"\n";
//         solve();
//     }
// }