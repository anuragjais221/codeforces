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
// print 1d vector //
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
    cin >> n>> m;
    vector<ll> a(n,0);
    for(ll i = 0; i < n ; i++){
        cin >> a[i];
    }

    ll k;
    cin >> k;
    vector<ll> b(k,0);
    for(ll i = 0; i < k;i++){
        cin >> b[i];
    }

    vector<ll>c_a(n,1);
    vector<ll> c_b(k,1);
    for(ll i = 0; i < n; i++){
        while(a[i] % m == 0){
            a[i] = a[i] / m;
            c_a[i] = c_a[i] * m;
        }
    }
    for(ll i = 0; i < k; i++){
        while(b[i] % m == 0){
            b[i] = b[i] / m;
            c_b[i] = c_b[i] * m;
        }
    }

    ll i = 0, j = 0;

    while(true){

        if( i >= n && j >= k ) { cout << "yes" << endl; return; }

        if( i >= n || j >= k) { cout << "no" << endl; return; }

        if( a[i] != b[j] ) { cout << "no" << endl; return; }

        ll mini = min(c_a[i],c_b[j]);

        c_a[i] -= mini;
        c_b[j] -= mini;

        if( c_a[i] == 0 ) i++;
        if( c_b[j] == 0 ) j++;

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