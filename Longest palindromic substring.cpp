#include<bits/stdc++.h>
using namespace std;

int longestPalSubstr(string s)
{
    int Max=1;
    int str=0;
    int n=s.length();
    bool tab[n][n]={{false}};
    
    for(int i=0;i<n;i++)
         tab[i][i]=true;
         
    for(int i=0;i<n;i++)
    {
        if(s[i]==s[i+1])
        {
            tab[i][i+1]=true;
            str=i;
            Max=2;
        }
    }
    for(int gap=2;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            if(s[i]==s[j] && tab[i+1][j-1])
            {
                tab[i][j]=true;
                if(Max<gap)
                {
                    Max=gap+1;
                    str=i;
                }
            }

        }
    }
    for(int i=str;i<str+Max;i++)
        cout<<s[i];
    cout<<endl;
    return Max;
}

int main() 
{ 
    string str = "forgeeksskeegfor"; 
    int x=longestPalSubstr(str);
    cout << "Length is: "
         <<x; 
    return 0; 
} 
