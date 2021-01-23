void sieve(ll n)
    {
        ll a[n+1];
        a[1]=1;
        f(i,2,n+1)
        {
            a[i]=0;
        }
        for(ll i=2;i<=sqrt(n);i++)
        {
            if(a[i]==0)
            {
                for(ll j=i*2;j<n;j+=i)
                {
                    a[j]=1;
                }
            }
        }
        f(i,1,n+1)
        {
            if(a[i]==0)
            {
                cout<<i<<" ";
            }
        }
        cout<<"\n";
    }
