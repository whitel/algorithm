#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
public:
    void run() {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; ++i)
            cin >> nums[i];
        int leftSum = 0;
        int midSum = 0;
        int rightSum = 0;
        vector<int> result;
        for(int left = 0; left < n - 1; ++left) {
            leftSum = getSum(nums, 0, left);
            for(int right = left + 1; right < n - 1; ++right) {
                midSum = getSum(nums, left + 1, right);
                rightSum = getSum(nums, right + 1, n - 1);
                result.push_back(max(max(leftSum, midSum), rightSum));
            }
        }
        int minResult = INT_MAX;
        for(int i = 0; i < result.size(); ++i) {
            minResult = min(minResult, result[i]);
        }
        cout << minResult << endl;
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

