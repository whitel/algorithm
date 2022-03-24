#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
public:
    void run() {
        string str;
        cin >> str;
        if(str.size() <= 1)
            cout << 0 << endl;
        int resultA = 0;
        int resultB = 0;
        bool flag = true;
        for(int i = 0; i < str.size(); ++i) {
            if(!flag) {
                if(str[i] == '1') {
                    resultA += (i + 1);
                }
            } else {
                if(str[i] == '0') {
                    resultA += (i + 1);
                }
            }
            flag = !flag;
        }

        flag = false;
        for(int i = 0; i < str.size(); ++i) {
            if(!flag) {
                if(str[i] == '1') {
                    resultB += (i + 1);
                }
            } else {
                if(str[i] == '0') {
                    resultB += (i + 1);
                }
            }
            flag = !flag;
        }
        int result = resultA < resultB ? resultA : resultB;
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

