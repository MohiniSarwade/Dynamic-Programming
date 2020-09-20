#include<bits/stdc++.h>
#define R 6  
#define C 5 
using namespace std;


void printMaxSubSquare(bool M[R][C])
{
    int S[R][C];
    for(int i=0;i<R;i++)
        S[i][0]=M[i][0];
    for(int i=0;i<C;i++)
        S[0][i]=M[0][i];
    for(int i=1;i<R;i++)
    {
        for(int j=1;j<C;j++)
        {
            if(M[i][j]==1)
                S[i][j]=min(S[i-1][j],min(S[i][j-1],S[i-1][j-1]))+1;
            else
                S[i][j]=0;
        }
    }
    int max_s=S[0][0],max_i=0,max_j=0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(S[i][j]>max_s)
            {
                max_s=S[i][j];
                max_i=i;
                max_j=j;
            }
        }
    }
    for(int i=max_i;i>max_i-max_s;i--)
    {
        for(int j=max_j;j>max_j-max_s;j--)
        {
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()  
{  
    bool M[R][C] = {{0, 1, 1, 0, 1},  
                    {1, 1, 0, 1, 0},  
                    {0, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 1},  
                    {0, 0, 0, 0, 0}};  
                      
    printMaxSubSquare(M);  
    return 0;
}  

  
