ll binaryexponention(ll a,ll b)
{
    ll result=1;
    while(b>0)
    {
        if(b%2==1)
        {
            result*=a;
        }
        a*=a;
        b/=2;
    }
    return result;
}
int bintodec(string s)
{
    reverse(s.begin(),s.end());
    ll ans=0;
    f(i,0,s.length())
    {
        if(s[i]=='1')
        {
            ans+=binaryexponention(2,i);
            // ans%=1000003;
        }
    }
    return ans;
}
