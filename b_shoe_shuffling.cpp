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
// print 1d vector //
void print_1d_vector(vector<ll> v)
{
    for (ll i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

ll pair_exist(vector<ll> &v, ll x, ll low, ll high)
{

    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (v[mid] == x)
        {
            return mid;
        }
        else if (v[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
void answer()
{
    ll n;
    cin >> n;

    vector<ll> v(n, 0);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    map<ll,ll> m;
    for(ll i =0; i < n; i++){
        if(m.find(v[i]) != m.end()){
            m[v[i]]++;
        }
        else{
            m.insert(make_pair(v[i],1));
        }
    }

    for( auto i : m){
        if(i.second < 2){
            cout << -1 << endl;
            return;
        }
    }

    vector<ll> ans(n,0);

    for(ll i = 0; i < n; i++){
        ans[i] = i+1;
    }

    ll l = 0;
    ll r = 0;
    bool flag = true;
    while( r < n){
        while( r < n-1 && v[r] == v[r+1]){
            ++r;
        }

        if( l == r ) flag = false;

        else { 
            // rotate(ans.begin()+l,ans.begin()+r, ans.begin()+r+1 );

            ll temp = ans[r];
            // cout << "n = " << n << endl;
            // cout << "temp = " << temp << endl;

            // cout << "l = " << l << endl;
            // cout << "r = " << r << endl;
            // print_1d_vector(ans);

            for( ll i = r-1; i >= l ; i--){

                // if( i == l){
                //     ans[i] = temp;
                // }
                // else{
                    ans[i+1] = ans[i];
                // }
                
            }
            ans[l] = temp;
            // print_1d_vector(ans);
        }

        l = r+1;
        ++r;
        
    }

    if( flag ){

        print_1d_vector(ans);
    }
    else{
        cout << -1 << endl;
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