#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
public:
    void run() {
        string str;
        int N, M;
        cin >> N >> M;
        vector<string> box;
        while(cin >> str){
            box.push_back(str);
        }
        vector<string> result_lines;
        string line;
        for(int i = 0; i < box.size(); ++i) {
            if(box[i].size() + line.size() < N + M) {
                line += box[i];
                line += " ";
            } else {
                // 去掉行末的空格
                line.pop_back();
                result_lines.push_back(line);
                line.clear();
                line += box[i];
                line += " ";
            }
        }
        if(line.size() != 0) {
            result_lines.push_back(box[box.size() - 1]);
        }
        cout << result_lines.size() << endl;
        for(int i = 0; i < result_lines.size(); ++i) {
            cout << result_lines[i] << endl;
        }
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

