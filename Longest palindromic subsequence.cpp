#include<bits/stdc++.h>
using namespace std;
int longestPalindromicSubsequence(string arr,int n)
{
	int tab[n][n]={{0}};
	for(int i=0;i<n;i++)
		tab[i][i]=1;
	for(int gap=1;gap<n;gap++)
	{
		for(int i=0,j=gap;j<n;i++,j++)
		{
			if(arr[i]==arr[j] && gap==1)
					tab[i][j]=2;
				else if(arr[i]==arr[j])
					tab[i][j]=2+tab[i+1][j-1];
				else
					tab[i][j]=max(tab[i+1][j],tab[i][j-1]);

		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<tab[i][j]<<" ";
		cout<<endl;
	}
	return tab[0][n-1];
}

void print(string x, int m, string y, int n,int tab[][1024])
{
	int index=tab[0][0];
	string res="";
    int i=0,j=0;
    while(i<m && j<n && res.size()!=index)
    {
        if(x[i]==y[j])
        {
        	res+=x[i];
            i++;j++;
        }
        else if(tab[i][j]==tab[i][j+1])
        {
            j++;
        }
        else if(tab[i][j]==tab[i+1][j])
            i++;
      
    }
    cout<<res<<endl;
}
int tab[1024][1024];
int LCS(string x,int m,string y, int n)
{
   
    for(int i=0;i<=m;i++)
        tab[i][n]=0;
    for(int i=0;i<=n;i++)
        tab[m][i]=0;
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            tab[i][j]=tab[i+1][j+1];
            if(x[i]==y[j])
                tab[i][j]++;
            if(tab[i][j]<tab[i][j+1])
                tab[i][j]=tab[i][j+1];
            if(tab[i][j]<tab[i+1][j])
                tab[i][j]=tab[i+1][j];
        }
    }
    
    return tab[0][0];
}

int main()
{
	string s="GEEKSFORGEEKS";
	int n=s.length();
	string r=s;
	reverse(r.begin(),r.end());
	//cout<<"length of Lingest palindromic Subsequnece is "<<longestPalindromicSubsequence(s,n)<<endl;
	int z=LCS(s,s.length(),r,r.length());
	print(s,s.length(),s,s.length(),tab);
	cout<<endl<<"length of Lingest palindromic Subsequnece is "<<z;
	return 0;
}
