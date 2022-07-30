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
        cout << v[i];
    }
    cout << endl;
}


// bool is_possible(string s, vector<pair<ll,ll>> p,vector<string> v, ll i, ll j,ll n){
//     ll t = s.size();
//     // cout << "t = "<< t << endl;
//     // ll i = 0;
//     // ll j = n-1;
//     // cout << "j = " << j << endl;
//     while( i <= j){
        
//         ll sum = p[i].first + p[j].first;

//         if( sum == t){

//             string ss1 =  v[p[i].second] + v[p[j].second] ;
//             string ss2 = v[p[j].second] + v[p[i].second];

//             if( s.compare(ss1) == 0 || s.compare(ss2) == 0 ){
//                 return true;
//             }
//             else{

//                 if( ( i != n-1 &&  p[i].first == p[i+1].first ) && ( j != 0 && p[j].first == p[j-1].first)){


//                     return ( is_possible(s,p,v,i+1,j,n) || is_possible(s,p,v,i,j-1,n)) ;
//                 }  
//                 else if( ( i != n-1 &&  p[i].first == p[i+1].first ) ){
//                     i++;
//                 }
//                 else if( j != 0 && p[j].first == p[j-1].first){
//                     j--;
//                 }
//                 else{
//                     i++;
//                     j--;
//                 }
//             }
//             // else{
//             //     return false;
//             // }
//         }
//         else if(sum > t){
//             j--;
//         }
//         else{
//             i++;
//         }
//     }

//     return false;
// }
void answer()
{
    ll n;
    cin >> n;
    vector<string> v;
    map<string,ll> m;   

    vector<pair<ll,ll>> p;
    for(ll i = 0; i < n; i++){
        string s;
        cin >> s;
        v.push_back(s);
        // p.push_back(make_pair(s.size(),i));
        if( m.find(s) == m.end()){
            m.insert(make_pair(s,1));
        }
        else{
            m[s]++;
        }
    }
    vector<ll> ans;

    for( ll i = 0; i < n;i++){
        bool flag = false;
        for( ll j = 0; j < v[i].size();j++){

            string ss1 = v[i].substr(0,j);
            string ss2 = v[i].substr(j,v[i].size()-j);

            if( m.find(ss1) != m.end() && m.find(ss2) != m.end() ){
                ans.push_back(1);
                flag = true;
                break;
            }
            else{

            }
        }

        if( flag == false){
            ans.push_back(0);
        }
    }

    // for(ll i = 0; i < n; i++){
    //     cout << p[i].first << " " << p[i].second;
    // }
    // cout << endl;
    

   

    
    // cout << "here << " << is_possible("forces",p,v);
    

    // for(ll r = 0; r < n; r++){

    //     if( is_possible(v[r],p,v,0,n-1,n)){
    //         ans.push_back(1);
    //     }
    //     else{
    //         ans.push_back(0);
    //     }
    // }

    print_1d_vector(ans);
    
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