#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
public:
    void run() {
        string str;
        cin >> str;
        int result = 0;
        for(int i = 0; i < str.size() - 1;) {
            if(str[i] == str[i + 1] || str[i] + 1 == str[i + 1]) {
                result += (str[i] - 'a') + (str[i + 1] - 'a') + 2;
                i += 2;
            }
            else {
                i++;
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

