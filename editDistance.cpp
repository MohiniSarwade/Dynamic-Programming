class Solution
{
	public:
		int editDistance(string s, string t)
		{
		    // Code here
		    int n=s.size();
		    int m=t.size();
		    int tab[n+1][m+1];
		    for(int i=0;i<=n;i++)
		        tab[i][0]=i;
		    for(int i=0;i<=m;i++)
		        tab[0][i]=i;
		    for(int i=1;i<=n;i++)
		    {
		        for(int j=1;j<=m;j++)
		        {
		
		            if(s[i-1]==t[j-1])
		                tab[i][j]=tab[i-1][j-1];
		            else
		                tab[i][j]=min(tab[i-1][j],min(tab[i-1][j-1],tab[i][j-1]))+1;
		        }
		    }
		    
		    return tab[n][m];
		}
};
