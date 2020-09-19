#include<bits/stdc++.h>
using namespace std;
#define V 4
#define INF 9999

void floydWarshall(int graph[][V])
{
    int tab[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            tab[i][j]=graph[i][j];
        }
    }
    
    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(tab[i][k]+tab[k][j]<tab[i][j])
                    tab[i][j]=tab[i][k]+tab[k][j];
            }
        }
    }
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(tab[i][j]==INF)
                cout<<"INF"<<" ";
            else 
                cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main()  
{  
    /* Let us create the following weighted graph  
            10  
    (0)------->(3)  
        |     /|\  
    5 |     |  
        |     | 1  
    \|/     |  
    (1)------->(2)  
            3     */
    int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
  
    floydWarshall(graph);  
    return 0;  
}  
