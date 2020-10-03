int nCr(int n, int r){
        // code here
        vector<long long int>tab(r+1);
        tab[0]=1;
        const int M=pow(10,9)+7;
        for(int i=0;i<=n;i++)
        {
            for(int j=min(i,r);j>0;j--)
            {
               tab[j]=(tab[j]+tab[j-1])%M;
            }
        }
        return tab[r];
    }
    
   int nCr(int n, int r){
        // code here
        vector<vector<long long int>>tab(n+1,vector<long long int>(r+1));
        const int M=pow(10,9)+7;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=min(i,r);j++)
            {
                if(j==0||i==j)
                    tab[i][j]=1;
                else
                    tab[i][j]=(tab[i-1][j-1]+tab[i-1][j])%M;
            }
        }
        return tab[n][r];
    }
