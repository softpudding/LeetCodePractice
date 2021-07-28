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
    bool isPalindrome(ListNode* head) {
        ListNode * cur = head;
        int len = 0;
        // get the length of list
        while(cur){
            len++;
            cur = cur->next;
        }
        int palindromeLen = len / 2;
        int ct = 0;
        vector<int> s;
        cur = head;
        while(ct < palindromeLen){
            ct++;
            s.push_back(cur->val);
            cur = cur->next;
        }
        if(len % 2){
            cur = cur->next;
        }
        while(cur){
            if(cur->val != s.back()){
                return false;
            }
            else{
                s.pop_back();
                cur = cur->next;
            }
        }
        return true;
    }
};