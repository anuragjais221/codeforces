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
    vector<vector<char>> board(8,vector<char>(8,'.'));

    for(ll i =0; i < 8; i++){
        for(ll j = 0; j < 8;j++){
            cin >> board[i][j];
        }
    }
    ll i = 0;
    ll j =0;
    bool flag = false;
    for( i = 1; i < 7 ; i++){
        for( j = 1; j < 7; j++){

            if(board[i][j] == '#' && board[i+1][j+1] == '#' && board[i-1][j+1] == '#' && board[i-1][j-1] == '#' && board[i+1][j-1] == '#'){
                cout << i+1 << " " << j+1 << endl;
                flag = true;
                break;
            }
        }
        if( flag ) break;
    }

    // for(i = 0 ; i < 8 ; i++){
    //     ll count = 0;
    //     for( j = 0 ; j < 8; j++){
    //         if( board[j][i] == '#') count++;
    //     }

    //     if( count == 1 && i != 0 && i != 7){

    //         for ( ll k = 1; k < 7; k++){
    //             if( board[k][i] == '#' ){
    //                 cout << k+1 << " " << i+1 << endl;
    //                 break;
    //             }
    //         }

    //         break;
    //     } 
    // }
    // for( i = 0; i < 8; i++){
    //     ll count = 0;
    //     bool flag2 = false;
    //     for( j = 0; j < 8;j++){
    //         if( board[j][i] == '#') count++;
    //     }
    //     // cout << "count = " << count  << endl;
    //     if( count == 1 && i != 0 && i!= 7){
    //         // cout << i << " " << j << endl;
    //         for(ll k = 1; k < 7; k++){
    //             if( board[k][i] == '#') {
    //                 flag2 = true;
    //                 cout << k+1 << " " << i+1 << endl;
    //                 break;
    //             }
    //         }
    //     }

    //     if( flag2 ) break;
    // }


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