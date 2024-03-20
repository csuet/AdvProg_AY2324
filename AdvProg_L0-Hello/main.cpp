#include<bits/stdc++.h>
using namespace std;
int f(int a[],int n)
{
    if(n=0) return a[n];
    return a[n]+a[n-1];
}
int main()
{   
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    int n;cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        b[i]=f(a,i);
        cout<<b[i]<<" ";
    }

}
