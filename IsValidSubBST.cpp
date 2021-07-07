/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 对子树进行判断：这个子树节点的数值范围是否在min max之间？
    bool isValidSubBST(TreeNode * root, long long min, long long max){
        if(root == NULL)
            return true;
        long long val = root->val;
        if(val <= min || val >= max){
            //cout<<val<<' '<<min<<' '<<max<<'\n';
            return false;
        }
        else{
            return isValidSubBST(root->right,val > min ? val : min , max) && 
                isValidSubBST(root->left, min, val < max ? val : max);
        }
    }
    bool isValidBST(TreeNode* root) {
        return isValidSubBST(root,-(((long long)1<<35)-1),(((long long)1<<35)-1));
    }
};