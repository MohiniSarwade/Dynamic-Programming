
#include<bits/stdc++.h>
using namespace std;


bool word_break(unordered_map<string,int>mp, string x)
{
    int n=x.length();
    bool tab[n+1];
    memset(tab,0,sizeof(tab));
    //cout<<x<<endl;
   for(int i=1;i<=n;i++)
   {
       if(tab[i]==false && mp.find(x.substr(0,i))!=mp.end())
            tab[i]=true;
        if(tab[i]==true)
        {
            if(i==n)
                return true;
            for(int j=i+1;j<=n;j++)
            {
                if(tab[j]==false && mp.find(x.substr(i,j-i))!=mp.end())
                    tab[j]=true;
                if(j==n && tab[j]==true)
                    return true;
            }
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
	    string tmp;
	    unordered_map<string,int>mp;
	    for(int i=0;i<n;i++)
	   {
	       cin>>tmp;
	       mp[tmp]++;
	   }
	    
	    string x;
	    cin>>x;
	   
	    cout<<word_break(mp,x)<<endl;
	}
	return 0;
}
/////////////////////////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;


bool word_break(unordered_map<string,int>mp, string x)
{
    int n=x.length();
    if(n==0)
        return true;
    for(int i=1;i<=n;i++)
    {
        if(mp.find(x.substr(0,i))!=mp.end() && word_break(mp,x.substr(i,n-i)))
            return true;
        
    }
    return false;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string tmp;
	    unordered_map<string,int>mp;
	    for(int i=0;i<n;i++)
	   {
	       cin>>tmp;
	       mp[tmp]++;
	   }
	    
	    string x;
	    cin>>x;
	   
	    cout<<word_break(mp,x)<<endl;
	}
	return 0;
}
