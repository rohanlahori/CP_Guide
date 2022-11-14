// Recursion to Tabulation:

// write base case
// write changing parameters: reverse them
// copy the recurrence logic and change rec to dp vector



#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <bits/stdc++.h> 
#include <algorithm>
using namespace std;
#define ll long long 
#define all(x) (x).begin(),(x).end()
#define vll vector<ll>
#define vi vector<ll>
#define vp vector<pi>
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define POB pop_back 
#define f(i,x,z) for(ll i=x;i<z;i++)
#define debug(x) cout<<'DEBUG------> '<<x<<endl
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define clr(x) memset(x, 0, sizeof(x)) 
#define setall(x,a) memset(x, a, sizeof(x))
#define INF 1000000000000000003 
#define mathpi 3.141592653589793238 
#define F first;
#define S second;
#define vpair vector<pair<ll,ll>>
#define vpairs vector<pair<string,string>>
#define tin tuple<ll,ll,ll>
#define rev(i,x,z) for(ll i=x;i>=z;i--)  
#define ld long double 
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<"\n"; 
#define print_pair(v) for(auto x:v){cout<<x.first<<" "<<x.second<<" ";}cout<<"\n"; 
#define reverse(v) reverse(v.begin(),v.end()) 
#define nline "\n"
#define nl "\n"
int dp[3005][3005];

class Solution {
public:

    int lis(int i,int prev,vector<int> &v,int n)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        int take=-1;
        int nottake=-1;
        if(prev==-1 || v[i]>v[prev])
        {
            take=1+lis(i+1,i,v,n);
        }
        nottake=lis(i+1,prev,v,n);
        return dp[i][prev+1]=max(take,nottake);
    }

    int tabulateeasily(vector<int> &v,int n)
    {
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                if(prev==-1 || v[i]>v[prev])
                {
                    dp[i][prev+1]=max(dp[i+1][prev+1],1+dp[i+1][i+1]);
                }
                else{
                    dp[i][prev+1]=dp[i+1][prev+1];
                }
            }
        }
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<3005;i++)
        {
            for(int j=0;j<3005;j++)
            {
                dp[i][j]=-1;
            }
        }
        return lis(0,-1,nums,n);
    }
};


int main()
{
    Solution obj;
    ll n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    for(int i=0;i<3005;i++)
    {
        for(int j=0;j<3005;j++)
        {
            dp[i][j]=0;
        }
    }
    int x=obj.lengthOfLIS(nums);
    cout<<x<<"\n";
}
