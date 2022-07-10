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
#define fr(i, x, z) for (ll i = x-1; i >=z; i--)
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
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<"\n";
#define print_pair(v) for(auto x:v){cout<<x.first<<" "<<x.second<<"  ";}cout<<"\n";
#define nline "\n"
#define nl "\n"
#define rev(v) reverse(v.begin(), v.end())
#define mapll map<ll, ll>
#define maplc map<ll, char>
#define mapcc map<char, char>
#define mapcl map<char, ll>


int find_parent(int x,vector<int> &parent){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=find_parent(parent[x],parent);
}

void union_sets(int x,int y,vector<int> &parent,vector<int> &rank){
    x=find_parent(x,parent);
    y=find_parent(y,parent);
    if(rank[x]==rank[y]){
        parent[y]=x;
        rank[x]++;
    }
    else if(rank[x]>rank[y]){
        parent[y]=x;
    }
    else{
        parent[x]=y;
    }
}
void dsu()
{
    int n;
    cin>>n;
    vector<int> parent(n+1);
    vector<int> rank(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        rank[i]=0;
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        union_sets(x,y,parent,rank);
        // I have to union x and y
        // 2 options: make x as the parent of y or make y as the parent of x
        
        // one with lower rank will be attached to the rank with higher rank

        //  Height of the tree only increases if similar rank guys are attached to 
        // each other because if a lower rank guy is attached to higher rank guy the 
        // height of the tree would never increase
    }
    for(int i=1;i<parent.size();i++)
    {
        cout<<parent[i]<<" ";
    }
    cout<<"\n";

}
int main()
{
    //  freopen("inp.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    ios::sync_with_stdio(0); // Input and output clearance
    cin.tie(0);
    dsu();
}
