#include<bits/stdc++.h>
using namespace std;
void maxSumNonConti(int arr[], int n)
{
    int tab[n+1];
    tab[0]=arr[0];
    tab[1]=(arr[0]>arr[1]?arr[0]:arr[1]);
    for(int i=2;i<n;i++)
    {
        tab[i]=max(arr[i]+tab[i-2],tab[i-1]);
    }
    cout<<"Maximum sum of non contigious elements is "<<tab[n-1];
}
void Max(int arr[], int n)
{
    int tab[n+1];
    tab[n-1]=arr[n-1];
    tab[n-2]=(arr[n-1]>arr[n-2]?arr[n-1]:arr[n-2]);
    for(int i=n-3;i>=0;i--)
    {
        tab[i]=max(arr[i]+tab[i+2],tab[i+1]);
    }
    cout<<endl<<"Maximum sum of non contigious elements is "<<tab[0];
}
int main()
{
    int arr[]={5,  5, 10, 40, 50, 35};
    int n=(sizeof(arr)/sizeof(arr[0]));
    maxSumNonConti(arr,n);
    Max(arr,n);
    return 0;
}
