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
const int MAX = 1e3 + 7; 
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


/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
//   freopen('a.txt', 'r', stdin); freopen('a_out.txt', 'w', stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,n;
    string bb;
    cin>>bb;
    ll a,co=0,c=0,d=0,b=0,k;
    n=bb.size();
    int l[n][n];
    f(i,0,n)
    {
        f(j,0,n)l[i][j]=0;
    }
   f(i,0,n)
   {
       l[i][i]=1;
   }
       
       f(j,2,n+1)
       {
           f(i,0,n-j+1)
           {
               t=i+j-1;
               if(bb[i]==bb[t] && j==2)
               {
                   l[i][t]=2;
               }
               else if(bb[i]==bb[t])
               {
                   l[i][t]=l[i+1][t-1]+2;
               }
               else
               {
                   l[i][t]=max(l[i][t-1],l[i+1][t]);
               }
               
           }
       }
   
   cout<<l[0][n-1];
   return 0;
}