#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &nums, int left, int right) {
        if(left < right) {
            int privotLoc = partition(nums, left, right);
            quickSort(nums, left, privotLoc);
            quickSort(nums, privotLoc + 1, right);
        }
    }

    int partition(vector<int> &nums, int left, int right) {
        int privotKey = nums[left];
        while(left < right) {
            while(left < right && nums[right] >= privotKey) right--;
            swap(nums[left], nums[right]);
            while(left < right && nums[left] <= privotKey) left++;
            swap(nums[left], nums[right]);
        }
        return left;
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
