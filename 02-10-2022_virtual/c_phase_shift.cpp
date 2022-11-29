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

int parent[100000];
int rankk[100000];
int siz[100000];

void makeset(){
    for(int i = 0; i < 26;i++){
        parent[i] = i;
        rankk[i] = 0;
        siz[i] = 1;
    }
}

int find(int node){
    if(node == parent[node]) return node;
    return parent[node] = find(parent[node]);
}

void unionn(int a,int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
    siz[b] += siz[a];
}

void answer()
{
    ll n;
    cin >> n;
    string t;
    cin >> t;
    makeset();
    map<char,int> m;
    vector<bool>visited(n,false);
    // map<char, bool> visited;
    string ans;
    char c = 'a';
    for(int i = 0; i < n;i++){
        
        if( m.find(t[i]) != m.end() ){
            ans.push_back(m[t[i]]+'a');
        }
        else{

            int root = find(c-'a'); // a

            if( siz[root] == 26  ){
                m[t[i]] = c-'a';
                unionn(t[i]-'a' , c-'a');
                ans.push_back(c);
                c++;
            }
            else{

                char lst_ch = c;

                while( find(c-'a') == find(t[i]-'a') || visited[c-'a'] && c <='z' ){
                    c++;
                }
                m[t[i]] = c-'a';
                ans.push_back(c);
                unionn(t[i]-'a',c-'a');
                visited[c-'a'] = true;
                c = lst_ch;
                while(visited[c-'a'] && c <='z') c++;
                
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