#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double long;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)x.size()
int diff_bits(int a, int b) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if (((a >> i) & 1) != ((b >> i) & 1)) {
            count++;
        }
    }
    return count;
}
int MSBPosition(long long int N){
    int msb_p = -1;
    while (N) {
        N = N >> 1;
        msb_p++;
    }
    return msb_p;
}
long long int findBitwiseOR(long long int L,long long int R){
  if(L==R)
    return L;
    long long int res = 0;
    int msb_p1 = MSBPosition(L);
    int msb_p2 = MSBPosition(R);
    while (msb_p1 == msb_p2) {
        long long int res_val = (1 << msb_p1);
        res += res_val;
        L -= res_val;
        R -= res_val;
        msb_p1 = MSBPosition(L);
        msb_p2 = MSBPosition(R);
    }
    msb_p1 = max(msb_p1, msb_p2);
    for (int i = msb_p1; i >= 0; i--) {
        long long int res_val = (1 << i);
        res += res_val;
    }
    return res;
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
int factorial(int n){
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

void solve(){
    string s,t;
    cin >> s >> t;
    int cnt = 0;
    int a = 0, b = 0;
    for (int i =0;i < sz(s);i ++){
        if (s[i] == '+') a++;
        else a--;
        if (t[i] == '+') b++;
        else if (t[i] == '-') b--;
        else cnt ++;
    }
    if (cnt ==0){
        if (a == b) cout << (db)1 << endl;
        else cout << (db)0 << endl;
    }
    else if (a - b > cnt) cout << (db)0 << endl;
    else if (a-b < 0) cout << (db)0 << endl;
    else{
        cout << factorial((db)(cnt))/(a - b) << endl;
    }
}
int main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}