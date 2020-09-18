#include<bits/stdc++.h>
using namespace std;
int sum(int freq[], int i,int j)
{
    int x=0;
    for(int k=i;k<=j;k++)
    {
        x+=freq[k];
    }
    return x;
}
void print(vector<vector<int>>p,int keys[],int low,int high)
{
    
    if(high<low)
        return;
    if(low==high)
        cout<<keys[low]<<" ";
    int x=p[low][high];
    if(x==-1)
        return;
    cout<<keys[x]<<" ";
    print(p,keys,low,x-1);
    print(p,keys,x+1,high);
    
}
int optimalSearchTree(int keys[],int freq[],int n)
{
    int tab[n][n];
    vector<vector<int>>p(n,vector<int> (n,-1));
    for(int i=0;i<n;i++)
        tab[i][i]=freq[i];
        
    for(int gap=1;gap<=n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            tab[i][j]=INT_MAX;
            for(int g=0;g<=gap;g++)
            {
                int k=i+g;
                int c=((k>i)?tab[i][k-1]:0)+((j>k)?tab[k+1][j]:0)+sum(freq,i,j);
                if(c<tab[i][j])
                {
                    tab[i][j]=c;
                    p[i][j]=k;
                }
            }
        }
    }
    cout<<"Preorder traversal of tree"<<endl;
    print(p,keys,0,n-1);
    return tab[0][n-1];
}

int main()  
{  
    int keys[] = {10, 12, 16,21};  
    int freq[] = {4,2,6,3};  
    int n = sizeof(keys)/sizeof(keys[0]);  
    int z=optimalSearchTree(keys, freq, n);
    cout <<endl<<"Cost of Optimal BST is " <<z;  
    return 0;  
}  
