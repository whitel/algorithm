#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        selectSort(nums);
        return nums;
    }

    void selectSort(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            // 获取后面数组最小的那个元素的下标k
            int k = i;
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[k] > nums[j])
                    k = j;
            }
            // 防止与自己交换
            if(k != i) {
                // 把后面无序部分的最小值放到当前位置
                swap(nums[k], nums[i]);
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
