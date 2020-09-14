#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>p, int arr[],int n)
{
   vector<int>max=p[0];
   for(vector<int>v:p)
    {
        if(v.size()>max.size())
            max=v;
    }
    
    for(auto x:max)
        cout<<x<<" ";
    cout<<endl;
}
int lis(int arr[], int n)
{
    vector<int>tab(n,1);
    vector<vector<int>>p(n);
    
    p[0].push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && tab[j]+1>tab[i])
            {
                tab[i]=tab[j]+1;
                if(p[i].size()<p[j].size()+1)
                    p[i]=p[j];
            }
           
        }
        p[i].push_back(arr[i]);
    }
  
    print(p,arr,n);
    return *max_element(tab.begin(),tab.end());
}
int lisR(int arr[], int n)
{
    vector<int>tab(n,1);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(arr[i]<arr[j] && tab[j]+1>tab[i])
                tab[i]=tab[j]+1;
        }
    }
    return *max_element(tab.begin(),tab.end());
}

int main() 
{ 
    int arr[] = {50, 3, 10, 7, 40, 80}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int p=lis( arr, n );
    cout<<"Length of lis is "<<p<<endl; 
    cout<<"Length of lis is "<<lisR( arr, n )<<endl; 
    return 0; 
} 
