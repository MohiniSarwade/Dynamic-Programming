int LP(string s)
{
    stack<int>st;
    int n=s.length();
    st.push(-1);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
            st.push(i);
        else
        {
            st.pop();
            if(!st.empty())
            {
                count=max(count,i-st.top());
            }
            else
                st.push(i);
        }
    }
    return count;
}

int LP(string s)
{
    int count=0;
    int n=s.length();
    vector<int>tab(n+1,0);
    for(int i=1;i<n;i++)
    {
        if(s[i]==')'&& (i-tab[i-1]-1)>=0 && s[i-tab[i-1]-1]=='(')
            tab[i]=tab[i-1]+2+((i-tab[i-1]-2 >=0)?tab[i-tab[i-1]-2]:0);
        count=max(count,tab[i]);
    }
    return count;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<LP(s)<<endl;
	}
	return 0;
}
