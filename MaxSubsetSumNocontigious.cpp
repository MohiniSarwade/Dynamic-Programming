int maxSubsetSum(vector<int> arr) {
    int n=arr.size();
    if(n==0)
        return 0;
    if(n==1)
        return arr[0];
    int t[n];
    t[0]=max(0,arr[0]);
    t[1]=max(t[0],arr[1]);
    for(int i=2;i<n;i++)
    {
        t[i]=max(arr[i]+t[i-2],max(t[i-1],arr[i]));
    
    }
    return t[n-1];

}
int main()
{
  vector<int> arr={-4,3,3,8,0,18};
  cout<<maxSubsetSum(arr); 
  return 0;
}
