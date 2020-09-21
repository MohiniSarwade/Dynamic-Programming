#include<bits/stdc++.h>
#define ROW 4
#define COL 5
using namespace std;

int kadane(int* tmp, int * s,int *f, int r)
{
    int l_s=0,sum=0,max_sum=INT_MIN;
    *f=-1;
    int maxSum=INT_MIN;
    for(int i=0;i<r;i++)
    {
        sum+=tmp[i];
        if(sum<0)
        {
            sum=0;
            l_s=i+1;
        }
        else if(sum>maxSum)
        {
            maxSum=sum;
            *s=l_s;
            *f=i;
        }
    }
    if(*f!=-1)
        return maxSum;
    maxSum=tmp[0];
    *s=*f=0;
    for(int i=1;i<r;i++)
    {
        if(tmp[i]>maxSum)
        {
            maxSum=tmp[i];
            *s=*f=i;
        }
    }
    return maxSum;
}

void findMaxSum(int M[][COL])
{
    int FLeft,FRight,FTop,FBottom;
    int maxSum=INT_MIN;
    int start,finish;
    int tmp[ROW];
    for(int i=0;i<COL;i++)
    {
        for(int z=0;z<ROW;z++)
            tmp[z]=0;
        for(int j=i;j<COL;j++)
        {
            for(int k=0;k<ROW;k++)
                tmp[k]+=M[k][j];
                
            int sum=kadane(tmp,&start,&finish,ROW);
            if(maxSum<sum)
            {
                maxSum=sum;
                FLeft=i;
                FRight=j;
                FTop=start;
                FBottom=finish;
            }
            
        }
    }
     cout << "(Top, Left) (" << FTop 
         << ", " << FLeft << ")" << endl;  
    cout << "(Bottom, Right) (" << FBottom  
         << ", " << FRight << ")" << endl;  
    cout << "Max sum is: " << maxSum << endl;  
}

int main()  
{  
    int M[ROW][COL] = {{1, 2, -1, -4, -20},  
                       {-8, -3, 4, 2, 1},  
                       {3, 8, 10, 1, 3},  
                       {-4, -1, 1, 7, -6}};  
  
    findMaxSum(M);  
  
    return 0;  
} 
