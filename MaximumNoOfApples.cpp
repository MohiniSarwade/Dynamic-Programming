#include<bits/stdc++.h>
using namespace std;


void maxApples(vector<vector<int>>arr, int n)
{
    vector<vector<int>>tab(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            tab[i][j]=max(tab[i-1][j],tab[i][j-1])+arr[i-1][j-1];
        }
    }
    cout<<tab[n][n]<<endl;
}
int main()
{
 
   vector<vector<int>>v= { { 1, 2 }, { 3, 5 } };
    maxApples(v,v.size());
    return 0;
}
