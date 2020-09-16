#include<bits/stdc++.h>
using namespace std;
struct Box
{
    int h,w,d;
};
int comp(const void *a,const void *b)
{
    return (*(Box *)b).d * (*(Box *)b).w > (*(Box *)a).d * (*(Box *)a).w;
}
int  maxStackHeight(Box arr[],int n)
{
    Box res[3*n];
    int index=0;
    for(int i=0;i<n;i++)
    {
        res[index].h=arr[i].h;
        res[index].d=max(arr[i].d,arr[i].w);
        res[index].w=min(arr[i].d,arr[i].w);
        index++;
        
        res[index].h=arr[i].d;
        res[index].d=max(arr[i].h,arr[i].w);
        res[index].w=min(arr[i].h,arr[i].w);
        index++;
        
        res[index].h=arr[i].w;
        res[index].d=max(arr[i].d,arr[i].h);
        res[index].w=min(arr[i].d,arr[i].h);
        index++;
    }
    n=3*n;
    qsort(res,n,sizeof(res[0]),comp);
    
    int tmp[n+1];
    for(int i=0;i<n;i++)
        tmp[i]=res[i].h;
        
    int max=tmp[0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(res[j].w>res[i].w && res[j].d>res[i].d && tmp[j]+res[i].h>tmp[i])
            {
                tmp[i]=tmp[j]+res[i].h;
                if(max<tmp[i])
                    max=tmp[i];
            }
        }
    }
    return max;
}

int main() 
{ 
  Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} }; 
  int n = sizeof(arr)/sizeof(arr[0]); 
  
  printf("The maximum possible height of stack is %d\n", 
         maxStackHeight (arr, n) ); 
  
  return 0; 
} 
