#include<bits/stdc++.h>
using namespace std;

void print(int i, int j,int s[][1024], int n, char &x)
{
    
    if(i==j)
    {
        cout<<x++;
        return;
    }
    cout<<"(";
    print(i,s[i][j],s,n,x);
    print(s[i][j]+1,j,s,n,x);
    cout<<")";
}
int MatrixMultiplication(int p[], int len)
{
     int n=len-1;
    int m[n][n];
    int s[1024][1024];
    for(int i=1;i<=n;i++)
        m[i][i]=0;
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                if(m[i][j]>(m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]))
                {
                    m[i][j]=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                    s[i][j]=k;
                }
            }
        }
    }
    char x='A';
    print(1,n,s,n,x);
    return m[1][n];
}

int main()
{
    int p[]={2,3,6,4,5};
    int n=sizeof(p)/sizeof(p[0]);
    int z=MatrixMultiplication(p,n);
    cout<<endl<<"cost of matrix chain multiplication is "<<z;
    
    return 0;
}
