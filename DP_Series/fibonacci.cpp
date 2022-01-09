#include <iostream>
#include <bits/stdc++.h> 
#include <algorithm>
using namespace std;
#define ll long long


// Memoization
int memoize(int n,vector<int> &dp)
{
    if(n<=1)
    {
        return dp[n]=n;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=memoize(n-1,dp)+memoize(n-2,dp);
}

//Tabulation
// Bottom Up Approach
int tabulate(int n,vector<int> &dp)
{
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// Space optimization

int low_space(int n)
{
    int a=0;
    int b=1;
    int c=1;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main()
{
    vector<int>dp(100001,-1);
    int n;
    cin>>n;
    cout<<low_space(n)<<"\n";
}
