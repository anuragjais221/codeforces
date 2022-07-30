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

bool is_exist(vector<ll>v,int target){

    ll i =0;
    ll j = v.size()-1;
    cout << "t = " << target << endl;
    while(i <= j){

        ll mid = (i+j)/2;

        cout << "mid = " << mid << endl;

        if( v[mid] == target && mid != i && mid != j){
            cout << "fo" << endl;
            return true;
        }
        else if( v[mid] > target ) {

            
            j = mid-1;
        }
        else{
            i = mid+1;
        }
    }
    return false;

}
void answer()
{
    ll n;
    cin >> n;
    vector<ll> v(n,0);

    for(ll i = 0; i < n;i++){
        cin >> v[i];
    }

    ll po = 0;
    ll ne = 0;
    ll z= 0;
    ll sum = 0;

    for(ll i = 0; i < n; i++){
        sum += v[i];
        if(v[i] > 0 ) po++;
        else if( v[i] < 0 ) ne++;
        else z++;
    }

    if( po == 0 && ne == 0 ) cout << "yes" << endl;
    else if( po == 1 && ne == 0 ) cout << "yes" << endl;
    else if( po == 0 && ne == 1 ) cout << "yes" << endl;
    else if( po == 1 && ne == 1 ){
        if ( sum == 0 ) cout << "yes" << endl;
        else cout << "no" << endl;
    } 
    else if( z == 0 ){

        if( po < 3 && ne < 3 ){

            bool flag = false;
            string ans = "yes";
            for(ll i = 0; i < n; i++){
                for(ll j = i+1; j < n;j++){
                    for(ll k = j+1; k < n; k++){
                        flag = false;
                        for( ll l = 0; l < n;l++){
                            if( v[i] + v[j] + v[k] == v[l] ) {
                                flag = true;
                                break;
                            } 
                        }

                        if( flag ) continue;

                        else { ans = "no" ; break; }
                    }

                    if( ans == "no" ) break;
                }

                if( ans == "no") break;
            }

            cout << ans << endl;
        }
        else{
            cout << "no" << endl;
        }
    } 
    else cout << "no" << endl;

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