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
private:
    void __find_prev_node(TreeNode * root, vector<TreeNode *> & prevNode){
        if(!root)
            return;
        if(root->left){
            prevNode[root->left->val] = root;
            __find_prev_node(root->left, prevNode); 
        }
        if(root->right){
            prevNode[root->right->val] = root;
            __find_prev_node(root->right, prevNode); 
        }
    }

    void __bfs(TreeNode * node, vector<TreeNode*> & prevNode, int dis, int k, vector<int> & visited, vector<int> & res){
        if(!node){
            return;
        }
        visited[node->val] = 1;
        if(dis == k){
            res.push_back(node->val);
            return;
        }
        if(node->left && visited[node->left->val] == 0){
            __bfs(node->left,prevNode,dis+1,k,visited,res);
        }
        if(node->right && visited[node->right->val] == 0){
            __bfs(node->right,prevNode,dis+1,k,visited,res);

        }
        TreeNode * prev = prevNode[node->val];
        if(prev && visited[prev->val] == 0){
            __bfs(prev,prevNode,dis+1,k,visited,res);
        }

    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // do a bfs
        vector<TreeNode *> prevNode(500,nullptr);
        __find_prev_node(root,prevNode);
        
        vector<int> visited(500,0);
        vector<int> res;

        __bfs(target,prevNode,0,k,visited,res);

        return res;
    }
};