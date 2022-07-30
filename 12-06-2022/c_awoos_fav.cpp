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

bool issubsequence(string &s1, string &s2)
{
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    /*If i reaches end of s1,that mean we found all
    characters of s1 in s2,
    so s1 is subsequence of s2, else not*/
    return i == n;
}
void answer()
{
    ll n;
    cin >> n;

    // vector<char>
    string s, t;

    cin >> s >> t;
    ll s_a = 0;
    ll s_b = 0;
    ll s_c = 0;
    ll t_a = 0;
    ll t_b = 0;
    ll t_c = 0;

    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            s_a++;
        else if (s[i] == 'b')
            s_b++;
        else
            s_c++;
    }

    for (ll i = 0; i < n; i++)
    {
        if (t[i] == 'a')
            t_a++;
        else if (t[i] == 'b')
            t_b++;
        else
            t_c++;
    }

    if (s_a != t_a || s_b != t_b || s_c != t_c)
    {
        cout << "NO" << endl;
    }
    else{
        ll j = 0;
        bool flag = false;
        for(ll i = 0 ; i < n; i++){
            if(s[i] == 'b')
                continue;
            while(t[j] == 'b'){
                j++;
            }
            if(s[i] != t[j] || ( s[i] == 'a' && i > j ) || (s[i] == 'c' && i < j)  ){
                cout << "NO" << endl;
                flag = true;
                break;
            }
            j++;
        }
        if( !flag ) cout << "YES" << endl;
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