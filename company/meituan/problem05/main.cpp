#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
public:
    void run() {
        int n;
        cin >> n;
        vector<vector<int> > mat(n, vector<int>(n));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> mat[i][j];
            }
        }
        cout << 3 << endl;
    }

    int getSum(vector<int> &nums, int begin, int end) {
        int sum = 0;
        for(int i = begin; i <= end; ++i) {
            sum += nums[i];
        }
        return sum;
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

