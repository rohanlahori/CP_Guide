// CF: https://codeforces.com/contest/161/problem/D



#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define vll vector<ll>
#define vi vector<int>
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define POB pop_back
#define f(i, x, z) for (ll i = x; i < z; i++)
#define debug(x) cout << 'DEBUG------> ' << x << endl
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define clr(x) memset(x, 0, sizeof(x))
#define setall(x, a) memset(x, a, sizeof(x))
#define INF 1000000000000000003
#define mathpi 3.141592653589793238
#define F first
#define S second
#define vs vector<string>
#define vpair vector<pair<ll, ll>>
#define vpairs vector<pair<string, string>>
#define tin tuple<ll, ll, ll>
#define ld long double
#define prll(v) for(auto x:v){cout<<x<<" ";}cout<<"\n";
#define prll_pair(v) for(auto x:v){cout<<x.first<<" "<<x.second<<"\n";};
#define nline "\n"
#define nl "\n"
#define rev(v) reverse(v.begin(), v.end())
#define mapll map<ll, ll>
#define maplc map<ll, char>
#define mapcc map<char, char>
#define mapcl map<char, ll>


int dp1[50005][505],dp2[50005][505];
vector<int>adj[50005];

void dfs(int cur,int parent,int k)
{
    for(auto x:adj[cur])
    {
        if(x!=parent)
        {
            dfs(x,cur,k);
        }
    }
    dp1[cur][0]=1;
    for(int i=1;i<=k;i++)
    {
        for(auto child:adj[cur])
        {
            dp1[cur][i]+=dp1[child][i-1];
        }
    }

}


void solve(int cur,int par,int k)
{
    for(int dis=0;dis<=k;dis++)
    {
        dp2[cur][dis]=dp1[cur][dis];
    }
    if(par!=-1)
    {
        dp2[cur][1]+=1;
        for(int dis=2;dis<=k;dis++)
        {
            dp2[cur][dis]+=(dp2[par][dis-1]-dp1[cur][dis-2]);
        }
    }

    for(auto x:adj[cur])
    {
        if(x!=par)
        {
            solve(x,cur,k);
        }
    }
}



void cses()
{
    ll n,k;
    cin>>n>>k;
   
    ll st=0;
    f(i,0,n-1)
    {
        ll x,y;
        cin>>x>>y;
        if(i==0)
        {
            st=x;
        }
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,-1,k);
    solve(1,-1,k);
    ll ans=0;
    f(i,1,n+1)
    {
        ans+=dp2[i][k];
    }
    cout<<ans/2<<"\n";
}
int main()
{
    // freopen("inp.txt","r",stdin);
    // freopen("out5.txt","w",stdout);
    // ios::sync_with_stdio(0); // Input and output clearance
    // cin.tie(0);
    cses();
}

      


// suppose x is a node in diameter of tree the maximum of 2 values in the subtree
//  would be the diameter in it
