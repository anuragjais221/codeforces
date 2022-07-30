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

void build(ll node,ll start,ll end,vector<ll> &v,vector<ll> & segtree){

    if( start == end ){
        segtree[node] = v[start];
    }
    else{
        ll mid = (start + end )/2;
        int left = 2 * node;
        int right = 2 * node + 1;
        build(left,start,mid,v,segtree);
        build(right,mid + 1, end, v,segtree );
        segtree[node] = max(segtree[left],segtree[right]);
    }
}

ll query(ll node,ll strt, ll end, ll l,ll r,vector<ll> & segtree){

    if( end < l || r < strt ){
        return LONG_LONG_MIN;
    }
    if( strt == end ) {
        return segtree[node];
    }
    else if(l <= strt && end <= r){
        return segtree[node];
    }
    else{
        ll mid = ( strt + end ) /2;
        ll left = query(node * 2, strt,mid,l, r ,segtree);
        ll right = query(node * 2 + 1,mid + 1, end, l ,r, segtree);
        return max(left,right);
    }
}
void answer()
{
    ll n,m;
    cin >> n >> m;
    ll size = 1;
    while(size < m){
        size = size*2;
    }
    vector<ll>h(size,0);
    for(ll i = 0; i < m;i++) cin >> h[i];
    vector<ll> segtree(4*size,0);
    build(1,0,size-1,h,segtree);
    // print_1d_vector(segtree);
    ll q;
    cin >> q;
    while(q--){
        ll x1,y1,x2,y2,k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        if( (x2-x1) % k || (y2-y1) % k ){
            cout << "NO" << endl;
            continue;
        }
        if( y1 > y2 ) swap(y1,y2);
        ll mx_hg = query(1,0,size-1,--y1,--y2,segtree);
        // cout << mx_hg << endl;
        ll steps = n - x1;
        x1 += (steps/k)*k;

        if( mx_hg >= x1 ){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;

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
    // cin >> t;
    // while (t--)
        answer();
}