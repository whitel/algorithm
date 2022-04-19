#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
public:
    void run() {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        int result = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                result += getZero(nums, i, j);
            }
        }
        cout << result << endl;
    }

    int getZero(vector<int> &nums, int left, int right) {
        int multi = 1;
        for(int i = left; i <= right; ++i) {
            multi *= nums[i];
        }
        int result = 0;
        while(multi != 0) {
            if(multi % 10 == 0) {
                result++;
                multi /= 10;
            }
            else
                break;
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

