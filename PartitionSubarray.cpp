#include<bits/stdc++.h>
using namespace std;

bool findPartiion(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    if(sum%2!=0)
        return false;
    bool tab[n+1][sum/2 +1];
    for(int i=0;i<=n;i++)
        tab[i][0]=true;
    for(int i=1;i<=sum/2;i++)
        tab[0][i]=false;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum/2;j++)
        {
            if(arr[i]<=j)
                tab[i][j]=tab[i-1][j]||tab[i-1][j-arr[i]];
            else
                tab[i][j]=tab[i-1][j];
        }
    }
    return tab[n][sum/2];
}

int main()  
{  
    int arr[] = {3, 1, 1, 2, 2, 1};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    if (findPartiion(arr, n) == true)  
        cout << "Can be divided into two subsets of equal sum";  
    else
        cout << "Can not be divided into" 
             << " two subsets of equal sum";  
    return 0;  
}  
