#include<bits/stdc++.h>
using namespace std;

bool IsSubsetHalfSum(int arr[], int n)
{
    int k=0;
    for(int i=0;i<n;i++)
        k+=arr[i];
    sort(arr,arr+n);
    int R=0;
    vector<int>tab(k+1,0);
    tab[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=R;j>=0;j--)
        {
            if(tab[j])
                tab[j+arr[i]]=1;
            R=min(k/2,R+arr[i]);
        }
    }
    return tab[k/2];
}

int main()
{
    int arr[]={3,4,1,2,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    if(IsSubsetHalfSum(arr,n))
        cout<<"Subset with half sum exist"<<endl;
    else
        cout<<"Subset with half sum does not exist"<<endl;
    return 0;
}
