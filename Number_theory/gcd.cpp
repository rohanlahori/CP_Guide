//a>b for all a and b
ll gcd(ll a,ll b)
{
    if(b==0)
    {
        return a;   
    }
    else{
        return gcd(b,a%b);
    }
}
