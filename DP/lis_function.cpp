int lis(vector<int> &v,int n)
{
    vector<int>dp(n+1,1);
    int mx=1;
    for(int i=0;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(v[i]>v[j])
            {
                dp[i]=max(dp[i],1+dp[j]);
            }
            mx=max(mx,dp[i]);
        }
    }
    return mx;
}
