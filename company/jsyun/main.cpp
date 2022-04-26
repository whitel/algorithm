#include<bits/stdc++.h>
using namespace std;

#define DEBUG

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

class Solution {
private:
    vector<int> preOrder, inOrder;
    unordered_map<int, int> hash;
public:
    void run() {
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        for(int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for(int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        preOrder = A;
        inOrder = B;

        for(int i = 0; i < n; ++i)
            hash[inOrder[i]] = i;

        TreeNode *root = buildTree(0, 0, n - 1);
        printTree(root);
        cout << endl;
    }

    TreeNode *buildTree(int root, int left, int right) {
        if(left > right)
            return nullptr;
        TreeNode *node = new TreeNode(preOrder[root]);
        int i = hash[preOrder[root]];
        node->left = buildTree(root + 1, left, i - 1);
        node->right = buildTree(root + (i - left) + 1, i + 1, right);
        return node;
    }

    void printTree(TreeNode *root) {
        if(root == nullptr)
            return ;
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
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

