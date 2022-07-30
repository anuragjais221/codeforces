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
        void answer()
        {
            ll n;
            cin >> n;

            ll temp = n;
            // cout << "temp = " << temp << endl;
            vector<ll>v;

            while(temp > 0){

                ll r = temp % 10;
                
                v.push_back(r);

                temp = temp /10;
            }

            // for(ll i = 0; i < v.size();i++){
            //     cout << v[i] << " ";
            // }
            // cout << endl;

            ll mini = *min_element(v.begin(),v.end());

            // cout << "mini = "<< mini << endl;


            if( v.size() == 2){
                cout << v[0] << endl;
            }
            else{
                cout << mini << endl;
            //     if( (v.size() % 2) == 1){
            //     cout << mini << endl;
            // }
            // else{   
                

            //     ll count = 0;
            //     // cout << "size even" << endl;

            //     for(ll i = 0; i < v.size();i++){
            //         if( mini == v[i]){
            //             count++;
            //         }
            //     }

            //     if( count == 1 ){
            //         // find second minimum
            //         ll second_mini = INT_MAX;
            //         // cout << "second_mini = " << second_mini << endl;
            //         for( ll i = 0 ; i < v.size();i++){
            //             if(v[i] != mini && v[i] < second_mini){
            //                 second_mini = v[i];
            //                 // cout << "second_mini = " << second_mini << endl;
            //             }
                            
            //         }
            //         cout << second_mini << endl;
            //     }
            //     else{
                    
            //         cout << mini << endl;
            //     }
            // }
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