#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
public:
    void run() {
        int n;
        cin >> n;
        vector<string> strs;
        for(int i = 0; i < n; ++i) {
            string temp;
            cin >> temp;
            strs.push_back(temp);
        }
        vector<int> result;
        for(int i = 0; i < strs[0].size(); ++i) {
            string temp;
            for(int j = 0; j < n; ++j) {
                temp += strs[j][i];
            }
            result.push_back(to_number(temp));
        }
        sort(result.begin(), result.end());
        for(int x : result)
            cout << x << " ";
        cout << endl;
    }

    int to_number(string str) {
        int result = 0;
        int base = 1;
        for(int i = str.size() - 1; i >= 0; --i) {
            result += (str[i] - '0') * base;
            base *= 10;
        }
        return result;
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

