#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
public:
    void run() {
        int T;
        cin >> T;
        while(T--) {
            int n;
            cin >> n;
            // 输入数字
            vector<int> nums(n);
            for(int i = 0; i < n; ++i) {
                cin >> nums[i];
            }
            // 输入花色
            vector<char> types(n);
            for(int i = 0; i < n; ++i) {
                cin >> types[i];
            }

            // 开始处理
            if(check1(nums, types, n)) {
                cout << "15000" << endl;
            } else if(check2(nums, types, n)) {
                cout << "8000" << endl;
            } else if(check3(nums, types, n)) {
                cout << "300" << endl;
            } else if(check4(nums, types, n)) {
                cout << "150" << endl;
            } else if(check5(nums, types, n)) {
                cout << "40" << endl;
            } else if(check6(nums, types, n)) {
                cout << "20" << endl;
            } else if(check7(nums, types, n)) {
                cout << "6" << endl;
            } else if(check8(nums, types, n)) {
                cout << "4" << endl;
            } else if(check9(nums, types, n)) {
                cout << "2" << endl;
            } else {
                cout << "1" << endl;
            }
        }
    }

    // 数字相同的5张牌
    bool check1 (vector<int> nums, vector<char> types, int n) {
        if(n < 5)   return false;
        int target = nums[0];
        for(int i = 1; i < 5; ++i) {
            if(nums[i] != target)
                return false;
        }
        return true;
    }

    // 类别相同，且数字连续的5张牌
    bool check2 (vector<int> nums, vector<char> types, int n) {
        if(n < 5)   return false;
        int targetType = types[0];
        for(int i = 1; i < 5; ++i) {
            if(types[i] != targetType)
                return false;
        }
        sort(nums.begin(), nums.end());
        int targetNum = nums[0];
        for(int i = 1; i < 5; ++i) {
            targetNum++;
            if(nums[i] != targetNum)
                return false;
        }
        return true;
    }
    // 类别相同的任意5张牌
    bool check3 (vector<int> nums, vector<char> types, int n) {
        if(n < 5)   return false;
        int targetType = types[0];
        for(int i = 1; i < 5; ++i) {
            if(types[i] != targetType)
                return false;
        }
        return true;
    }

    // 数字相同的4张牌
    bool check4 (vector<int> nums, vector<char> types, int n) {
        vector<int> hash(11, 0);
        for(int i = 0; i < nums.size(); ++i) {
            hash[nums[i]]++;
        }
        for(int i = 1; i <= 10; ++i) {
            if(hash[i] == 4) 
                return true;
        }
        return false;
    }

    // 数字相同的3张牌+数字相同的2张牌
    bool check5 (vector<int> nums, vector<char> types, int n) {
        if(n < 5)   return false;
        vector<int> hash(11);
        for(int i = 0; i < nums.size(); ++i) {
            hash[nums[i]]++;
        }
        bool flagA = false, flagB = false;
        for(int i = 1; i <= 10; ++i) {
            if(hash[i] == 3)  {
                flagA = true;
            } else if(hash[i] == 2) {
                flagB = true;
            }
        }
        return flagA && flagB;
    }

    // 数字连续的5张牌
    bool check6 (vector<int> nums, vector<char> types, int n) {
        if(n < 5)   return false;
        sort(nums.begin(), nums.end());
        int targetNum = nums[0];
        for(int i = 1; i < n; ++i) {
            targetNum++;
            if(nums[i] != targetNum)
                return false;
        }
        return true;
    }

    // 数字相同的3张牌
    bool check7 (vector<int> nums, vector<char> types, int n) {
        vector<int> hash(11);
        for(int i = 0; i < nums.size(); ++i) {
            hash[nums[i]]++;
        }
        for(int i = 1; i <= 10; ++i) {
            if(hash[i] == 3)  {
                return true;
            }
        }
        return false;
    }
    // 数字相同的2张牌+数字相同的2张牌
    bool check8 (vector<int> nums, vector<char> types, int n) {
        vector<int> hash(11);
        for(int i = 0; i < nums.size(); ++i) {
            hash[nums[i]]++;
        }
        bool flag = false;
        for(int i = 1; i <= 10; ++i) {
            if(!flag && hash[i] == 2)  {
                flag = true;
            } else if(flag && hash[i] == 2) {
                return true;
            }
        }
        return false;
    }

    // 数字相同的2张牌
    bool check9 (vector<int> nums, vector<char> types, int n) {
        vector<int> hash(11);
        for(int i = 0; i < nums.size(); ++i) {
            hash[nums[i]]++;
        }
        for(int i = 1; i <= 10; ++i) {
            if(hash[i] == 2)  {
                return true;
            }
        }
        return false;
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

