#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
#define forz(i, n) for (int i = 0; i < n; i++)
#define forzm(i, m, n) for (int i = m; i < n; i++)
#define lb lower_bound
using namespace std;

lli gcd(lli x, lli y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

/*STD fucntions*/
lli power(lli x, lli y, lli p)
{
    //this is function is calculatiing power
    //lli is long long int
    lli result = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            result = (result * x) % p;
        //here is new y which should be even
        y = y >> 1; //y is now y/2
        x = (x * x) % p;
    }
    return result;
}
lli modi(lli a, lli m)
{
    // ferjhfdj's
    return power(a, m - 2, m);
}
lli lcm(lli a, lli b)
{
    //this function is calculating lcm
    return a * b / gcd(a, b);
}

/*CODE BEGINS*/

int main()
{
    // kira;
    lli n, q;
    cin >> n >> q;
    lli que[q][3];
    lli id[q];
    lli val[q] = {0};
    lli temp, flag = 0, maxuid;
    forz(i, q)
    {
        cin >> que[i][0];
        if (que[i][0] == 1)
        {
            cin >> que[i][1] >> que[i][2];
            id[i] = que[i][1];
        }
    }
    sort(id, id + q);
    forz(i, q)
    {
        if (que[i][0] == 2)
        {
            //if first code is 2
            if (flag == 0)
            //no data is available
                cout << "No data available" << endl;
            else
                cout << id[maxuid] << endl;
        }
        else
        {
            //first code is 1
            temp = lb(id, id + q, que[i][1]) - id;
            val[temp] += que[i][2];
            //storing data
            if (flag == 0)
            {
                flag = 1;
                maxuid = temp;
            }
            else if (val[temp] > val[maxuid])
            {
                maxuid = temp;
            }
        }
    }
    return 0;
}


