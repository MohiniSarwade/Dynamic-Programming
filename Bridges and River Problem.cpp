#include<bits/stdc++.h>
using namespace std;
struct CityPairs
{
    int l,r;
};
bool comp(struct CityPairs a,struct CityPairs b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}
int maxBridges(CityPairs values[],int n)
{
    sort(values,values+n,comp);
    vector<int>v(n,1);
    int Max=INT_MIN;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(values[i].r>=values[j].r && v[j]+1>v[i])
                v[i]=v[j]+1;
            if(Max<v[i])
                Max=v[i];
        }
    }
    return Max;
}
int main() 
{ 
    struct CityPairs values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}}; 
    int n = 4; 
    cout << "Maximum number of bridges = " 
             << maxBridges(values, n);     
    return 0; 
}  
