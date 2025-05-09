#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int diff_bits(int a, int b) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if (((a >> i) & 1) != ((b >> i) & 1)) {
            count++;
        }
    }
    return count;
}
int countSetBits(int n){
    if (n == 0)
        return 0;
    else
        return (n & 1) + countSetBits(n >> 1);
}
int getFirstSetBit(int n) {
    if (n == 0) return 0;
    int res = n & (~n + 1);
    return log2(res) + 1;
}

int logb(ll a, ll b){
    return log2(b) / log2(a);
}

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