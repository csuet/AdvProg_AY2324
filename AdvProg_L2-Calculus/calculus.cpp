#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main(){
    int n,m,k;
    int tong=0;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cin>>a[i][j];
    }
    cin>>k;
    for(int x=0;x<k;x++){
        tong=0;
        for(int j=0;j<m;j++)
        tong+=a[x][j];
        cout<<fixed<<setprecision(2)<<tong<<" ";
    }
    return 0;
}
