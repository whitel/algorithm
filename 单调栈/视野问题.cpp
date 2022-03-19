#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> run(vector<int>& nums) {
        // core code here
        vector<int> result(nums.size());
        nums.push_back(INT_MAX);
        stack<int> st;
        for(int i = 0; i < nums.size(); i++) {
            if(st.empty() || nums[i] < nums[st.top()])
                st.push(i);
            else {
                while(!st.empty() && nums[i] >= nums[st.top()]) {
                    result[st.top()] = i - st.top() - 1;
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    // input here
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> result = s.run(nums);

    for(int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
