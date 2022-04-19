#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

class Solution {
private:
    unordered_map<int, int> loc;
public:
    TreeNode* reConstructBST(vector<int>& preSlice) {
        // write code here
        vector<int> inSlice = preSlice;
        sort(inSlice.begin(), inSlice.end());
        for(int i = 0; i < inSlice.size(); ++i) {
            loc[inSlice[i]] = i;
        }
        return helper(preSlice, 0, preSlice.size() - 1, inSlice, 0, inSlice.size() - 1);
    }
    
    TreeNode* helper(vector<int>& preSlice, int preLeft, int preRight, 
                     vector<int>& inSlice, int inLeft, int inRight) {
        if(preLeft > preRight || inLeft > inRight || preLeft < 0 || preLeft >= preSlice.size() || preRight < 0 || preRight >= preSlice.size() || inLeft < 0 || inLeft >= inSlice.size() || inRight < 0 || inRight >= inSlice.size())
            return nullptr;
        int rootVal = preSlice[preLeft];
        TreeNode *root = new TreeNode(rootVal);
        int rootIndex = loc[rootVal];
        root->left = helper(preSlice, preLeft + 1, preLeft + (rootIndex - inLeft), 
                            inSlice, inLeft, rootIndex - 1);
        root->right = helper(preSlice, preLeft + (rootIndex - inLeft) + 1, preRight, 
                            inSlice, rootIndex + 1, inRight);
        return root;
    }
};

void traverseTree(TreeNode *root) {
    if(root == nullptr)
        return ;
    traverseTree(root->left);
    cout << root->val << " ";
    traverseTree(root->right);
}

int main() {
#ifdef DEBUG
    freopen("inputdata", "r", stdin);
    cout << "===========INPUT=============" << endl;
    system("cat inputdata");
    cout << endl;
    cout << "===========OUTPUT============" << endl;
#endif
    int n;
    cin >> n;
    vector<int> preSlice(n);
    for(int i = 0; i < n; ++i)
        cin >> preSlice[i];

    Solution s;
    TreeNode *result = s.reConstructBST(preSlice);
    traverseTree(result);
    cout << endl;

#ifdef DEBUG
    cout << "============END==============" << endl;
#endif
    return 0;
}


