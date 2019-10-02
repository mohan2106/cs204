#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;

#define S second

#define forz(i, n) for (int i = 0; i < n; i++)

#define rforzm(i, m, n) for (int i = n - 1; i >= m; i--)


#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()
#define si size()
#define be begin()
#define en end()


#define all(v) v.be, v.en
#define le length()


// #define parity(n) __builtin_parity(n)
// #define ctz(n) __builtin_ctz(n)

#define mine *min_element
#define mod 1000000007
#define mod2 998244353
#define mp make_pair
#define mt make_tuple
// #define acc(v) accumulate(all(v), 0)
#define F first
// #define gcd __gcd
#define kira ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define endl "\n"
#define p0(a) cout << a << " "
#define forzm(i, m, n) for (int i = m; i < n; i++)
#define rforz(i, n) for (int i = n - 1; i >= 0; i--)
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
//this is just a test message
#define ofk order_of_key
#define fbo find_by_order
using namespace std;

/*STD fucntions*/
lli power(lli x, lli y, lli p)
{
    // calculate power
    long long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        //y must be even now
        y = y >> 1; //y=y/2
        x = (x * x) % p;
    }
    return res;
}
long long modi(lli a, lli m)
{
    return power(a, m - 2, m);
}
/*CODE BEGINS*/
bool cw(pair<lli, lli> a, pair<lli, lli> b, pair<lli, lli> c)
{
    //checking clockwise
    return a.F * (b.S - c.S) + b.F * (c.S - a.S) + c.F * (a.S - b.S) < 0;
}
bool ccw(pair<lli, lli> a, pair<lli, lli> b, pair<lli, lli> c)
{
    //checking clockwise or anticlock wise
    return a.F * (b.S - c.S) + b.F * (c.S - a.S) + c.F * (a.S - b.S) > 0;
}
int main()
{
    //main function starts from here
    kira;
    long long n;
    cin >> n;
    vector<pair<long long, long long>> data;
    long long x, y;
    forz(i, n)
    {
        //reading x and y coordinate
        cin >> x >> y;
        data.pb({x, y});
    }
    if (n == 1)
    {
        cout << data[0].F << " "<< data[0].S;
    }
    else
    {
        sort(data.begin(),data.end());
        vector<pair<lli, lli>> up, down;
        pair<lli, lli> p1 = data[0], p2 = data.back();
        up.pb(p1);
        down.pb(p1);
        if(p1 == p2)
        {
            p1(1);
            p2(p1.F,p1.S);
            return 0;
        }
        for (int i = 1; i < data.si; i++)
        {
            if (i == data.si - 1 || cw(p1, data[i], p2))
            {
                while (up.si >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], data[i]))
                    up.pop_back();
                up.pb(data[i]);
            }
            if (i == data.si - 1 || ccw(p1, data[i], p2))
            {
                while (down.si >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], data[i]))
                    down.pop_back();
                down.pb(data[i]);
            }
        }
        //clearing the vector
        data.clear();
        for(auto x:up)
            data.pb(x);
        for(int i=down.si-2;i>0;i--)
            data.pb(down[i]);
        p1(data.si);
        for(auto x:data)
        {
            p2(x.F,x.S);
        }
    }
    return 0;
}
