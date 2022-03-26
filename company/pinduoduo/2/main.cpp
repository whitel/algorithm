#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void run() {
        // core code here
    }

};

int main() {
    Solution s;
    // input here

    int T;
    cin >> T;
    while(T--) {
        int n, V;
        cin >> n >> V;
        vector<int> nums(n+1);
        int maxDay = INT_MIN;
        multimap<int, int> m;
        for(int i = 1; i <= n; i++) {
            int value, start, end;
            cin >> value >> start >> end;
            nums[start] += value;
            nums[end+1] -= value;
            maxDay = max(maxDay, end);
            m.insert({start, end});
        }
        int ans = 0;
        int storage = 0;
        maxDay++;
        for(int today = 1; today <= maxDay; today++) {
            for(int i = 1; i <= maxDay; ++i) {
                cout << nums[i] << " ";
            }
            cout << endl;
            storage += nums[today];
            storage = max(0, storage);
            cout << "storage : " << storage << endl;
            int getValue = 0;
            if(storage > V) {
                getValue = V;
                storage -= V;
            } else {
                getValue = storage;
                storage = 0;
            }
            cout << "getvalue : " << getValue << endl;
            cout << "storage : " << storage << endl;
            ans += getValue;

            // 应该从离他最近的一个有map的数据中扣除

            vector<int> temp;
            for(auto iter = m.begin(); iter != m.find(today); iter++) {
                temp.push_back(iter->second);
                cout << iter->second << " ";
            }
            cout << endl;
            sort(temp.begin(), temp.end());
            int that;
            for(int i = 0; i < temp.size(); i++) {
                if(temp[i] > today) {
                    that = temp[i];
                    break;
                }
            }

            nums[that+1] += getValue;
            for(int i = 1; i <= maxDay; ++i) {
                cout << nums[i] << " ";
            }
            cout << endl;
            cout << "total : " << ans << endl;
            cout << "-----------------" << endl;
        }
        cout << ans << endl;
    }
    s.run();
    return 0;
}
