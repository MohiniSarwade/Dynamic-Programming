#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int rod(int a[], int n)
{
    int tab[n+1];
    memset(tab,0,sizeof(tab));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            tab[i]=max(tab[i],a[j]+tab[i-j-1]);
        }
    }
    return tab[n];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cout<<rod(a,n)<<endl;
	}
	return 0;
}
