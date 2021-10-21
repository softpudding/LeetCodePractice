// 属于是数学题 还蛮有意思的
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log(buckets)/log(minutesToTest/minutesToDie+1));
    }
};