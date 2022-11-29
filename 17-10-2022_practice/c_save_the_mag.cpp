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

int prev_notSwap = 0;
int prev_swap = 0;
int f(int index,int n, string &s,vector<int>&cost){


    // cout << "index = " << index << " s = " << s << endl;
    if(index == n) return 0;
    int notSwap = 0;
    int swap = 0;

    if( index == 0 ){
        if(s[index] == '1') {
            notSwap = cost[index]+f(index+1,n,s,cost);
            swap=0;
        }
        else{
            notSwap =  f(index+1,n,s,cost);
            swap =  f(index+1,n,s,cost);
        }
    }
    else if( s[index] == '1') {
        notSwap = cost[index] + f(index+1,n,s,cost);
        if(s[index-1] == '0'){
            string str = s;
            str[index] = '0';
            str[index-1] = '1';
            swap = cost[index-1] + f(index+1,n,str,cost); 
        }
    }
    else{
        notSwap =  f(index+1,n,s,cost);
        swap =  f(index+1,n,s,cost);
    }
    cout << "index = " << index << " swap = " << swap << endl;
    cout << "index = " << index << " notSwap = " << notSwap << endl;
    cout << "max = " << max(swap,notSwap) << endl;
    return max(swap,notSwap);
}

int f(int index,int n, string &s,vector<int>&cost,vector<int>&dp){


    cout << "index = " << index << " s = " << s << endl;
    if(index == n) return 0;

    if( dp[index] != -1 ) return dp[index];
    int notSwap = 0;
    int swap = 0;

    if( index == 0 ){
        if(s[index] == '1') {
            notSwap = cost[index]+f(index+1,n,s,cost,dp);
            swap=0;
        }
        else{
            notSwap =  f(index+1,n,s,cost,dp);
            swap =  f(index+1,n,s,cost,dp);
        }

    }
    else if( s[index] == '1') {
        notSwap = cost[index] + f(index+1,n,s,cost,dp);
        if(s[index-1] == '0'){
            string str = s;
            str[index] = '0';
            str[index-1] = '1';
            swap = cost[index-1] + f(index+1,n,str,cost,dp); 
        }
    }
    else{
        notSwap =  f(index+1,n,s,cost,dp);
        swap =  f(index+1,n,s,cost,dp);
    }
    cout << "index = " << index << " swap = " << swap << endl;
    cout << "index = " << index << " notSwap = " << notSwap << endl;
    cout << "max = " << max(swap,notSwap) << endl;
    return dp[index] =  max(swap,notSwap);
}
void answer()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>cost(n,0);
    for(int i =0; i < n;i++) cin >> cost[i];

    // int c = 0;
    // vector<int>dp(n,-1);

    // // cout << "s = " << s << endl;

    // int ans = f(0,n,s,cost);
    // cout << "ans = " << ans << endl;
    // f(0,n,s,cost,dp);

    // for(auto x: dp) cout << x << " ";
    // cout << endl;
    // cout << ans << endl;
    int tot = 0;

    // if(s[0] == '1') tot += cost[0];
    for(int i = 0; i < n;){
        if( s[i] == '1'){
            tot += cost[i];
        }
        if(s[i] == '0' && s[i+1] == '1'){
            int j = i+1;
            int mini = 1e9;
            int pos = -1;
            while( j < n && s[j] == '1') {
                tot += cost[j];
                if(cost[j] <= mini){
                    mini = cost[j];
                    pos = j;
                }
                j++;
            }
            if( cost[i] >= mini ){
                tot = tot-mini+cost[i];
               
                s[pos] = '0';
            }
            i = j;
        }
        
        else i++;
    }

    cout << tot << endl;
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

