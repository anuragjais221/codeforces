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
    vector<ll> a(n,0);
    vector<ll> b(n,0);

    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];

    vector<ll> dmin(n,0);
    vector<ll> dmax(n,0);

    if( a[n-1] <= b[0]){
        for(ll i = 0;i < n;i++){
            dmin[i] = b[0] - a[i];
            dmax[i] = b[n-1]-a[i];
        }
    }
    // else if(a[n-1] == b[0]){


    // }
    else{

        ll i = 0;
        ll j = 0;   
        while( i < n && j < n ){
            if( a[i] <= b[j]){
                dmin[i] = b[j]-a[i];
                // cout << "i = " << i << endl;
                i++;
            }
            else{
                j++;
                // i++;
            }
        }
        // for(ll i = 0; i < n; i++){
        //     ll index = lower_bound(b.begin(),b.end(),a[i])-b.begin();  
        //     dmin[i] = b[index] - a[i];
        // }

        


        j = n-1;
        dmax[n-1] = b[n-1]-a[n-1];
        for(ll i = n-2; i >= 0;i--){
            if(a[i+1]<=b[i]){
                dmax[i] = b[j]-a[i];
            }
            else{
                dmax[i] = b[i]-a[i];
                j=i;
            }
        }

        // while( a[i] > b[0]){
        //     dmax[i] = b[i] - a[i];
        //     i--;
        // }

        // for(ll j = 0;j < i+1 ;j++){
        //     // dmin[j] = b[0] - a[j];
        //     dmax[j] = b[i]-a[j]; 
        // }

    }

    print_1d_vector(dmin);
    print_1d_vector(dmax);
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