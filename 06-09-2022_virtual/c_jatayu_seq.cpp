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
void dfs(ll node, vector<bool>&visited,vector<ll>adj[]){

    visited[node] = true;
    for(auto child: adj[node]){
        if( !visited[child]){
            dfs(child,visited,adj);
        }
    }
}
void answer()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll cnt = 0;
    for(ll i =1;i < s.length();i++){
        if(s[i] == '(' && s[i-1] == '(') cnt++;
    }

    cout << cnt+1 << endl;
    // vector<ll>adj[n*2];

    // stack<pair<char,ll>>st;
    // bool flag = false;
    // for(ll i = 0; i < s.length();i++){
    //     if( s[i] == '('){

    //         if(st.empty() && i != 0){
    //             adj[0].push_back(i-1);
    //             adj[i-1].push_back(0);
    //         }
    //         st.push({s[i],i});
    //     }
    //     else{
    //         if(!st.empty()){
    //             ll v = st.top().second;
    //             adj[i].push_back(v);
    //             adj[v].push_back(i);
    //             st.pop();
    //         }
    //         else{
    //             flag = true;
    //         }
    //     }
    // }

    // if(st.empty() ) { 
    //     adj[0].push_back(n*2-1);
    //     adj[n*2-1].push_back(0);
    // }

    // for(int i = 0; i < n*2;i++){
    //     cout << i << ": " ;
    //     for(auto x : adj[i]){
    //         cout << x << ' ';
    //     }
    //     cout << endl;
    // }

    // ll cc = 0;
    // vector<bool>visited(n*2,false);

    // for(ll i = 0; i < n*2;i++){
    //     if( !visited[i] ){
    //         dfs(i,visited,adj);
    //         cc++;
    //     }
    // }

    // cout << cc << endl;
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