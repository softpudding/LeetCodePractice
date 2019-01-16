/**
 * 题目：二叉树的最大宽度 题号：662 4ms，100%
 * 主要是利用了堆可以用数组实现的这个思想，把二叉树也用堆的序列的方式来考虑。
 * 然后为了满足数字上的有符号32位整形的局限，做了一定的调整。
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
    const int SIZE=4000;
    //Think of this bi tree as a heap
    int widthOfBinaryTree(TreeNode* root) {    
        long long dis[SIZE][2];
        for(int i=0;i<SIZE;i++){
            dis[i][0]=0;
            dis[i][1]=0;
        }
        //pos ori 1 depth ori 0
        search(root,dis,1,1);
        int temp=0,max=0;
        for(int i=0;i<SIZE;i++){
            temp=dis[i][1];
            //cout<<"temp:"<<temp<<endl;
            if(temp>max)
            {
                max=temp;
            }
            
        }
        return max;
        
        
    }
    void search(TreeNode* curNode,long long dis[][2],long long pos,int depth){
        if(dis[depth][0]==0)
            dis[depth][0]=pos;
        int new_pos=pos-dis[depth][0]+1;
        dis[depth][1]=new_pos;
        if(curNode->left)
            search(curNode->left,dis,new_pos*2-1,depth+1);
        if(curNode->right)
            search(curNode->right,dis,new_pos*2,depth+1);
    }
    
};