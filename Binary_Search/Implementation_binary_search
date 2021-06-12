// aaj to fodna ha bhai div 3 aya khushiya laya

// Code Template bY !@ Rohan Lahori
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

ll binary_search(ll n,ll *a,ll target)
{
    ll st=0,end=n-1,mid;
    while(st<=end)
    {
        mid=(st)+(end-st)/2;
        if(a[mid]==target)
        {
            return mid;
        }
        else if(a[mid]<target)
        {
            st=mid+1;
        }
        else{
            end=mid-1;
        }
        // cout<<st<<" "<<end<<" ";
    }
    return -1;
}
int main()
{
	// freopen("inp.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);// Input and output clearance
	cin.tie(0);
    ll arr[101];
    f(i,0,100)
    {
        arr[i]=i;
    }
    ll target=50;
    ll n=101;// size of given array
    cout<<binary_search(n,arr,target);
}
