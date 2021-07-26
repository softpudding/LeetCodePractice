#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<map>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        // used in the original linked-list: keep record of <pointer,index> relationship
        map<Node *, int> cmap;
        // used in keeping record of <index,pointer> relationship of new linked-list
        Node * newNodes[1000] = {0};
        int i = 0;
        // p used to traverse original linked-list
        Node * p = head;
        // if original linked-list is empty, just return NULL
        if(!p){
            return NULL;
        }
        Node * newList = new Node(head->val);
        // _p used to traverse new linked-list
        Node * _p = newList;
        newNodes[0] = _p;

        while(p){
            cmap.insert(pair<Node *,int>(p,i));
            i++;
            if(p->next){
                p = p->next;
                _p->next = new Node(p->val);
                _p = _p->next;
                newNodes[i] = _p;
            }
            else{
                break;
            }
        }

        p = head;
        _p = newList;
        int index;
        while(p){
            if(p->random == nullptr){
                _p->random = nullptr;
            }
            else{
                assert(cmap.find(p->random) != cmap.end());
                index = cmap.find(p->random)->second;
                _p->random = newNodes[index];
            }
            p = p->next;
            _p = _p->next;
        }
        
        return newList;
    }
};

int main(){
    Solution s;
    s.copyRandomList(NULL);
    return 0;
}