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
    ll n,c,q;   
    cin >> n >> c >> q;

    string s;
    cin >> s;

    vector<ll> first(c+1,0);
    vector<ll> last(c+1,0);
    vector<ll> diff(c+1,0);

    last[0] = n-1;

    for(ll i = 1; i < c+1;i++){

        ll l,r;
        cin >> l >> r;
        l--;
        r--;

        first[i] = last[i-1] + 1;
        last[i] = ( r-l ) + first[i]; 
        diff[i] = first[i]-l;
       
    }

    // print_1d_vector(first);
    // print_1d_vector(last);
    // print_1d_vector(diff);
    
    for(ll i = 0; i < q;i++){
        ll k;
        cin >> k;

        // cout << "k = " << k << endl; 

        k--;

        for(ll j = c;j > 0;j--){

            if( k < first[j] ) continue;

            else {
                k -= diff[j];
            }
        }

        cout << s[k] << endl;
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