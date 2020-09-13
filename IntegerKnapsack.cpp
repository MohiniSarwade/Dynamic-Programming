#include<bits/stdc++.h>
using namespace std;

void intergerKnapsack(int W, int wt[],int val[], int n)
{
    vector<int>dp(W+1); 
    
    
    for (int i=1; i<=W; i++) 
    {
        int cMax=INT_MIN;
        for (int j=0; j<n; j++) 
        {
            if (wt[j] <= i)
            {
                if(cMax<dp[i-wt[j]]+val[j])
                    cMax=dp[i-wt[j]]+val[j];
            }
        }
                 
        dp[i] = max(dp[i-1],cMax);
    }
    cout<<"Maximum weight in bag: "<<dp[W];
}

void intergerKnap(int W, int wt[],int val[], int n)
{
    vector<int>dp(W+1); 
    
    
    for (int i=1; i<=W; i++) 
    {
        for (int j=0; j<n; j++) 
        {
            if(wt[j]<=i)
                dp[i] = max(dp[i],dp[i-wt[j]]+val[j]);
        }
    }
    cout<<endl<<"Maximum weight in bag: "<<dp[W];
}
int main()
{
    int C = 100; 
    int val[] = {10, 30, 20}; 
    int wt[] = {5, 10, 15}; 
    int n=sizeof(val)/sizeof(val[0]);
    intergerKnapsack(C,wt,val,n);
    intergerKnap(C,wt,val,n);
    return 0;
    
}
        
