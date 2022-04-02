#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
public:
    void run() {
        int n, r, b;
        cin >> n >> r >> b;
        string str;
        cin >> str;
        char prev = str[0];
        int resultRed = 0;
        int resultBlack = 0;
        for(int i = 1; i < n; ++i) {
            if(prev == str[i]) {
                if(str[i] == 'r') resultRed++;
                if(str[i] == 'b') resultBlack++;
            }
            prev = str[i];
        }
        // cout << resultRed << " " << resultBlack << endl;
        if(resultRed <= r && resultBlack <= b) {
            cout << n + resultRed + resultBlack << endl;
            return ;
        }
        int A = max(resultRed - r, 0);
        int B = max(resultBlack - b, 0);
        cout << A << " " << B << endl;
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

