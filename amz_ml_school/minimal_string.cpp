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
void answer()
{

    string s;
    cin >> s;

    vector<char> ch(1e5+10);

    
    stack<char> st;
    vector<char> ans;
    ll n = s.length();

    for(ll i = n-1 ; i >= 0 ;i--){
        if( i == n-1  ) ch[i] = s[i];
        else ch[i] = min(ch[i+1],s[i]);
    }

    // for( ll i = 0 ; i < n; i++){
    //     cout << ch[i];
    // }
    // cout << endl;
    // for(ll i = 0; i < n ; i++){
    //     if( s[i] > mini[i] ){
    //         st.push(s[i]);
    //     }
    //     else{
    //         ans.push_back(s[i]);
    //     }
    // }


    // while(!st.empty()){
    //     ans.push_back(st.top());
    //     st.pop();
    // }
    // cout << "ans = ";
    string t;
    string temp;
    // cout << temp.back() << endl;
    int cur = 0;
    ll i = 0;

    while(  ans.size() < n ){
        // cout << "i = " << i  << endl;
        if( st.empty() || (i < n && (ch[i] < st.top()))){
            while( s[i] != ch[i] ){
                st.push(s[i]);
                i++;
            }
            ans.push_back(s[i++]);
        }
        else{
            ans.push_back(st.top());
            st.pop();
        }
        
    }

    
    // while (t.size() < n) {
    //     if (temp.empty() || (cur < n && ch[cur] < temp.back())) {
    //         while (s[cur] != ch[cur]) temp.push_back(s[cur++]);
    //         t.push_back(s[cur++]);
    //     }
    //     else {
    //         t += temp.back();
    //         temp.pop_back();
    //     }
    // }


    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i];
    }
    cout << endl;
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