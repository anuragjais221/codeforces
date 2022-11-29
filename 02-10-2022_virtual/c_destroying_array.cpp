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

ll parent[100005];
ll sizee[100005];
ll rankk[100005];
ll sum[100005];
ll visited[100005];

void makeset(ll n)
{
    for (ll i = 0; i < n + 1; i++)
    {
        parent[i] = i;
        sizee[i] = 1LL;
        rankk[i] = 0;
        visited[i] = 0;
        sum[i] = 0;
        // sum[i] = INT_MAX;
    }
}

ll findPar(ll node)
{
    if (node == parent[node])
        return node;
    return parent[node] = findPar(parent[node]);
}

void unionn(ll a, ll b)
{
    a = findPar(a);
    b = findPar(b);
    parent[b] = a;
    sizee[a] += sizee[b];
}

void answer()
{
    ll n;
    cin >> n;
    vector<ll> a(n, 0), d(n, 0);
    vector<ll> visited(n + 1, 0);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> d[i];
    vector<ll> ans;
    ans.push_back(0);
    makeset(n);
    ll maxi = LONG_LONG_MIN;
    for (ll i = n - 1; i > 0; i--)
    {
        if (i == n - 1)
        {
            visited[d[i]] = 1;
            sum[d[i]] = a[d[i] - 1];
            maxi = max(maxi, sum[d[i]]);
            ans.push_back(maxi);
        }
        else
        {
            visited[d[i]] = 1;
            sum[d[i]] = a[d[i] - 1];
            if (d[i] < n && visited[d[i] + 1] == 1)
            {
                // merging required
                ll p = findPar(d[i] + 1);
                // cout << "d[i] = " << d[i] << " d[i]+1 = " << d[i] + 1 << " p = " << p << endl;
                unionn(d[i], d[i] + 1);
                sum[d[i]] += sum[p];
            }
            if (d[i] > 0 && visited[d[i] - 1] == 1)
            {
                // merging required
                ll p = findPar(d[i] - 1);
                // cout << "d[i] = " << d[i] << " d[i]-1 = " << d[i] - 1 << " p = " << p << endl;
                unionn(d[i], d[i] - 1);
                sum[d[i]] += sum[p];
            }

            maxi = max(sum[d[i]], maxi);
            ans.push_back(maxi);
        }
    }
    reverse(ans.begin(), ans.end());
    // for (auto x : sum)
    //     cout << x << " ";
    // cout << endl;
    for (auto x : ans)
        cout << x << endl;
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

    // ll t;
    // cin >> t;
    // while (t--)
    answer();
}