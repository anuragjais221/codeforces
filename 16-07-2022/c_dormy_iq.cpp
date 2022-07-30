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
        cout << v[i];
    }
    cout << endl;
}

bool is_possible_to_leave(ll mid, vector<ll> v, ll n, ll q)
{

    ll i = 0;

    while (i < n && q > 0)
    {
        if (v[i] > q )
        {
            // q--;

            if (mid > 0)
            {
                // do nothing
                mid--;
            }
            else
            {
                q--;
            }
        }
        i++;
    }
    if ( i >= n)
        return true;
    else
        return false;
}
void answer()
{
    ll n, q;
    cin >> n >> q;

    vector<ll> v(n, 0);
    vector<ll> res(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll low = 0;
    ll high = n;
    ll ans = -1;
    while (low <= high)
    {

        ll mid = (low + high) >> 1;

        if (is_possible_to_leave(mid, v, n, q))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    // cout << "low = " << low << endl;
    // cout << "high = " << high << endl;
    // cout << "ans = " << ans << endl;

    if (ans == 0)
    {
        for (ll i = 0; i < n; i++)
        {
            cout << 1;
        }
        cout << endl;
    }
    else
    {
        for (ll i = 0; i < n; i++)
        {
            if (v[i] > q)
            {   
                if( ans > 0 ) ans--;

                else res[i] = 1;
                // res[i] = 0;

            }
            else{
                res[i] = 1;
            }
        }
        print_1d_vector(res);
    }

    // if( ans == 0){
    //     print_1d_vector(res);
    // }
    // else{
    //     for(ll i = 0; i < n;i++){
    //         if( ans == 0 ) break;
    //         res[i] = 0;
    //         ans--;
    //     }
    //     print_1d_vector(res);
    // }
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