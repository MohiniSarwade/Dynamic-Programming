#include<bits/stdc++.h>
#define C 4
using namespace std;

int MaxHisto(int A[])
{
    stack<int>res;
    int Ctop;
    int i=0;
    int cA=0;
    int mA=0;
   while(i<C)
    {
        if(res.empty()||A[res.top()]<=A[i])
            res.push(i++);
        else
        {
            Ctop=A[res.top()];
            res.pop();
            cA=Ctop*i;
            if(!res.empty())
            {
                cA=Ctop*(i-res.top()-1);
            }
            mA=max(mA,cA);
        }
    }
    while(!res.empty())
    {
        Ctop=A[res.top()];
            res.pop();
            cA=Ctop*i;
            if(!res.empty())
            {
                cA=Ctop*(i-res.top()-1);
            }
            mA=max(mA,cA);
    }
    return mA;
}

int maxRectangle(int A[][C])
{
    for(int i=1;i<=C;i++)
    {
        for(int j=1;j<=C;j++)
        {
            if(A[i][j]==1)
                A[i][j]=A[i-1][j]+1;
        }
    }
    int curMax=0;
    for(int i=0;i<C;i++)
    {
        int Max=MaxHisto(A[i]);
        if(Max>curMax)
            curMax=Max;
    }
    return curMax;
}
int main() 
{ 
    int A[][C] = { 
        { 0, 1, 1, 0 }, 
        { 1, 1, 1, 1 }, 
        { 1, 1, 1, 1 }, 
        { 1, 1, 0, 0 }, 
    }; 
  
    cout << "Area of maximum rectangle is "
         << maxRectangle(A); 
  
    return 0; 
} 
