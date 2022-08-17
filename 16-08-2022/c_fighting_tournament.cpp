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
    ll n, q;
    cin >> n >> q;

    vector<ll> strength(n + 1, 0);
    map<ll,ll> wins;
    for(ll i = 1 ; i <= n;i++) wins[i] = 0;
    for (ll i = 1; i < n + 1; i++)
        cin >> strength[i];
    ll max_strength_player = max_element(strength.begin(), strength.end()) - strength.begin();
    // cout << "max_player = " << max_strength_player << endl;
    vector<ll> rounds;
    ll winner, looser;
    if (strength[1] > strength[2])
    {
        winner = 1;
        looser = 2;
    }
    else
    {
        winner = 2;
        looser = 1;
    }
    rounds.push_back(winner);
    wins[winner]++;
    for (ll i = 3; i < n + 1; i++)
    {
        if (strength[winner] == strength[max_strength_player])
        {
            break;
        }
        if (strength[i] > strength[winner])
        {
            looser = winner;
            winner = i;
        }
        rounds.push_back(winner);
        wins[winner]++;
    }
    // cout << "rounds : ";
    // print_1d_vector(rounds);
    for (ll i = 0; i < q; i++)
    {
        ll I, k;
        cin >> I >> k;
        // cout << "I = " << I << endl;
        // cout << "K = " << k << endl;

        if (I > max_strength_player)
        {
            cout << 0 << endl;
            // return;
        }
        // else if(){

        // }
        else
        {
            ll cnt = 0;
            if (k <= rounds.size())
            {

                // for (ll i = 0; i < k; i++)
                // {
                //     if (rounds[i] == I)
                //         cnt++;
                // }
                cout << min(wins[I], max(0LL,k-max(I-2,0LL))) << endl;
                // cout << cnt << endl;
            }
            else
            {
                // for (ll i = 0; i < rounds.size(); i++)
                // {
                //     if (rounds[i] == I)
                //         cnt++;
                // }
                cnt = wins[I];
                if (I == max_strength_player)
                {
                    cnt += k - rounds.size();
                }

                cout << cnt << endl;
            }
        }
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