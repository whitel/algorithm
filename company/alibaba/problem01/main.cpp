#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
private:
    unordered_map<char, vector<char> > nums;
    string str;
public:
    void run() {
        cin >> str;
        nums = unordered_map<char, vector<char> >(str.size());
        nums['1'] = vector<char>{};
        nums['2'] = vector<char>{'A', 'B', 'C'};
        nums['3'] = vector<char>{'D', 'E', 'F'};
        nums['4'] = vector<char>{'G', 'H', 'I'};
        nums['5'] = vector<char>{'J', 'K', 'L'};
        nums['6'] = vector<char>{'M', 'N', 'O'};
        nums['7'] = vector<char>{'P', 'Q', 'R', 'S'};
        nums['8'] = vector<char>{'T', 'U', 'V'};
        nums['9'] = vector<char>{'W', 'X', 'Y', 'Z'};

        int curr = 0;       // 当前键入的数
        char buf = '0';     // 当前待输出的数
        int pointer = 0;    // 当前待输出数的指针
        for(int i = 0; i < str.size(); ++i) {
            switch(str[i]){
                case '1' :
                    // 如果当前的buf有待输出的数字，直接输出
                    if(buf != '0') {
                        // 输出buf
                        cout << buf ;
                        // 重置所有计数器
                        curr = 0;
                        buf = '0';
                        pointer = 0;
                    }
                    break;
                case '2' :    
                    helper(curr, 2, buf, pointer, 3);
                    break;
                case '3' :
                    helper(curr, 3, buf, pointer, 3);
                    break;
                case '4' :
                    helper(curr, 4, buf, pointer, 3);
                    break;
                case '5' :
                    helper(curr, 5, buf, pointer, 3);
                    break;
                case '6' :
                    helper(curr, 6, buf, pointer, 3);
                    break;
                case '7' :
                    helper(curr, 7, buf, pointer, 4);
                    break;
                case '8' :
                    helper(curr, 8, buf, pointer, 3);
                    break;
                case '9' :
                    helper(curr, 9, buf, pointer, 4);
                    break;
            }
        }
        cout << endl;
    }

    void helper(int &curr, int target, char &buf, int &pointer, int mod) {
        if(curr != target && buf != '0') {
            // 如果当前缓冲区里有数，就先输出
            cout << buf ;
            pointer = 0;
        }
        curr = target;
        buf = nums[target + '0'][pointer];
        pointer = (pointer + 1) % mod;
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

