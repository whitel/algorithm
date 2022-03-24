#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
public:
    void run() {
        long long x;
        cin >> x;
        vector<int> nums;
        while(x) {
            nums.push_back(x % 10);
            x /= 10;
        }
        for(int i = 0; i <= nums.size(); ++i) {
            for(int j = 0; j < 10; ++j) {
                nums.insert(nums.begin() + i, j);
                // cout << to_int(nums) << endl;
                if(to_int(nums) % 7 == 0) {
                    cout << to_int(nums) << endl;
                    return ;
                }
                nums.erase(nums.begin() + i);
            }
        }
    }

    long long to_int(vector<int> nums) {
        long long result = 0;
        for(int i = 0; i < nums.size(); ++i) {
            result += nums[i] * pow(10, i);
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

