ll factorial(ll n)
{
    // single line to find factorial
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
int main()
{
    // freopen("inp.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    ios::sync_with_stdio(0);// Input and output clearance
    cin.tie(0);
    int n;
    cin>>n;
    cout<<factorial(n)<<"\n";
}
