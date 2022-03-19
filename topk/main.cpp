#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> result;
public:
    vector<int> sortArray(vector<int>& nums) {
        bool flag = false;
        quickSort(nums, 0, nums.size(), 5, flag);
        return nums;
    }

    void quickSort(vector<int> &nums, int left, int right, int k, bool &flag) {
        if(flag == true) {
            return ;
        }
        if(left < right) {
            int privotLoc = partition(nums, left, right);
            if(privotLoc == k) {
                result.assign(nums.begin(), nums.begin() + k);
                flag = true;
            }
            quickSort(nums, left, privotLoc, k, flag);
            quickSort(nums, privotLoc + 1, right, k, flag);
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

    void printResult() {
        for(vector<int>::iterator it = result.begin(); it != result.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
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
    s.printResult();
    return 0;
}
