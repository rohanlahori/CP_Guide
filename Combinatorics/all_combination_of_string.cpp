#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//#pragma GCC optimize('O2') 
#define ll long long 
#define vll vector<ll>
#define vi vector<int>
#define tin tuple<ll,ll,ll>
#define mll map<ll,ll>
#define pi pair<ll,ll>
#define vp vector<pi>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define rall(x) x.rbegin(), x.rend()
#define watch(x) cout << (#x) << ' is ' << (x) << endl
#define f(i,x,z) for(ll i=x;i<z;i++)
#define rf(i,x,z) for(ll i=x-1;i>=z;i--)
#define deb(x) cout<<'DEBUG------> '<<x<<endl
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define clr(x) memset(x, 0, sizeof(x)) 
#define fa(i,vect) for(auto i : vect)
#define fr(i,vect) for(VI :: reverse_iterator i = vect.rbegin(); i != vect.rend(); i++)
#define mod 1000000007
//  for (auto &a : v)
//cin >> a;
//for (auto me : m) {
//std::vector<ll>::iterator it; 
//it = std::find (v.begin(), v.end(), ser);
//if (it != v.end())
# define INF 0x3f3f3f3f 
////////////////////////////////////////////////////////////////////////////////////////////

ll power(ll base,ll por)
{
ll res=1;
while(por>1){
if(por%2==1)
{
res*=base;
por--;
}
por/=2;
base*=base;
}
res*=base;
return res;
}
vector<string> v;
bool shouldswap(string aa, ll start, ll curr)
{
	f(i,start,curr)
	{
		if(aa[i]==aa[curr])
			return 0;
	}
	return 1;
}
void findpermutation(string aa,ll index, ll n)
{
	if(index>=n)
	{
		v.pb(aa);
		return;
	}
	f(i,index,n)
	{
		bool check=shouldswap(aa,index,i);
		if(check)
		{
			swap(aa[index],aa[i]);
			findpermutation(aa,index+1,n);
			swap(aa[index],aa[i]);
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
//   freopen('a.txt', 'r', stdin); freopen('a_out.txt', 'w', stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t,n;
	string aa;
	cin>>aa;
	findpermutation(aa,0,aa.size());
	cout<<v.size()<<"\n";
	srt(v);
	f(i,0,v.size())
	{
		cout<<v[i]<<"\n";
	}
   return 0;
}