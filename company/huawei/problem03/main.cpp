#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
public:
    void run() {
        int M, N, x;
        cin >> M >> N >> x;
        if(N * 2 < M * x)   cout << "false" << endl;
        vector<vector<string> > interviews;
        for(int i = 0; i < M; ++i) {
            string str;
            vector<string> str_arr;
            while(cin >> str) {
                str_arr.push_back(str);
            }
            interviews.push_back(str_arr);
        }
        vector<string> student;
        for(int i = 0; i < N; ++i) {
            string str;
            while(cin >> str) {
                student.push_back(str);
            }
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

