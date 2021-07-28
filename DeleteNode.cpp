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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode * target = root, * father = nullptr, * newTarget = nullptr;
        if(!target)
            return nullptr;
        while(target->val != key){
            if(target->val < key){
                father = target;
                target = target->right;
            }
            else{
                father = target;
                target = target->left;
            }
            if(!target)
                return root;
        }
        if(target->right == nullptr){
            newTarget = target->left;
        }
        else{
            newTarget = target->right;
            TreeNode * cur = newTarget;
            while(cur->left){
                cur = cur->left;
            }
            cur->left = target->left;
        }
        if(!father)
            return newTarget;
        if(target == father->left){
            father->left = newTarget;
            return root;
        }    
        else{
            father->right = newTarget;
            return root;
        }
    }
};