#include<bits/stdc++.h>
using namespace std;
bool isSubsetSum(int set[],int n, int sum)
{
    int tab[n+1][sum+1];
    for(int i=0;i<=n;i++)
        tab[i][0]=true;
    for(int i=1;i<=sum;i++)
        tab[0][i]=false;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(set[i-1]<=j)
                tab[i][j]=tab[i-1][j]||tab[i-1][j-set[i-1]];
            else
                tab[i][j]=tab[i-1][j];
        }
    }
    
    for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          cout<<tab[i][j]<<" "; 
       cout<<endl;
     }
    return tab[n][sum];
}
int main() 
{ 
    int set[] = { 3, 34, 4, 12, 5, 2 }; 
    int sum = 13; 
    int n = sizeof(set) / sizeof(set[0]); 
    if (isSubsetSum(set, n, sum) == true) 
       cout<<"Found a subset with given sum"; 
    else
        cout<<"No subset with given sum"; 
    return 0; 
} 
