int DivisibleByM(vector<int>nums, int m){
		    // Code here
		    int n=nums.size();
		    if(n>m)
		        return 1;
		    int Dp[m+1];
		    memset(Dp,0,sizeof(Dp));
		    for(int i=0;i<n;i++)
		    {
		        if(Dp[0])
		            return true;
		        int tab[m];
		        memset(tab,0,sizeof(tab));
		        
		        for(int j=0;j<m;j++)
		        {
		            if(Dp[j]==true)
		            {
		                if(Dp[(j+nums[i])%m]==false)
		                    tab[(j+nums[i])%m]=true;
		            }
		        }
		        for(int j=0;j<m;j++)
		        {
		            if(tab[j])
		                Dp[j]=true;
		        }
		        
		        Dp[nums[i]%m]=true;
		    }
		    if(Dp[0]==false)
		        return false;
		}
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    	int DivisibleByM(vector<int>nums, int m){
		    // Code here
		    unordered_map<int,int>mp;
		    mp[0]=1;
		    int n=nums.size();
		    int cs=0;
		    for(int i=0;i<n;i++)
		    {
		       cs+=nums[i];
		       if(cs<0)
		            cs=(cs+n)%m;
		        else
		            cs%=m;
		       if(mp[cs]>1)
		            return true;
		        else
		            mp[cs]++;
		    }
		    for(auto i:mp)
		    {
		        if(i.second>1)
		            return true;
		    }
		    return false;
		}
