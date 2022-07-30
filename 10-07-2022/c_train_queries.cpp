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
void answer()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // map<int, vector<int>> m;

    map<ll,ll> start,end;

    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (start.find(v[i]) == start.end())
        {
            start.insert(make_pair(v[i],i));
        }
        // else{
        if(end.find(v[i]) == end.end()){
            end.insert(make_pair(v[i],i));
        }
        else{
            end[v[i]] = i;
        }
        // }
    }
    
    // map<ll,ll>:: iterator itr;

    // for(itr = start.begin(); itr != start.end(); itr++){
    //     cout << itr->first << " : " << itr->second << endl;
    // }
    // for(itr = end.begin(); itr != end.end(); itr++){
    //     cout << itr->first << " : " << itr->second << endl;
    // }

    for (ll j = 0; j < k; j++)
    {
        ll a, b;
        cin >> a >> b;

        if ((start.find(a) == start.end()) || start.find(b) == start.end())
        {
            cout << "no" << endl;
            // return;
        }
        else
        {

            // vector<int> x = m[a];
            // vector<int> y = m[b];

            if( start[a] <= end[b]){    
                cout << "yes" << endl;
            }
            else{
                cout << "no" << endl;
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