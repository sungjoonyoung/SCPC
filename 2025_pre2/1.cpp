#include<iostream>
#include<vector>
#define ll long long
#define INF 1LL*200000*200001
using namespace std;
ll arr[200'000];
ll dp[3][200'010];
void solve(void){
    for(int i=0;i<200'010;i++){
        dp[0][i]=dp[1][i]=dp[2][i]=0;
    }
    int N;
    cin>>N;
    for(int i=0;i<N;i++)cin>>arr[i];
    vector<ll> zero;
    vector<ll> nume;
    for(int i=0;i<N;i++){
        if(arr[i]==0)zero.push_back(i);
        if(arr[i]>1){
            for(int k=0;k<arr[i]-1;k++)nume.push_back(i);
        }
    }
    if(zero.size()==0){cout<<"0\n";return;}
    dp[0][0]=dp[1][0]=dp[2][0]=0;
    dp[0][0]=abs(zero[0]-nume[0]);

    for(int i=1;i<nume.size();i++){
        dp[0][i]=dp[1][i]=dp[2][i]=INF;

        if(i<zero.size())dp[0][i]=dp[0][i-1]+abs(zero[i]-nume[i]);

        for(int s=1;s<3;s++){
            dp[s][i]=dp[s-1][i-1];
            if(0<=i-s and i-s<zero.size())dp[s][i]=min(dp[s][i-1]+abs(zero[i-s]-nume[i]),dp[s][i]);
        }
    }
    cout<<dp[nume.size()-zero.size()][nume.size()-1]<<"\n";
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



#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define inf 3000000000000000

ll a[200005],dp[200005][5];

ll _abs(ll v)
{
    if(v < 0)return -v;
    else return v;
}

int main()
{
    ll t,tc = 1;
    scanf("%lld",&t);
    while(t--)
    {
        ll i,n,s = 0;
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        printf("Case #%lld\n",tc);
        for(i=1;i<=n;i++)
        {
            s += a[i] - 1;
            dp[i][0] = dp[i-1][0] + _abs(s);
        }
        s = 0;
        dp[0][1] = inf;
        dp[0][2] = inf;
        for(i=1;i<=n;i++)
        {
            s += a[i] - 1;
            dp[i][1] = min(dp[i-1][1],dp[i-1][0]) + _abs(s-1);
        }
        s = 0;
        for(i=1;i<=n;i++)
        {
            s += a[i] - 1;
            dp[i][2] = min(dp[i-1][2],dp[i-1][1]) + _abs(s-2);
        }
        s = 0;
        for(i=1;i<=n;i++)
        {
            s += a[i];
        }
        if(s <= n)dp[n][1] = inf;
        if(s <= n+1)dp[n][2] = inf;
        printf("%lld\n",min(dp[n][0],min(dp[n][1],dp[n][2])));
        for(i=1;i<=n;i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 0;
            dp[i][2] = 0;
        }
        tc++;
    }
}


// for(int i=1;i<=n;i++){
//         sum+=arr[i];
//         dp[i][0]=dp[i-1][0]+abs(sum-i);
//         dp[i][1]=min(dp[i-1][0],dp[i-1][1])+abs(sum-(i+1));
//         dp[i][2]=min({dp[i-1][1],dp[i-1][2]})+abs(sum-(i+2));
//     }
//     cout<<dp[n][sum-n]<<'\n';