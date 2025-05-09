#include <bits/stdc++.h>
using namespace std;

void solve(){
    int l,r;
    cin >> l >> r;
    map<int, int> al;
    int ans = 1e9;
    for(int i =l ;i <= r;i ++){
        for (int j =0 ;j < 18;j ++){
            if (!((1 << j) & i)){
                al[j] ++;
            }
        }
    }
    for (int i =0;i < 18;i ++){
        ans = min(ans, al[i]);
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}