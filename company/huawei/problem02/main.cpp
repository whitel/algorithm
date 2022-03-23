#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
public:
    void run() {
        string str;
        cin >> str;
        
        unordered_map<char, int> alpha;
        alpha['0'] = 0;
        alpha['1'] = 1;
        alpha['2'] = 2;
        alpha['3'] = 3;
        alpha['4'] = 4;
        alpha['5'] = 5;
        alpha['6'] = 6;
        alpha['7'] = 7;
        alpha['8'] = 8;
        alpha['9'] = 9;
        alpha['A'] = 10;
        alpha['B'] = 11;
        alpha['C'] = 12;
        alpha['D'] = 13;
        alpha['E'] = 14;
        alpha['F'] = 15;

        int index = 0;

        unordered_map<int, vector<int> > M;

        while(true){
            if(str.size() - index < 4)  break;
            int tag = 0;
            tag = alpha[str[index + 0]] * 16 + alpha[str[index + 1]];
            int length = 0;
            length = alpha[str[index + 2]] * 16 + alpha[str[index + 3]];
#ifdef DEBUG
            cout << tag << " " << length << endl;
#endif
            index += (4 + length * 2);
            if(index > str.size()) {
                break;
            }
#ifdef DEBUG
            cout << "added" << endl;
#endif
            vector<int> temp;
            temp.push_back(length);
            temp.push_back(index - length * 2 - 2);
            M.insert({tag, temp});
        }
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            int tag;
            cin >> tag;
            if(M.find(tag) != M.end()) {
                cout << M[tag][0] << " " << M[tag][1] << endl;
            } else {
                cout << "0 0" << endl;
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

