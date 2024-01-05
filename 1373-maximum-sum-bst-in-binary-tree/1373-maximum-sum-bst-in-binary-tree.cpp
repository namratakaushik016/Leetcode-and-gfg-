/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  
class info{
    public : 
    int maxi;
    int mini;
    bool isBST;
    int sum;
};

info solve(TreeNode* root, int &ans){
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info newRoot;
    newRoot.maxi = max(root->val, right.maxi);
    newRoot.mini = min(root->val, left.mini);
    newRoot.sum = left.sum + right.sum + root->val;

    if(left.isBST && right.isBST && (root->val < right.mini) && (root->val > left.maxi) ){
        newRoot.isBST = true;
    }
    else{
        newRoot.isBST = false;
    }
    if(newRoot.isBST){
        ans = max(newRoot.sum, ans);
    }
    return newRoot;

}
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }

};