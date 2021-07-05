// Question Link: https://www.spoj.com/problems/MARBLES/

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


ll ncr(int n, int r)
{
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
 
    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
 
            long long m = __gcd(p, k);
 
            p /= m;
            k /= m;
 
            n--;
            r--;
 
        }
    }
 
    else
    {
        p = 1;
    }
    return p;
}
string decToBinary(int n)
{
    int binaryNum[32];
    string s="";    int i = 0;
    while (n > 0) 
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        if(binaryNum[j]==0)
        {
            s+='0';
        }
        else{
            s+='1';
        }
    }
    return s;
}


ll binaryexponention(ll a,ll b)
{
    ll result=1;
    ll mod=1e9+7;
    while(b>0)
    {
        if(b%2==1)
        {
            result*=a;
        }
        result%=mod;
        a*=a;
        a%=mod;
        b/=2;
    }
    return result;
}
void div2round()
{
    ll n,a,b;
    cin>>n;
    vpair v;
    f(i,0,n)
    {
        cin>>a>>b;
        v.pb(mp(a,b));
    }
    vi v1={1};
    ll i=0;
    if(n==3)
    {
        cout<<1<<" "<<2<<" "<<3<<"\n";
        return;
    }
    while(v1.size()<n)
    {
        ll cur=v1[i];
        ll x=v[cur-1].first,y=v[cur-1].second;
        if(v[x-1].first==y || v[x-1].second==y)
        {
            v1.pb(x);
        }
        else{
            v1.pb(y);
        }
        i++;
    }
    f(i,0,n)
    {
        cout<<v1[i]<<" ";
    }
}
int main()
{
    // freopen("inp.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    ios::sync_with_stdio(0);// Input and output clearance
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        a-=b;
        cout<<ncr(a+b-1,a)<<"\n";
    }
    // cout<<ncr(29,23);
}
