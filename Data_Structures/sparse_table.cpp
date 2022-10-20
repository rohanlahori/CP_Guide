//Classic
//g++ -std=c++17 -O2 -Wall a.cpp -o test
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vp vector<pi>
#define vpll vector<pll>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define For(i,a,b) for(ll i=a;i<b;i++)
#define endl "\n"
#define debug2(x,y) cout<<"This side ----> "<<#x<<" -> "<<x<<" | "<<#y<<" -> "<<y<<endl;
#define debug(x) cout<<"This side    ----> "<<#x<<" -> "<<x<<endl
//#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
//#define ao(a, n) {for (int ele = 0; ele < (n); ele++) {cout << a[ele]<<" "; } cout << '\n';}
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define mint map<int,int>
#define mall map<ll,ll>
#define ciN cin
#define g(a,s) get<a>(s)
#define tin tuple<ll,ll,ll>
#define ter(x,y,z) ((x)?y:z)

struct Item {
	ll x;
};
struct sparse_table
{
	Item NEUTRAL = {1000000009};
	vector<vector<Item>> tab;
	int siz, bit;
	Item merge(Item a, Item b) {
		// Which operation you want sparse table to perform. 'min' is used here.
		Item c;
		c.x = min(a.x, b.x);
		return c;
	}
	Item single(ll a) {
		Item b; b.x = a; return b;
	}
	void init(int n) {
		// Find the 'bit' value required and initialized the 'tab' vector.
		int val = 1;
		bit = 0;
		while (val <= n) {
			bit++; val *= 2;
		}
		siz = n;
		tab.assign(bit, vector<Item>(n, NEUTRAL));

	}
	void build(vll &v) {
		// Build the 'tab' from the given array.
		// N*(log(N))
		for (int i = 0; i < siz; i++) {
			tab[0][i] = single(v[i]);
		}
		for (int i = 1; i < bit; i++) {
			for (int j = 0; j < siz; j++) {
				Item f = tab[i - 1][j];
				ll done = j + (1LL << (i - 1));
				Item s = NEUTRAL;
				if (done < siz) {
					s = tab[i - 1][done];
				}
				tab[i][j] = merge(f, s);
			}

		}
	}
	Item calc(int l, int r) {
		// 0-based indexing.
		// Find query answer for [l,r]. O(logN)
		int len = r - l + 1;
		int ind  = 0;
		for (int i = bit - 1; i > -1; i--) {
			if ((len & (1 << i))) {
				ind = i; break;
			}
		}
		Item a = tab[ind][l];
		ll xx = r - (1LL << ind) + 1;
		Item b = tab[ind][xx];
		return merge(a, b);
	}

};