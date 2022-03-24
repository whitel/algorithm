#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
public:
    void run() {
        unordered_set<char> visited;
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        int result = 0;
        for(int i = 0; i < str.size(); ++i) {
            // 以i为起点的子串
            // visited.clear();
            for(int j = i; j < str.size(); ++j) {
                visited.insert(str[j]);
                if(visited.size() <= k) {
                    result = max(result, j - i + 1);
                } else {
                    visited.erase(str[i]);
                    break;
                }
            }
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

