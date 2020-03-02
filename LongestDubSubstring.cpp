/*
 * 题号：1044 最长重复字串 用后缀数组做到过测试的边缘。。。并不理想wuwuwu
 */

#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
// v0.1 动态规划 时间复杂度n^3 空间复杂度超标
class Solution {
public:
    string longestDupSubstring(string S) {
        bool noFound = true;
        string res;

        int len = S.length();
        int *** d_p = new int ** [len];
        for(int i = 0; i < len; i++){
            d_p[i] = new int * [len];
            for(int j = 0; j < len; j++){
                d_p[i][j] = new int [len];
                for(int k = 0; k < len; k++){
                    d_p[i][j][k] = 0;
                }
            }
        }
        // 初始化d_p[?][?][1]的数组
        // 确保d_p[x][x][1]不为1
        for(int x = 0; x < len; x++){
            for(int y = x+1; y < len; y++){
                if(S[x] == S[y]){
                    d_p[x][y][1] = 1;
                    noFound = false;
                    res = S.substr(x,1);
                }
            }
        }
        if(noFound) 
            return "";
        // 开始考虑更长的字符串长度
        for(int current_len = 2; current_len < len; current_len ++){
            noFound = true;
            for(int x = 0; x < len - current_len; x++){
                for(int y = x+1; y <= len - current_len; y++){
                    if(d_p[x][y][current_len-1] && d_p[x+current_len-1][y+current_len-1][1]){
                        d_p[x][y][current_len] = 1;
                        noFound = false;
                        res = S.substr(x,current_len);
                    }
                }
            }
            if(noFound){
                return res;
            }
        }
        return res;
    }
};
// v0.2 动态规划 时间复杂度n^3 空间优化
// 但是还是超出空间限制。。
class Solution_2 {
public:
    string longestDupSubstring(string S) {
        bool noFound = true;
        string res;

        int len = S.length();
        int *** d_p = new int ** [len];
        for(int i = 0; i < len; i++){
            // d_p[i][j] 的意思是 S[i]和S[i+j+1]处的字串
            d_p[i] = new int * [len - i - 1];
            for(int j = 0; j < len - i - 1; j++){
                // S[i]和S[i+j+1]处字串 最多重复长度取决于后者
                // 计算：(len-1)-(i+j+1)+1+1
                d_p[i][j] = new int [len-(i+j)];
                for(int k = 0; k < len-(i+j); k++){
                    d_p[i][j][k] = 0;
                }
            }
        }
        // 初始化d_p[?][?][1]的数组
        for(int x = 0; x < len; x++){
            for(int y = 0; y < len - x - 1; y++){
                if(S[x] == S[x + y + 1]){
                    cout<<x<<' '<<y<<"hihi"<<endl;
                    d_p[x][y][1] = 1;
                    noFound = false;
                    res = S.substr(x,1);
                }
            }
        }
        if(noFound) 
            return "";
        // 开始考虑更长的字符串长度
        for(int current_len = 2; current_len < len; current_len ++){
            noFound = true;
            for(int x = 0; x < len - current_len; x++){
                for(int y = 0; y <= len - current_len - x - 1 ; y++){
                    if(d_p[x][y][current_len-1] && d_p[x+current_len-1][y][1]){
                        d_p[x][y][current_len] = 1;
                        noFound = false;
                        res = S.substr(x,current_len);
                    }
                }
            }
            if(noFound){
                return res;
            }
        }
        return res;
    }
};
// v0.3 改用二维数组来做线性规划 还是超出限制。。。。我吐了
class Solution_3 {
public:
    string longestDupSubstring(string S) {
        bool noFound = true;
        string res;

        int len = S.length();
        int ** d_p = new int * [len];
        for(int i = 0; i < len; i++){
            // d_p[i][j] 存储不再为0/1 而是具体长度
            d_p[i] = new int [len - i - 1];
        }
        for(int x = 0; x < len; x++){
            for(int y = 0; y < len - x - 1; y++){
                if(S[x] == S[x+y+1]){
                    d_p[x][y] = 1;
                    noFound = false;
                    res = S.substr(x,1);
                }
                else{
                    d_p[x][y] = 0;
                }
            }
        }
        if(noFound) 
            return "";
        // 开始考虑更长的字符串长度
        for(int current_len = 2; current_len < len; current_len ++){
            noFound = true;
            for(int x = 0; x < len - current_len; x++){
                for(int y = 0; y <= len - current_len - x -1; y++){
                    if(d_p[x][y] == current_len - 1 && S[x+current_len-1] == S[x+y+1+current_len-1]){
                        d_p[x][y]= current_len;
                        noFound = false;
                        res = S.substr(x,current_len);
                    }
                }
            }
            if(noFound){
                return res;
            }
        }
        return res;
    }
};
// v0.4 放弃线性规划 学习了一下后缀树和后缀数组  https://www.geeksforgeeks.org/pattern-searching-using-suffix-tree/
// https://www.geeksforgeeks.org/suffix-array-set-1-introduction/
// 用后缀数组来做 在后缀数组中相邻的两两比较
// 终于可以惹。。。
class Suffix{
public:
    int index;
    int rank[2];
};
int cmp(Suffix a, Suffix b){
    return (a.rank[0] == b.rank[0] )? (a.rank[1] < b.rank[1]? 1 : 0):(a.rank[0] < b.rank[0]? 1: 0);   
}
class Solution_4 {
public:
    string longestDupSubstring(string S) {
        int len = S.length();
        const char * c_style_str = S.c_str();
        Suffix * suffixArray = new Suffix[len];
        for(int i = 0; i < len; i++){
            suffixArray[i].index = i;
            suffixArray[i].rank[0] = c_style_str[i] - 'a';
            suffixArray[i].rank[1] = i != len -1 ? c_style_str[i+1] - 'a' : -1;
        }
        sort(suffixArray,suffixArray+len,cmp);
        int * indices = new int[len];
        for(int k = 4; k < 2*len;k*=2){
            int rank = 0;
            indices[suffixArray[0].index] = 0;
            int prev_rank = suffixArray[0].rank[0];
            suffixArray[0].rank[0] = rank;
            for(int i = 1;i < len; i++){
                indices[suffixArray[i].index] = i;
                if(suffixArray[i].rank[0] == prev_rank && suffixArray[i].rank[1] == suffixArray[i-1].rank[1]){
                    prev_rank = suffixArray[i].rank[0];
                    suffixArray[i].rank[0] = rank;
                }
                else{
                    prev_rank = suffixArray[i].rank[0];
                    suffixArray[i].rank[0] = ++rank;
                }
            }
            for(int i = 0; i< len; i++){
                int same_rank_index = suffixArray[i].index + k/2;
                suffixArray[i].rank[1] = same_rank_index < len ? suffixArray[indices[same_rank_index]].rank[0]: -1;
            }
            sort(suffixArray,suffixArray+len,cmp);
        }
        int longestDup = 0;
        int offset = 0;
        for(int i = len - 1; i > 0; i --){
            if(len - suffixArray[i].index < longestDup || len - suffixArray[i-1].index < longestDup)
                continue;
            if(longestDup != 0 && strncmp(c_style_str+suffixArray[i].index,c_style_str+suffixArray[i-1].index,longestDup) != 0)
                continue;
            while(c_style_str[suffixArray[i].index + longestDup] == c_style_str[suffixArray[i-1].index + longestDup]){
                longestDup ++;
                offset = suffixArray[i].index;
            }
        }
        if(longestDup == 0)
            return "";
        else
            return S.substr(offset,longestDup);

    }
};
int main (void){
    Solution_4 sol;
    cout<<sol.longestDupSubstring("banana");
    return 0;
}