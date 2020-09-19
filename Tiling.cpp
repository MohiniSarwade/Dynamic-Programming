#include<bits/stdc++.h>
using namespace std;
void waysToTile(int n)
{
    int f[n+1];
    f[0]=0,f[1]=1,f[2]=2;
    for(int i=2;i<n;i++)
    {
        f[i+1]=f[i]+f[i-1];
    }
    cout<<f[n]<<endl;
    for(int i=0;i<=n;i++)
        cout<<f[i]<<" ";
}
int main()
{
    int x=11;
    waysToTile(x);
    return 0;
}
