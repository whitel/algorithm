#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
public:
    void run() {
        int n, m;
        cin >> n >> m;
        int x, y;
        cin >> x >> y;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int temp;
                cin >> temp;
                if(x == i + 1 && y == j + 1) {
                    continue;
                } else {
                    sum += temp;
                }
            }
        }
        cout << sum + 1 << endl;
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

