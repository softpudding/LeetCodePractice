/*
题目：汉明距离 题号：461
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z=x^y;
        int sum=0;
        for(int i=0;i<31;i++){
            sum+=(z>>i)&0x1;
        }
        return sum;
    }
};