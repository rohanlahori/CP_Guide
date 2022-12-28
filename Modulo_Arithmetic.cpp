template<typename T> T getmod(T x, T m)
{
    T z = x % m;

    if(z >= 0) return z;
    return (z + m);
}
ll mod_add(ll a, ll b, ll m)
{
    a = getmod(a, m);
    b = getmod(b, m);
    return (((a + b) % m) + m) % m;
}

ll mod_mul(ll a, ll b, ll m)
{
    a = getmod(a, m);
    b = getmod(b, m);
    return (((a * b) % m) + m) % m;
}

ll mod_sub(ll a, ll b, ll m)
{
    a = getmod(a, m);
    b = getmod(b, m);
    return (((a - b) % m) + m) % m;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

ll modInverse(ll b, ll m)
{
    ll x, y; // used in extended GCD algorithm
    ll g = gcdExtended(b, m, &x, &y);
    if (g != 1)
    {
        return -1;
    }
    return (x%m + m) % m;
} 
ll modDivide(ll a, ll b, ll m)
{
    a = a % m;
    ll inv = modInverse(b, m);
    ll ans=(inv * a) % m;

    return ans;

}
