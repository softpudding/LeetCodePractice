#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
class Solution {
public:
    /* 
     * 这道题是完全按照输入范围来做的 O(1)方法
     * 已知输入数值在0~2^31-1之间
     */
    int addDigits(int num) {
        int n = num%10 + (num/10%10) + (num/100%10) + (num/1000%10) + + (num/10000%10)
        + (num/100000%10) + + (num/1000000%10) + + (num/10000000%10) + + (num/100000000%10)
        + (num/1000000000%10);
        n = n%10 + n/10;
        return n%10 + n/10;
    }
};