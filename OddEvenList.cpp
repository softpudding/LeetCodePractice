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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode * oddListHead = nullptr, * oddListTail = nullptr,
        * evenListHead = nullptr, * evenListTail = nullptr;
        int ct = 1;
        ListNode * cur = head;
        while(cur){
            if(ct % 2){
                // odd
                if(!oddListHead){
                    oddListHead = oddListTail = cur;
                }
                else{
                    oddListTail->next = cur;
                    oddListTail = cur;
                }
            }
            else{
                // even
                if(!evenListHead){
                    evenListHead = evenListTail = cur;
                }
                else{
                    evenListTail->next = cur;
                    evenListTail = cur;
                }
            }
            cur = cur->next;
            ct++;
        }
        if(oddListHead == nullptr){
            return nullptr;
        }
        if(evenListHead == nullptr){
            return oddListHead;
        }
        else{
            oddListTail->next = evenListHead;
            evenListTail->next = nullptr;
            return oddListHead;
        }
    }
};