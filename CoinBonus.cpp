/*
 * 题目：发LeetCoin 题号不详 用dfs加上线段树实现，击败100%
 */
#include <vector>
#include <cassert>
using namespace std;
// 孩子兄弟表示法
// v0.1 可以通过50/51的测试 最后一个48000+的用例过不去
class Node {
public:
    void addAsChild(Node * n){
        n->only_father = this;
        if(first_son == nullptr){
            // no child at all
            first_son = n;
        }
        else{
            if(first_son->first_sibling == nullptr){
                first_son->first_sibling = first_son->last_sibling = n;
            }
            else{
                first_son->last_sibling->first_sibling = n;
                first_son->last_sibling = n;
            }
        }
    }
    void getCoin(long long n){
        coins += n;
        team_coins += n;
        Node * cur = only_father;
        while(cur){
            cur->team_coins += n;
            cur = cur->only_father;
        }
    }
    long long teamGetCoin(long long n, bool isChief = false){
        coins += n;
        long long team_added_amount = n;
        Node * cur = first_son;
        while(cur){
            team_added_amount += cur->teamGetCoin(n);
            cur = cur->first_sibling;
        }
        team_coins += team_added_amount;
        if(isChief){
            Node * cur = only_father;
            while(cur){
                cur->team_coins += team_added_amount;
                cur = cur->only_father;
            }
        }
        return team_added_amount;
    }
    long long teamCoinSum(void){
        return team_coins % MO;
    }
    Node(void): only_father(nullptr),first_sibling(nullptr),last_sibling(nullptr),first_son(nullptr),coins(0),team_coins(0),childn(0){}
private:
    static const long long MO = 1000000007;
    Node * only_father;
    Node * first_sibling;
    Node * last_sibling;
    Node * first_son;
    long long coins;
    long long team_coins;
    // childn需要包括子子孙孙无穷尽也
    int childn;
};
class Solution_0 {
public:
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        Node * all_nodes = new Node[n];
        Node * chief_manager = all_nodes;
        Node * cur_super = nullptr, * cur_infer = nullptr;
        for(int i = 0; i < n - 1; i++){
            cur_super = all_nodes + leadership[i][0] - 1;
            cur_infer = all_nodes + leadership[i][1] - 1;
            cur_super->addAsChild(cur_infer);
        }
        int size = operations.size();
        vector<int> res;
        for(int i = 0; i < size; i ++){
            switch(operations[i][0]){
                case 1:
                    all_nodes[operations[i][1] - 1].getCoin(operations[i][2]);
                    break;
                case 2:
                    all_nodes[operations[i][1] - 1].teamGetCoin(operations[i][2],true);
                    break;
                case 3:
                    res.push_back(all_nodes[operations[i][1] - 1].teamCoinSum());
                    break;
            }
        }
        return res;
    }
};
// v0.2 dfs（先序遍历） + 线段树
struct Node_2{
    Node_2 * first_sibling;
    Node_2 * last_sibling;
    Node_2 * first_son;
    int l, r;
    int id;
    Node_2():first_sibling(nullptr),last_sibling(nullptr),first_son(nullptr),l(0),r(0),id(0){}
};
void dfs(Node_2 * cur_node,Node_2 ** sorted_nodes, int & cur_index){
    if(!cur_node)
        return;
    sorted_nodes[++cur_index] = cur_node;
    cur_node->l = cur_index;
    Node_2 * cur_node_child = cur_node->first_son;
    while(cur_node_child){
        dfs(cur_node_child,sorted_nodes,cur_index);
        cur_node_child = cur_node_child->first_sibling;
    }
    cur_node->r = cur_index;
}
struct SegmentNode{
    int l, r, m;
    long long lazy;
    long long total_coins;
    SegmentNode(){
        l = r = m = 0;
        lazy = total_coins = 0;
    }
};
class SegmentTree{
private:
    const int MO = 1000000007;
    SegmentNode * nodes = nullptr;
public:
    inline int LEFT(int x){
        return 2*x;
    }
    inline int RIGHT(int x){
        return 2*x + 1;
    }
    inline int FATHER(int x){
        return x/2;
    }
    SegmentTree(int n){
        nodes = new SegmentNode[4*n];
        // 需要修改
        build(0,n-1,1);
    }
    void build(int l, int r, int cur){
        nodes[cur].l = l;
        nodes[cur].r = r;
        int m = (l+r) / 2;
        nodes[cur].m = m;
        if(l == r)
            return;
        else{
            build(l,m,LEFT(cur));
            build(m+1,r,RIGHT(cur));
        }
    }
    void addCoins(int targ_l, int targ_r, long long coins, int cur){
        int cur_l = nodes[cur].l, cur_r = nodes[cur].r;
        if(targ_l > cur_r || targ_r < cur_l){
            return;
        }
        else if(targ_l <= cur_l && targ_r >= cur_r){
            nodes[cur].lazy += coins;
        }
        else if(targ_l >= cur_l && targ_r <= cur_r){
            int len = targ_r - targ_l + 1;
            nodes[cur].total_coins += coins*len;
            addCoins(targ_l,targ_r,coins,LEFT(cur));
            addCoins(targ_l,targ_r,coins,RIGHT(cur));
        }
        else{
            int len = cur_l < targ_l ?  cur_r - targ_l + 1: targ_r - cur_l + 1;
            nodes[cur].total_coins += coins * len;
            addCoins(targ_l,targ_r,coins,LEFT(cur));
            addCoins(targ_l,targ_r,coins,RIGHT(cur));
        }
    }
    long long searchCoins(int targ_l, int targ_r, int cur){
        long long cur_lazy = nodes[cur].lazy;
        int cur_l = nodes[cur].l, cur_r = nodes[cur].r;
        if(cur_lazy != 0){
            if(cur_l != cur_r){
                nodes[LEFT(cur)].lazy += cur_lazy;
                nodes[RIGHT(cur)].lazy += cur_lazy;
                nodes[cur].lazy = 0;
                nodes[cur].total_coins += (cur_r - cur_l + 1) * cur_lazy;
            }
            else{
                nodes[cur].total_coins += cur_lazy;
                nodes[cur].lazy = 0;
            }
        }
        if(cur_l > targ_r || cur_r < targ_l){
            return 0;
        }
        else if(targ_l <= cur_l && targ_r >= cur_r){
            return (nodes[cur].total_coins)%MO;;
        }
        else{
            int cur_mid = (cur_l + cur_r) / 2;
            return (searchCoins(targ_l,targ_r,LEFT(cur)) + searchCoins(targ_l,targ_r,RIGHT(cur)))%MO;
        }
    }
};
class Solution {
public:

    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        Node_2 * all_nodes = new Node_2[n];
        Node_2 * chief_manager = all_nodes;
        Node_2 * cur_super = nullptr, * cur_infer = nullptr;
        // 初始化图
        for(int i = 0; i < n - 1; i++){
            cur_super = all_nodes + leadership[i][0] - 1;
            cur_infer = all_nodes + leadership[i][1] - 1;
            cur_super->id = leadership[i][0];
            cur_infer->id = leadership[i][1];
            if(cur_super ->first_son == nullptr){
                cur_super->first_son = cur_infer;
            }
            else{
                if(cur_super->first_son->first_sibling){
                    cur_super->first_son->last_sibling->first_sibling = cur_infer;
                    cur_super->first_son->last_sibling = cur_infer;
                }
                else{
                    cur_super->first_son->first_sibling = cur_super->first_son->last_sibling = cur_infer;
                }
            }
        }
        // 做一次dfs 确认排序
        Node_2 ** sorted_all_nodes = new Node_2 * [n];
        int index = -1;
        dfs(all_nodes,sorted_all_nodes,index);
        assert(index == n - 1);
        SegmentTree * st = new SegmentTree(n);

        
        int size = operations.size();
        vector<int> res;
        int l = 0, r = 0;
        for(int i = 0; i < size; i ++){
            switch(operations[i][0]){
                case 1:
                    l = all_nodes[operations[i][1] - 1].l;
                    r = l;
                    st->addCoins(l,r,operations[i][2],1);
                    break;
                case 2:
                    l = all_nodes[operations[i][1] - 1].l;
                    r = all_nodes[operations[i][1] - 1].r;
                    st->addCoins(l,r,operations[i][2],1);
                    break;
                case 3:
                    l = all_nodes[operations[i][1] - 1].l;
                    r = all_nodes[operations[i][1] - 1].r;
                    res.push_back(st->searchCoins(l,r,1));
                    break;
            }
        }
        
        return res;
    }
};