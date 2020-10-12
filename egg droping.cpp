#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int eggDrop(int n, int k)
{
    int tab[n+1][k+1];
    memset(tab,0,sizeof(tab));
    for(int i=1;i<=n;i++)
    {
        tab[i][1]=1;
         tab[i][0]=0;
    }
    
    for(int i=1;i<=k;i++)
    {   
        tab[1][i]=i;
    }
    for(int i=2;i<=n;i++)
    {
       for(int j=2;j<=k;j++)
        {
            tab[i][j]=INT_MAX;
            for(int x=1;x<=j;x++)
            {
                tab[i][j]=min(tab[i][j],1+max(tab[i-1][x-1],tab[i][j-x]));
            
            }
        }
    }
    
    return tab[n][k];
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    cout<<eggDrop(n,k)<<endl;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int tab[105][10005];

int eggBreak(int e,int f)
{
    if(e==1||f==0||f==1)
        return tab[e][f]=f;
    if(tab[e][f]!=-1)
        return tab[e][f];
    int low=1,high=f;
     int res=INT_MAX;
    while(low<=high)
    {
        int mid=(low+high)/2;
       
        int below=((tab[e-1][mid-1]!=-1)?tab[e-1][mid-1]:eggBreak(e-1,mid-1));
        int above=((tab[e][f-mid]!=-1)?tab[e][f-mid]:eggBreak(e,f-mid));
        res=min(res,1+max(below, above));
        if(below<above)
            low=mid+1;
        else
            high=mid-1;
    }
    return tab[e][f]=res;
    
}
int Solution::solve(int A, int B) {
    
    memset(tab,-1,sizeof(tab));
    eggBreak(A,B);
    return tab[A][B];
        
}
