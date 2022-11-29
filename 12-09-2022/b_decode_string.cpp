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
    string s;
    cin >> s;
    string ans;
    map<int,char> m;

    for(char i = 1; i < 27; i++)
    {
        if( i == 1)  m[i] = 'a';
        else m[i] = m[i-1]+1;    
        // m[i] = i+'a';        
    }

    map<char,int> mm;
    mm['1'] = 1;
    mm['2'] = 2;
    mm['3'] = 3;
    mm['4'] = 4;
    mm['5'] = 5;
    mm['6'] = 6;
    mm['7'] = 7;
    mm['8'] = 8;
    mm['9'] = 9;

    // map<int,char>::iterator itr;
    // for(itr = m.begin();itr!= m.end();itr++){
    //     cout << itr->first << " " << itr->second << endl;
    // }


    for(int i = n-1;i>=0;){

        if(s[i] == '0'){

            if( i >= 2 ){
                string tmp;
                tmp.push_back(s[i-2]);
                tmp.push_back(s[i-1]);
                ans.push_back(m[stoi(tmp)]);
                i = i-3;
            }
            
        }
        else{
            // cout << s[i] << endl;
            // cout << (int)s[i]+0 << endl;
            ans.push_back(m[mm[s[i]]]);
            i--;
        }
    }
    reverse(ans.begin(),ans.end()); 

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