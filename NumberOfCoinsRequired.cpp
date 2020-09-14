#include<bits/stdc++.h>
using namespace std;

vector<int>dp(1024);
   
int countMem(int arr[], int m, int n)
{
 
    if(n==0)
        return 0;
    if(dp[n]!=0)
        return dp[n];

    int ans=INT_MAX;
    for(int i=0;i<m;i++)
    {
        if(arr[i]<=n)
        {
            ans=min(ans,countMem(arr,m,n-arr[i]));
        }
    }
    dp[n]=ans+1;
    return dp[n];
    
}
int countTab(int arr[], int m, int n)
{
    vector<int>tab(n+1);
    tab[0]=0;
    for(int i=1;i<=n;i++)
    {
        int ans=INT_MAX;
        for(int j=0;j<m;j++)
        {
            if(arr[j]<=i)
             {
               ans=min(ans,tab[i-arr[j]]);
             }
        }
        tab[i]=ans+1;
    }
    
    return tab[n];   
}
int main() 
{ 
    int arr[] = {1,2,5,10,20}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    cout<<"Minimum coins required to make change "<<countMem(arr, m, 101)<<endl;
    cout<<"Minimum coins required to make change "<<countTab(arr, m, 101)<<endl;
    return 0; 
} 
