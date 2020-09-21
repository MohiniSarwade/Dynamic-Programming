#include<bits/stdc++.h>
using namespace std;
void jump(int arr[], int n)
{
    vector<int>res(n,INT_MAX);
    if(n==0||arr[0]==0)
        return;
    res[0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>=(i-j))
            {
                if(res[j]+1<res[i])
                    res[i]=res[j]+1;
            }
        }
    }
    cout<<res[n-1];
    
}
int main()
{
    int arr[]={2,3,1,1,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    jump(arr,n);
    return 0;
}
