//. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Find out maximum amount of gold he can collect.

#include <iostream>
#include<bits/stdc++.h>
#define MAX 4
using namespace std;

int getMaxGold(int gold[][MAX],int m, int n)
{
   
    vector<vector<int>>tab(MAX,vector<int>(MAX,0));
    for(int j=n-1;j>=0;j--)
    {   int c=0;
        for(int i=0;i<m;i++)
        {
            int right=(j==n-1)?0:tab[i][j+1];
            int right_up=(i==0||j==n-1)?0:tab[i-1][j+1];
            int right_down=(i==m-1||j==n-1)?0:tab[i+1][j+1];
            
            tab[i][j]=gold[i][j]+max(right,max(right_up,right_down));
        }
    }
    int Max=tab[0][0];
    for(int i=0;i<m;i++)
        Max=max(Max,tab[i][0]);
    return Max;
}

int main() 
{ 
    int gold[MAX][MAX]= {{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};
    int m = 4, n = 4; 
    cout << getMaxGold(gold, m, n); 
    return 0; 
} 
