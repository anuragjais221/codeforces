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
bool is_valid(ll x,ll y, ll n,ll m){

    if( x < n && x >= 0 && y < m && y > 0){
        return true;
    }

    return false;

}
void answer()
{
    ll m;
    cin >> m;
    vector<vector<ll>> v(2,vector<ll>(m,0));
    vector<vector<ll>> visited(2,vector<ll>(m,0));
    for(ll i = 0; i < 2;i++){
        for(ll j = 0; j < m;j++){
            cin >> v[i][j];
        }
    }

    // priority_queue<tuple<ll,ll,ll>>pq;
    // priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>> > pq;

    queue<pair<ll,pair<ll,ll>>> pq;

    ll c1 = max(v[0][0], v[0][1])+1;
    ll c2 = max(v[0][0], v[1][0])+1;

    vector<ll> movex { 1, 0, -1,0};
    vector<ll> movey { 0,1,0,-1};

    pair<ll,pair<ll,ll>> p1 = {c1, {0,1}};
    pair<ll,pair<ll,ll>> p2 = { c2,{1,0}};

    pq.push(p1);
    pq.push(p2);

    visited[0][0] = 1;

    ll ans = INT_MIN;
    while(!pq.empty()){
        // pair<ll,pair<ll,ll>> p = pq.top();
        pair<ll,pair<ll,ll>> p = pq.front();
        visited[p.second.first][p.second.second] = 1;
        cout << "top cost = " << p.first << endl;
        ans = max(ans,p.first);
        pq.pop();
        for(ll i = 0; i < 4 ;i++){
            ll n_x = p.second.first+movex[i];
            ll n_y = p.second.second+movey[i];
            if( is_valid(n_x,n_y,2,m) && visited[n_x][n_y] == 0){
                ll cost = max(p.first,v[n_x][n_y]);
               
                // cout << " cost = " << cost+1 << endl;
                pq.push({ cost+1,{n_x,n_y}});
                visited[n_x][n_y] = 1;
            }
        }
    }
    
    cout << ans << endl;
    
    

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