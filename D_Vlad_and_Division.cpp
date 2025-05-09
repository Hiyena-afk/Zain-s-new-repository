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
    const int XOR = 2147483647;
    int n;
    cin >> n;
    vector<int> a (n);
    for (int i =0;i < n;i ++) cin >> a[i];
    unordered_map<int, int> status__t;
    int ans = 0;
    for(int i =0;i < n;i ++){
        if (status__t[a[i] ^ XOR]){
            status__t[a[i] ^ XOR]--;
        }
        else{
            ans ++;
            status__t[a[i]] ++;
        }
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}