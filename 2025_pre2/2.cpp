#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int N, evenN;
vector<int> arr1[400001];
vector<int> arr0[400001];
ll give_1(int i,int j,int k){
    ll answer=0;
    int ind1=(1<<evenN)+i;
    int ind2=(1<<evenN)+j;
    while(ind1<=ind2){
        // cout<<(upper_bound(arr[ind1].begin(),arr[ind1].end(),k)-arr[ind1].begin());
        // break;
        if(ind1%2==1)answer+=upper_bound(arr1[ind1].begin(),arr1[ind1].end(),k)-arr1[ind1].begin();
        if(ind2%2==0)answer+=upper_bound(arr1[ind2].begin(),arr1[ind2].end(),k)-arr1[ind2].begin();
        ind1=(ind1+1)/2;
        ind2=(ind2-1)/2;
    }
    return answer;
}
ll give_0(int i,int j,int k){
    ll answer=0;
    int ind1=(1<<evenN)+i;
    int ind2=(1<<evenN)+j;
    while(ind1<=ind2){
        // cout<<(upper_bound(arr[ind1].begin(),arr[ind1].end(),k)-arr[ind1].begin());
        // break;
        if(ind1%2==1)answer+=upper_bound(arr0[ind1].begin(),arr0[ind1].end(),k)-arr0[ind1].begin();
        if(ind2%2==0)answer+=upper_bound(arr0[ind2].begin(),arr0[ind2].end(),k)-arr0[ind2].begin();
        ind1=(ind1+1)/2;
        ind2=(ind2-1)/2;
    }
    return answer;
}
void solve(void){
    for(int i=0;i<400001;i++){
        arr1[i].clear();
        arr0[i].clear();
    }

    int M;
    cin>>N>>M;
    if(N==1)evenN=0;
    else evenN=log2(N-1)+1;
    //init
    for(int i=0;i<N;i++){
        int s,e;
        cin>>s>>e;
        s--;e--;
        arr1[(1<<evenN)+i].push_back(s);
        arr0[(1<<evenN)+i].push_back(e+1);
    }
    for(int h=(1<<evenN)/2;h>0;h/=2){
        for(int i=h;i<h*2;i++){
            int ind0,ind1,ind2;
            ind0=ind1=ind2=0;
            arr1[i].resize(arr1[i*2].size()+arr1[i*2+1].size());
            while(ind1<arr1[i*2].size() and ind2<arr1[i*2+1].size()){
                if(arr1[i*2][ind1]<arr1[i*2+1][ind2]){
                    arr1[i][ind0++]=arr1[i*2][ind1++];
                }
                else{
                    arr1[i][ind0++]=arr1[i*2+1][ind2++];
                }
            }
            for(;ind1<arr1[i*2].size();ind1++){
                arr1[i][ind0++]=arr1[i*2][ind1];
            }
            for(;ind2<arr1[i*2+1].size();ind2++){
                arr1[i][ind0++]=arr1[i*2+1][ind2];
            }
        }
    }
    for(int h=(1<<evenN)/2;h>0;h/=2){   
        for(int i=h;i<h*2;i++){
            int ind0,ind1,ind2;
            ind0=ind1=ind2=0;
            arr0[i].resize(arr0[i*2].size()+arr0[i*2+1].size());
            while(ind1<arr0[i*2].size() and ind2<arr0[i*2+1].size()){
                if(arr0[i*2][ind1]<arr0[i*2+1][ind2]){
                    arr0[i][ind0++]=arr0[i*2][ind1++];
                }
                else{
                    arr0[i][ind0++]=arr0[i*2+1][ind2++];
                }
            }
            for(;ind1<arr0[i*2].size();ind1++){
                arr0[i][ind0++]=arr0[i*2][ind1];
            }
            for(;ind2<arr0[i*2+1].size();ind2++){
                arr0[i][ind0++]=arr0[i*2+1][ind2];
            }
        }
    }
    //


    vector<pair<int,pair<int,int>>> v;
    for(int i=0;i<M;i++){
        int C,s,e;
        cin>>C>>s>>e;
        C--;s--;e--;
        v.push_back({C,{s,e}});
    }
    sort(v.begin(),v.end());
    int C,s,e;
    C=-1;
    s=-1;
    e=2'000'000'000;
    ll cnt1,cnt2;
    cnt1=cnt2=0;
    for(int i=0;i<M;i++){
        int tmpC=v[i].first;
        int tmps=v[i].second.first;
        int tmpe=v[i].second.second;
        if(tmpC!=C){//새로운 줄
            //전에 겹친 거 업데이트
            if(C!=-1){
                cnt1+=give_1(s,e,C)-give_0(s,e,C);
                if(give_1(s,e,C)-give_0(s,e,C))cnt2++;
            }
            //
            s=tmps;
            e=tmpe;
            C=tmpC;
        }

        if(e+1<tmps){//새로운 공백
            //만약 공백이 비었으면?
            if(give_1(e+1,tmps-1,C)-give_0(e+1,tmps-1,C)==0){
                e=max(e,tmpe);
                continue;//이어주기
            }

            //전에 겹친 거 업데이트
            cnt1+=give_1(s,e,C)-give_0(s,e,C);
            if(give_1(s,e,C)-give_0(s,e,C))cnt2++;
            //좌표
            s=tmps;
            e=tmpe;
        }
        else{//겹침
            e=max(e,tmpe);
        }
    }
    cnt1+=give_1(s,e,C)-give_0(s,e,C);
    if(give_1(s,e,C)-give_0(s,e,C))cnt2++;
    cout<<cnt1<<" "<<cnt2<<"\n";
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