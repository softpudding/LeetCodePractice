/* 
 * 题目：分裂二叉树的最大成绩 题号：1339 140ms 99.04%
 * 这道题就是典型的空间换时间做法 如果遍历两遍二叉树会超时
 * 所以需要在一次遍历中就做完所有事情 很有意思
 * /
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
    const long long MO = 1000000007; 
    long long getTotalSumAndSubSums(TreeNode * root, long long * subsums, int & index){
        if(root == nullptr)
            return 0;
        long long subsum = root->val + (root->left == nullptr ? 0 : getTotalSumAndSubSums(root->left,subsums,index)) 
            + (root->right == nullptr ? 0 : getTotalSumAndSubSums(root->right,subsums,index));
        subsums[index++] = subsum;
        return subsum;
    }
    long long maxProduct(TreeNode* root) {
        // I expect the program to use 8MB memory~
        long long * subsums = new long long [1024*1024], total_sum = 0;
        int index = 0;
        total_sum = getTotalSumAndSubSums(root,subsums,index);
        long long temp_product = 0, max_product = 0;
        for(int i = 0; i < index; i ++){
            temp_product = (total_sum - subsums[i]) * subsums[i];
            max_product = temp_product > max_product ? temp_product : max_product;
        }
        return max_product % MO;
    }
};