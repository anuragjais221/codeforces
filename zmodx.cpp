#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
#define MOD 1000000007
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mpll map<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vi vector<int>
#define vl vector<long long>
#define pqll priority_queue<ll>
#define ALL(t) t.begin(), t.end()
#define ALLR(t) t.rbegin(), t.rend()
#define fi first
#define se second
#define endl "\n"
#define precise(ans) cout << fixed << setprecision(15) << ans
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for (int i = (b)-1; i >= (a); --i)
///// Prime factor list////
vector<int> factors(int n)
{
    vector<int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
}
// power x^y//
ll power(ll x, ll y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res % MOD * x % MOD;
        y = y >> 1;
        x = x % MOD * x % MOD;
    }
    return res;
}
/// Palindrome Check///
bool palindrome(const string &s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}
void answer()
{
    ll a,b,c;
    cin >> a >> b >> c;

    ll x,y,z; 
    bool flag = false;
    for( ll q1 = 0; q1 < 10 ; q1++ ){
        for( ll q2 = 0; q2 < 10 ; q2++ ){
            for( ll q3 = 0; q3 < 10 ; q3++ ){
                x = (a + q1 * b + q1*q1*c)/(1-(q1*q2*q3));
                z = c + q3 * x;
                y = b + q2 *z;

                // cout << "x = " << x << " y = "<< y << "z = "<< z << endl;
                if( x%y == a && y%z == b && z%x == c){
                    flag = true;
                    cout << x << " " << y << " " << z << endl;
                    break;
                }
            }

            if( flag ){
                break;
            }
        }
        if( flag ){
            break;
        }
    }
    if( flag == false ){
        cout << "not able to find " << endl;
    }
    
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
        answer();
}