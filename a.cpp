#include<bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t,n,x;
    // int *ar;
    
    // scanf("%d",&t);
    cin >> t;
    while(t--){
        // scanf("%d",&n);
        cin >> n;
        int odd_ct = 0;
        int even_ct = 0;
        vector<int> ar(n,0);

        for(int i = 0; i < n ; i++){
            cin >> ar[i];
        }

        
        for (int i=0;i<n;i++){
            
            if (ar[i]%2 == 0)
                even_ct++;
            else
                odd_ct++;
            // ar[i] = x;
        }
        if (odd_ct < even_ct)
            cout << odd_ct << endl;
        else
            cout << even_ct << endl;
    }
    
}

