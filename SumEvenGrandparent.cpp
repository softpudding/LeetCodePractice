#include<iostream>
#include<vector>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        vector<TreeNode*> stack;
        stack.push_back(root);
        int sum = 0;
        TreeNode * node = nullptr;
        while(!stack.empty()){
            node = stack.back();
            stack.pop_back();
            if(node->left){
                stack.push_back(node->left);
                if(node->val % 2 == 0){
                    if(node->left->left){
                        sum += node->left->left->val;
                    }
                    if(node->left->right){
                        sum += node->left->right->val;
                    }
                }
            }
            if(node->right){
                stack.push_back(node->right);
                if(node->val % 2 == 0){
                    if(node->right->left){
                        sum += node->right->left->val;
                    }
                    if(node->right->right){
                        sum += node->right->right->val;
                    }
                }
            }

        }
        return sum;
    }
};