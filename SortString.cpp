#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    string sortString(string s) {
        // 题目中说明了：s中只包含小写字母
        // charCount是一个数组 记录了a~z在s中出现的次数
        int charCount[26] = {0};
        int len = s.size();
        for(int i = 0; i < len; i++){
            charCount[s[i] - 'a']++;
        }
        string res;
        // 这个量用来标记原数组里还有多少个字符没有排序
        // 当这个量为0时后面的循环就要结束
        int charLeft = len;
        // 这个量为true表示正序排序 false逆序
        bool pos = true;
        int index = -1;
        while(charLeft != 0){
            if(index == -1){
                pos = true;
                index = 0;
            }
            else if(index == 26){
                pos = false;
                index = 25;
            }
            else{
                if(charCount[index] != 0){
                    res += ('a'+index);
                    charCount[index]--;
                    charLeft--;
                }
                if(pos){
                    index++;
                }
                else{
                    index--;
                }
            }
        }

        return res;

    }
};