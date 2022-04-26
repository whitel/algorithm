#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
public:
    void run() {
        int n;
        cin >> n;
        string nums;
        cin >> nums;
        int left = 0;
        int right = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == '1')
                right += (i + 1);
        } 
        int result = 1e7;
        for(int i = 0; i < nums.size(); ++i) {
            result = min(result, abs(left - right));
            if(nums[i] == '0') {
                left += (i + 1);
            } else {
                right -= (i + 1);
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

