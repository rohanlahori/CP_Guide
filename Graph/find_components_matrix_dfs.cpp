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
#define vi vector<ll>
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
#define print(v)          \
    for (auto x : v)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define print_pair(v)                              \
    for (auto x : v)                               \
    {                                              \
        cout << x.first << " " << x.second << " "; \
    }                                              \
    cout << "\n";
#define nline "\n"
#define nl "\n"
#define rev(v) reverse(v.begin(), v.end())
#define mapll map<ll, ll>
#define maplc map<ll, char>
#define mapcc map<char, char>
#define mapcl map<char, ll>
void find_component(vector<pair<int,int>> &v,int n,int m,int i,int j,vector<vector<int>> &grid,
vector<vector<int>> &vis)
{
    if(i>n || j>m || i<0 || j<0)
    {
        return;
    }
    vector<int>xx({0,1,-1,0});
    vector<int>yy({1,0,0,-1});
    vis[i][j]=1;
    v.push_back(make_pair(i,j));
    for(int k=0;k<4;k++)
    {
        if(i+xx[k]>=0 && i+xx[k]<n && j+yy[k]>=0 && j+yy[k]<m && vis[i+xx[k]][j+yy[k]]==0 && grid[i+xx[k]][j+yy[k]]==1)
        {
            vis[i+xx[k]][j+yy[k]]=1;
            find_component(v,n,m,i+xx[k],j+yy[k],grid,vis);
        }
    }
}
int main()
{
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>mark(n,vector<int>(m,0));
    vector<vector<pair<int,int>>>components;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1 && vis[i][j]==0)
            {
                vector<pair<int,int>>v;
                find_component(v,n,m,i,j,grid,vis);
                components.push_back(v);
            }
        }
    }
    for(auto x:components)
    {
        for(auto y:x)
        {
            cout<<y.first<<" "<<y.second<<"  ";
        }
        cout<<"\n";
    }
}
