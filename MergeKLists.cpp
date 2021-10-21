/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Comp{
    // Comparator function
    public:
    bool operator()(ListNode * l1, ListNode * l2)
    {
        return l1->val > l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *,vector<ListNode *>,Comp> minHeap;
        int size = lists.size();
        if(size == 0)
            return nullptr;
        for(int i = 0; i < size; i++){
            if(lists[i] != nullptr)
                minHeap.push(lists[i]);
        }
        if(minHeap.empty()){
            return nullptr;
        }
        ListNode * res = nullptr;
        ListNode * curTail = nullptr;
        res = minHeap.top();
        curTail = res;
        minHeap.pop();
        if(curTail->next != nullptr){
            minHeap.push(curTail->next);
        }
        while(!minHeap.empty()){
            curTail->next = minHeap.top();
            curTail = curTail->next;
            minHeap.pop();
            if(curTail->next != nullptr){
                minHeap.push(curTail->next);
            }
        }
        return res;
    }
};