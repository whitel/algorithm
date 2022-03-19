#include<bits/stdc++.h>
using namespace std;

#define MOD 100000

class Solution {
public:
    void run(long long base, int n) {
        // core code here
        long long ans = 1;
        while(n) {
            if(n & 1)
                ans = (ans * base) % MOD;
            base = (base * base) % MOD;
            n >>= 1;
        }
        cout << ans << endl;
    }

};

int main() {
    Solution s;
    // input here
    int base, n;
    cin >> base >> n;

    s.run(base, n);
    return 0;
}
