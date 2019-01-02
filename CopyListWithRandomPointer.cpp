/*
题目：复制带随机指针的链表 题号138
这个题目实现起来不难，难的是效率。我第一遍做完这个题用的是最朴素的方法...然后160ms，1%。
现在自己实现了一个hash表，具体可以看代码，写的很清楚了。最后是36ms，99.1%。
*/

#include<iostream>
using namespace std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
//This hashtable is for storing
class SpecialMap{
    struct SpecialNode{
        RandomListNode *ori, *cor;
        SpecialNode *next;
        SpecialNode(RandomListNode *x,RandomListNode *y):ori(x),cor(y),next(nullptr){}
    };
private:
    SpecialNode *smap[0x3FF+1]={0};
    //check the last 3 bytes of a pt by & 0xFFF than /4
    //so range from 0xFFC to 0x000
public:
    SpecialMap(){}
    void insert(RandomListNode *x,RandomListNode *y){
        SpecialNode *new_snode=new SpecialNode(x,y);
        if(smap[((long long)x&0xFFF)/4]==nullptr)
            smap[((long long)x&0xFFF)/4]=new_snode;
        else{
            SpecialNode *temp=smap[((long long)x&0xFFF)/4];
            while(temp->next!=nullptr)
                temp=temp->next;
            temp->next=new_snode;
        }
    }
    RandomListNode * search_cor(RandomListNode *x)
    {
        SpecialNode * temp=smap[((long long)x&0xFFF)/4];
        while(temp->ori!=x)
        {
            temp=temp->next;
        }
        return temp->cor;
    }

};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *new_list_head=nullptr;
        if(head!=nullptr)
            new_list_head=new RandomListNode(head->label);
        else
            return nullptr;
        RandomListNode *cur_node=head->next;
        RandomListNode *cur_new_list=nullptr;
        RandomListNode *prev_new_list=new_list_head;

        SpecialMap sm;
        sm.insert(head,new_list_head);

        int len=1;
        //first time of loop check out the length of original list
        //and copy list without pt random

        while(cur_node!=NULL)
        {
            len++;
            cur_new_list=new RandomListNode(cur_node->label);

            sm.insert(cur_node,cur_new_list);

            prev_new_list->next=cur_new_list;
            prev_new_list=cur_new_list;
            cur_node=cur_node->next;
        }
        //second time of loop there are len random pt
        //and I should find out more about them
        cur_node=head;cur_new_list=new_list_head;
        while(cur_node!= nullptr)
        {
            if(cur_node->random== nullptr)
                cur_new_list->random=nullptr;
            else{
                cur_new_list->random=sm.search_cor(cur_node->random);
            }
            cur_node=cur_node->next;
            cur_new_list=cur_new_list->next;
        }


        return new_list_head;

    }

};
int main (void)
{
    RandomListNode n1(1);
    RandomListNode n2(2);
    n1.next=&n2;
    n1.random=&n2;
    Solution().copyRandomList(&n1);

}