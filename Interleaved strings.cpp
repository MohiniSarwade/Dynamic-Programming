bool isInterleave(string A, string B, string C) 
{
    //Your code here
    int m=A.length();
    int n=B.length();
    int tab[m+1][n+1];
    memset(tab, 0, sizeof(tab));
    if((n+m)!=C.length())
        return false;
   
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 && j==0)
                 tab[i][j]=true;
            else if(i==0)
            {
                if(B[j-1]==C[j-1])
                    tab[i][j]=tab[i][j-1];
            }
            else if(j==0)
            {
                if(A[i-1]==C[i-1])
                    tab[i][j]=tab[i-1][j];
            }
            else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1])
                tab[i][j]=tab[i-1][j];
            else if(A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1])
                tab[i][j]=tab[i][j-1];
            else if(A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1])
                tab[i][j]=tab[i-1][j]||tab[i][j-1];
        }
    }
    return tab[m][n];
}
