/*
题目：删除链表的倒数第N个节点 No.19
惊了，第一次做到超过100.00%。
思路就是用一个N+1大小的数组维护当前遍历到的Node
循环更新 超过N+1的内容不停从头开始遍历 最后数组必然形成以下情况（不考虑cornor case）
[***************E*D****]
每个*和E和D都代表一个node 最后只需要用D左边的这个node连接到D右边的node上就可以了
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * listNodeArray[n+1]={};
        listNodeArray[0]=head;
        ListNode * cur_node=head;
        int ct=0;
        while(cur_node->next)
        {
            cur_node=cur_node->next;
            if(++ct>=n+1)
                ct%=n+1;
            listNodeArray[ct]=cur_node;
        }
        if(!listNodeArray[(ct+1)%(n+1)])
            return listNodeArray[(ct+3)%(n+1)];//new head
        if(n==1)
            listNodeArray[(ct+1)%(n+1)]->next=NULL;
        else
            listNodeArray[(ct+1)%(n+1)]->next=listNodeArray[(ct+3)%(n+1)];
        return head;

    }
};