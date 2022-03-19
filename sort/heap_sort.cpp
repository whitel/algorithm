#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }

    void heapSort(vector<int>& nums) {
        buildingHeap(nums, nums.size());
        for(int i = nums.size() - 1; i > 0; i--) {
            swap(nums[i], nums[0]);
            adjustHeap(nums, 0, i);
        }
    }
    
    void buildingHeap(vector<int>& nums, int length) {
        for(int i = (length - 1) / 2; i >= 0; i--) {
            adjustHeap(nums, i, length);
        }
    }

    void adjustHeap(vector<int>& nums, int s, int length) {
        int child = 2 * s + 1; // left child
        while(child < length) {
            int temp = nums[s];
            // 从左右孩子中选比较大的那个
            if(child + 1 < length && nums[child] < nums[child+1])
                child++;
            // 用比较大的那个跟父节点进行比较，把大的换上去
            if(nums[s] < nums[child]) {
                nums[s] = nums[child];
                s = child;
                child = 2 * s + 1;
            } else {
                break;
            }
            // 把原本的父节点放回大孩子的位置
            nums[s] = temp;
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
