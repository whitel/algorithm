#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
public:
    void run() {
        int T;
        cin >> T;
        while(T--) {
            int n;
            cin >> n;
            vector<int> nums(n);
            for(int i = 0; i < n; ++i) 
                cin >> nums[i];
            sort(nums.begin(), nums.end());
            int result = INT_MAX;
            for(int i = 1; i < n; ++i) {
                result = min(result, nums[i] - nums[i - 1]);
            }
            cout << result << endl;
        }

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

