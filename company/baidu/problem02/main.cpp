#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
public:
    void run() {
        int a, b;
        int T;
        cin >> T;
        while(T--) {
            int n;
            cin >> n;
            int result = 0;
            for(int i = 1; i < sqrt(n); ++i) {
                if(n % i == 0) {
                    a = i;
                    b = n / i;
                    if(gcd(a, b)) {
                        result++;
                    }
                }
            }
            cout << result << endl;
        }
    }

    bool gcd(int a, int b) {
        int n = a < b ? a : b;
        for(int i = 2; i <= n; ++i) {
            if(a % i == 0 && b % i == 0)
                return false;
        }
        return true;
    }
};

int main() {
#ifdef DEBUG
    freopen("inputdata", "r", stdin);
    cout << "===========INPUT=============" << endl;
    system("cat inputdata");
    cout << endl;
    cout << "===========OUTPUT============" << endl;
#endif

    Solution s;
    s.run();

#ifdef DEBUG
    cout << "============END==============" << endl;
#endif
    return 0;
}

