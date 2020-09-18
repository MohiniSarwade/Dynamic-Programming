#include<bits/stdc++.h>
using namespace std;

int countParenth(char symbols[], char operators[], int n)
{
    int t[n][n],f[n][n];
    for(int i=0;i<n;i++)
    {
        f[i][i]=(symbols[i]=='F')?1:0;
        t[i][i]=(symbols[i]=='T')?1:0;
    }
    for(int gap=1;gap<=n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            t[i][j]=f[i][j]=0;
            for(int g=0;g<gap;g++)
            {
                int k=i+g;
                int tik=t[i][k]+f[i][k];
                int tkj=t[k+1][j]+f[k+1][j];
                
                if(operators[k]=='&')
                {
                    t[i][j]+=t[i][k]*t[k+1][j];
                    f[i][j]+=tik*tkj-t[i][k]*t[k+1][j];
                }
                else if(operators[k]=='|')
                {
                    f[i][j]+=f[i][k]*f[k+1][j];
                    t[i][j]+=tik*tkj-f[i][k]*f[k+1][j];
                }
                else if(operators[k]=='^')
                {
                    t[i][j]+=t[i][k]*f[k+1][j]+f[i][k]*t[k+1][j];
                    f[i][j]+=t[i][k]*t[k+1][j]+f[i][k]*f[k+1][j];
                }
                
            }
        }
    }
    return t[0][n-1];
}
int main() 
{ 
    char symbols[] = "TTFT"; 
    char operators[] = "|&^"; 
    int n = strlen(symbols); 
  
    cout <<"Number of ways to parenthise string "<<countParenth(symbols, operators, n); 
    return 0; 
} 
