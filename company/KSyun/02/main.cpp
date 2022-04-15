#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
public:
    void run() {
        int x, d, n;
        cin >> x >> d >> n;
        _Float64 a = 1.0 / x;
        string b = to_string(a);
        string result;
        for(auto i = b.begin() + d + 1; i < b.begin() + d + n + 1; ++i) {
            result += *i;
        }
        cout << result << endl;
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

