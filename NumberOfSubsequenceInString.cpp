#include<bits/stdc++.h>
using namespace std;
void occurance(string x, int n,string y, int m)
{
    int tab[n+1][m+1];
   
    for(int i=0;i<=n;i++)
        tab[i][0]=0;
    for(int i=0;i<=m;i++)
        tab[0][i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
                tab[i][j]=tab[i-1][j-1]+tab[i][j-1];
            else
                tab[i][j]=tab[i][j-1];
        }
    }
    
    cout<<tab[n][m];
}

int main()
{
    string x="Gks";
    string y="GeeksforGeeks";
    occurance(x,x.length(),y,y.length());
    return 0;
}
