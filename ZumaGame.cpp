/*
题目：祖玛游戏 题号：488
看提示写的是DFS，但我并不知道怎么用DFS来做这个题...
写了一个暴力的博弈树解法，然后很慢，但是好歹过了。
*/
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int findMinStep(string board, string hand, int steps=1) {
        int temp=INT32_MAX,min=INT32_MAX;
        for(auto iter=board.begin();iter<board.end();){
            int ct=1;
            while(*(iter+ct)==*iter){
                ct++;
            }
            if(ct>=3){
                board.erase(iter,iter+ct);
                iter=board.begin();
                continue;
            }
            iter+=ct;
        }
        if(board.empty())
            return steps-1;
        else if(hand.empty())
            return -1;

        char prevCh=board[0];
        auto board_index=0;
        auto hand_index=0;
        for(;hand_index<hand.size();hand_index++){
            if(hand[hand_index]==prevCh){
                board.insert(board.begin()+board_index,prevCh);
                hand.erase(hand.begin()+hand_index);
                temp=findMinStep(board,hand,steps+1);
                if(temp!=-1)
                    min=temp;
                board.erase(board.begin()+board_index);
                hand.insert(hand.begin()+hand_index,prevCh);
            }
        }

        for(board_index=1;board_index<board.size();board_index++){
            if(board[board_index]==prevCh)
                continue;
            else{
                prevCh=board[board_index];
                for(hand_index=0;hand_index<hand.size();hand_index++){
                    if(hand[hand_index]==prevCh){
                        board.insert(board.begin()+board_index,prevCh);
                        hand.erase(hand.begin()+hand_index);
                        temp=findMinStep(board,hand,steps+1);
                        if(temp!=-1&&temp<min)
                            min=temp;
                        board.erase(board.begin()+board_index);
                        hand.insert(hand.begin()+hand_index,prevCh);
                    }
                }
            }
        }
        if(min==INT32_MAX)
            return -1;
        return min;
    }
};
int main (void){
    string board="YYBBY";
    string hand="YB";
    cout<<Solution().findMinStep(board,hand);
    return 0;
}