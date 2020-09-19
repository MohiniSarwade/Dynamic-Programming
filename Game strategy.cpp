#include<bits/stdc++.h>
using namespace std;
void strategy(int arr[], int n)
{
    int tab[n][n];
    for(int i=0;i<n;i++)
    {
        tab[i][i]=arr[i];
        if(i<n-1)
            tab[i][i+1]=((arr[i]>arr[i+1])?arr[i]:arr[i+1]);
    }
    for(int gap=2;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            for(int g=0;g<gap;g++)
            {
                tab[i][j]=max((arr[i]+min(tab[i+1][j-1],tab[i+2][j])),(arr[j]+min(tab[i+1][j-1],tab[i][j-2])));
            }
        }
    }
    cout<<"Mzximum value user can get: "<<tab[0][n-1];
}
int main()
{
    int arr[]={20, 30, 2, 2, 2, 10};
    int n=sizeof(arr)/sizeof(arr[0]);
    strategy(arr,n);
    
    return 0;
}
