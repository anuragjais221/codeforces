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
void print_1d_vector(vector<ll> v)
{
    for (ll i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void answer()
{
      ll n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    vector<ll> va(n,0);
    vector<ll> vb(m,0);
    for(ll i = 0; i < n;i++){
        va[i] = a[i] == '1' ? 1 : 0;
    }
    for(ll i = 0; i < m;i++){
        vb[i] = b[i] == '1' ? 1 : 0;
    }
 
    // print_1d_vector(va);
    // print_1d_vector(vb);
    if( n < m ){
        cout << "no" << endl;
    }
    else if( n == m ) {
        if( a == b ) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    else{
        ll res1 = LONG_LONG_MAX;
        ll res2 = LONG_LONG_MIN;
        ll r = vb[0];
        ll i;
        if( r == 0){
            for( i = 0; i < n-m+1;i++){
                res1 = min(res1,va[i]);
            }
        }   
        else{
            for( i = 0; i < n-m+1;i++){
                res2 = max(res2,va[i]);
            }
        }
        // cout << "i = " << i << endl;
        string c = a.substr(i-1);
        // cout << "c = " << c << endl;
 
        if( res1 != LONG_LONG_MAX ){
            c[0] = res1 == 0 ? '0' : '1';
        }
        else{
            c[0] = res2 == 0 ? '0' : '1';
        }
        
        if( c == b ) cout << "yes" << endl;
        else cout << "no" << endl;
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