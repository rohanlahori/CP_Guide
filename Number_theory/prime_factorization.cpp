void prime_factorization(ll n)
{
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
            if((n/i)!=i)
            {
                cout<<n/i<<" ";
            }
        }
    }
    cout<<"\n";
}
