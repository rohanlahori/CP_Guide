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
ll bpowm(ll a, ll b, ll m)
{
    ll ans = 1;

    while(b > 0)
    {
        if(b % 2 == 0)
        {
            a = ((a % m) * 1LL * (a % m)) % m;
            b = (b) / 2;

        }

        else
        {
            ans = ((ans % m) * 1LL * (a % m)) % m;
            b--;

        }

    }

    return ans % m;

}

ll mod_inv_prime(ll a, ll b)
{
    return bpowm(a, b - 2, b);
}
