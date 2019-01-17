/*
题目：长按键入 题号：925
玩了一天累了，随便挑个简单的做，假装还在学习。0ms没有压力。
*/
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int index1=0,index2=0;
        while(index1<name.length()){
            if(typed[index2]==name[index1]){
                index2++;
                index1++;
            }
            else if(index1-1>=0&&typed[index2]==name[index1-1]){
                index2++;
            }
            else return false;
        }
        return true;
    }
};