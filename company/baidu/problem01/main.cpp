#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
public:
    void run() {
        int N, M;
        cin >> N >> M;
        int result = INT_MIN;
        for(int i = 1; i <= M; ++i) {
            int temp = N * i;
            vector<int> str;
            while(temp) {
                str.push_back(temp % 10);
                temp /= 10;
            }
            int now = 0;
            for(int i = 0; i < str.size(); ++i) {
                now *= 10;
                now += str[i];
            }
            result = max(result, now);
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

