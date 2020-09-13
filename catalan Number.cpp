#include<bits/stdc++.h>
using namespace std;
int catalanNoMemoization(int n)
{
    vector<int> tab(n+1);
    if(n==0)
        return 1;
    if(tab[n]!=0)
        return tab[n];
    for(int i=1;i<=n;i++)
        tab[n]+=catalanNoMemoization(i-1)*catalanNoMemoization(n-i);
    
    return tab[n];
}
int catalanNoTabulation(int n)
{
    vector<int>tab(n+1);
    tab[0]=1;
    tab[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            tab[i]+=tab[j-1]*tab[i-j];
    }
    return tab[n];
}
int main()
{
    for (int i = 0; i < 11; i++) 
        cout<<catalanNoMemoization(i)<<" ";
    cout<<endl;
    for (int i = 0; i < 11; i++) 
        cout<<catalanNoTabulation(i)<<" ";
    return 0;
}
