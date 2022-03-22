#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
public:
    void run() {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        printVector(nums);
        mergeSort(nums, 0, nums.size() - 1);
        printVector(nums);
    }

    void mergeSort(vector<int> &nums, int left, int right) {
        if(left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    void merge(vector<int> &nums, int left, int mid, int right) {
        // 注意这里要+1，因为mid取得到
        int subArrayA = mid - left + 1;
        // 注意这里不+1，因为mid是取不到的（上面已经取过了）
        int subArrayB = right - mid;

        // 创建temp数组
        vector<int> NumsA(subArrayA);
        vector<int> NumsB(subArrayB);

        // 把原数据复制到新temp数组里
        for(int i = 0; i < subArrayA; ++i) 
            NumsA[i] = nums[left + i];
        for(int i = 0; i < subArrayB; ++i)
            NumsB[i] = nums[mid + i + 1];

        int indexA = 0, indexB = 0;
        int indexC = left;

        // 合并两个有序数组
        while(indexA < subArrayA && indexB < subArrayB) {
            if(NumsA[indexA] <= NumsB[indexB]) {
                nums[indexC++] = NumsA[indexA++];
            } else {
                nums[indexC++] = NumsB[indexB++];
            }
        }

        // 合并剩下的数组
        while(indexA < subArrayA) {
            nums[indexC++] = NumsA[indexA++];
        }

        while(indexB < subArrayB) {
            nums[indexC++] = NumsB[indexB++];
        }
    }


    void printVector(vector<int> nums) {
        for(int x : nums) {
            cout << x << " ";
        }
        cout << endl;
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

