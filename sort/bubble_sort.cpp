#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        bubble_sort(nums);
        return nums;
    }

    void bubble_sort(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums.size() - i - 1; j++) {
                if(nums[j-1] > nums[j])
                    swap(nums[j-1], nums[j]);
            }
        }
    }
};

static void printArray(vector<int> nums) {
    cout << "[";
    for(int i = 0; i < nums.size(); i++) {
        if(i != nums.size() - 1)
            cout << nums[i] << ", ";
        else
            cout << nums[i] << "]" << endl;
    }
}

int main() {
    Solution s;
    vector<int> a = {6, 4, 0, 7, 8, 5, 9, 1, 2, 3};
    printArray(a);
    s.sortArray(a);
    printArray(a);
    return 0;
}
