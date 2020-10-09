int count( int S[], int m, int n ) 
{ 
	int table[n+1]; 

	memset(table, 0, sizeof(table)); 


	table[0] = 1; 

	// Pick all coins one by one and update the table[] values 
	// after the index greater than or equal to the value of the 
	// picked coin 
	for(int i=0; i<m; i++) 
		for(int j=S[i]; j<=n; j++) 
			table[j] += table[j-S[i]]; 

	return table[n]; 
} 
/////////////////////////////////////////////////////////////////////
long long int count( int S[], int m, int n )
    {
       
        //code here.
       long long int tab[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
                tab[i][j]=0;
        }
        for(long long int  i=0;i<=m;i++)
            tab[i][0]=1;
        for(long long int i=0;i<=n;i++)
            tab[0][i]=0;
         for(long long int i=1;i<=m;i++)
        {
            for(long long int j=1;j<=n;j++)
            {
                if(j>=S[i-1])
                    tab[i][j]=tab[i-1][j]+tab[i][j-S[i-1]];
                else
                    tab[i][j]=tab[i-1][j];
                    
            }
        }
        
        return tab[m][n];
    }
