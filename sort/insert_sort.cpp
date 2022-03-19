#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        insertSort(nums);
        return nums;
    }

    void insertSort(vector<int> &nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            // 若第i-1个元素小于第i个元素，直接插入
            if(nums[i-1] < nums[i])
                continue;
            // 否则移动前面排好序的元素，插入到正确位置
            if(nums[i-1] > nums[i]) {
                int j = i - 1;
                int x = nums[i];
                nums[i] = nums[i-1];
                while(x < nums[j]) {
                    nums[j+1] = nums[j];
                    j--;
                }
                nums[j+1] = x;
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
