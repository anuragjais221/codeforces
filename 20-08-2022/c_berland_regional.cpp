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
    ll n;
    cin >> n;
    vector<ll> u(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> u[i];
    vector<ll> s(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> s[i];

    map<ll, vector<ll>> us;
    multimap<ll,vector<ll>> uss;

    for (ll i = 0; i < n; i++)
    {
        us[u[i]].push_back(s[i]);
    }

    // for(auto x: us){
    //     print_1d_vector(x.second);
    // }
    for (auto &x : us)
    {
        sort(x.second.begin(), x.second.end());
    }
    
    



    for (auto &x : us)
    {
        for (ll i = 1; i < x.second.size(); i++)
        {
            x.second[i] = x.second[i] + x.second[i - 1];
        }
    }

    for(auto &x : us){
        uss.insert({x.second.size()*(-1LL),x.second});
    }

    // for (auto x : uss)
    // {
    //     cout << x.first << " : " << endl;
    //     print_1d_vector(x.second);
    // }

    vector<ll> ans(n, 0);

    

    for (ll k = 0; k < n; k++)
    {

        if (k == 0)
        {

            for (auto &xx : uss)
            {
                // if( xx.first < k ){
                    
                    ans[k] += xx.second[xx.second.size() - 1];
                // }
              
            }
        }

        else
        {
            for (auto &xx : uss)
            {

                if( k < xx.first*(-1LL) ){
                    ll size = xx.second.size();
                    ll leave = size % (k + 1);
                    if (leave == 0)
                    {
                        ans[k] += xx.second[size - 1];
                    }
                    else
                    {
                        ans[k] += xx.second[size - 1] - xx.second[leave - 1];
                    }
                }
                else{ break; }
                
            }
        }
    }

    print_1d_vector(ans);
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