void sieve(ll n)
{
    vector<char> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) 
    {
        if (is_prime[i] && (long long)i * i <= n) 
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    f(i,0,n)
    {
        if(is_prime[i]==1)
        {
            cout<<i<<" ";
        }
    }
}
// primes till 10^7 
