#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a) for (int i=0;i < a; i+=1)
int n,m,k;
int arr[500][500]={0};
int rm(int i,int j){
    if(i>=m||j>=n||j<0||i<0||arr[i][j]!=1)return 0;
    else{arr[i][j]=0;return 1+rm(i-1,j)+rm(i+1,j)+rm(i,j-1)+rm(i,j+1);}
}
int main(){
    int t=1;
    cin >> t;
    FOR(w,t) {
        cin>>n>>m>>k;
        FOR(i,n){
            FOR(j,m){
                cin>>arr[i][j];
            }
        }
        long long ans=0;
        FOR(i,n){
            FOR(j,m){
                int sz=rm(i,j);
                if(sz>=k&&sz>0){
                    ans+=1;
                }
            }
        }
        cout<<ans<<endl;
    }
}
