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
bool is_safe(pair<ll,ll>p1, int n,int m){
    if( p1.first > 0 && p1.first <= n && p1.second > 0 && p1.second <= m ) return true;
    return false;
}
void answer()
{
    ll n,m,lx,ly,d;
    cin >> n >> m >> lx >> ly >> d;
    // vector<ll> px {-1,1,0,0};
    // vector<ll> py {0,0,1,-1};
    // vector<vector<ll>> visited(n+1,vector<ll>(m+1,0));
    // queue<pair<pair<ll,ll>,ll>>q;
    // q.push({{1,1}, 0});
   
    // ll ans = -1;
    // while(!q.empty()){
    //     auto p = q.front();
    //     q.pop();
    //     visited[p.first.first][p.first.second] = 1LL;
    //     // cout << p.first.first << "," << p.first.second << endl;  
    //     if( p.first.first == n && p.first.second == m) { ans = p.second; break; }
    //     for(int i = 0; i < 4; i++){
    //         ll nx = p.first.first + px[i];
    //         ll ny = p.first.second + py[i];
    //         if( is_safe({nx,ny},n,m) && visited[nx][ny] == 0LL && (abs(nx - lx) + abs(ny - ly)) > d ){
    //             q.push({{nx,ny}, p.second+1});
    //         }
    //     }
    // }

    // cout << ans << endl;

    if((lx+d > n-1 && lx-d < 2 ) || (ly+d > m-1 && ly-d < 2) ){
        cout << -1 << endl;
    }
    else if(lx-d < 2 && ly - d < 2 ){
        cout << -1 << endl;
    }
    else if(lx+d > n-1 && ly+d > m-1){
        cout << -1 << endl;
    }
    else{
        cout << n+m-2 << endl;
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