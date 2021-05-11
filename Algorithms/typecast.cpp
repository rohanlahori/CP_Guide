// converting int n to string 
ostringstream str1;
str1 << n;
string s = str1.str();


// converting string s to int n
stringstream geek(s);
ll n=0;
geek >> n;
