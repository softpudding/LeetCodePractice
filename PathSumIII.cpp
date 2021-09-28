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
private:
    int countFromNode(TreeNode * cur, int curSum, int targetSum){
        if(cur == nullptr)
            return 0;
        curSum += cur->val;
        if(curSum == targetSum){
            return 1+countFromNode(cur->left,curSum,targetSum)+countFromNode(cur->right,curSum,targetSum);
        }
        return countFromNode(cur->left,curSum,targetSum)+countFromNode(cur->right,curSum,targetSum);
    }
    int count(TreeNode * cur, int targetSum){
        if(cur == nullptr)
            return 0;
        return countFromNode(cur,0,targetSum) + count(cur->left,targetSum) + count(cur->right,targetSum);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return 0;
        return count(root,targetSum);
    }
};