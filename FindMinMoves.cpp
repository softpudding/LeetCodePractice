class Solution {
private:
    inline int abs(int x){
        return x < 0 ?  -x : x;
    }
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        int size = machines.size();
        for(int i = 0; i < size; i++){
            sum += machines[i];
        }
        if(sum % size != 0){
            return -1;
        }
        int target = sum/size;
        vector<int> diffs(size,0);
        int minTimes = 0;
        for(int i = 0; i < size; i++){
            diffs[i] = machines[i] - target;
        }
        /* 从第0开始往后遍历
         * 对于第i个来说：
         * diffs[i]是我需要要的衣服数量（正负都有可能） 第i台洗衣机需要diffs[i]数量的衣服等价于
         * 第i+1台洗衣机需要diffs[i]+diffs[i+1]件衣服 为了完成这个等价目标需要abs(diffs[i])次操作
         * diffs[i+1]是我后面的这个人在第i台洗衣机把衣服给他之前他需要的衣服数量
         * 如果他是负数 无所谓 
         * 如果他是正数 由于他最后必然是把他所有的diffs[i]件衣服都给出了 所以他需要diffs[i+1]次操作
         */
        for(int i = 0; i < size; i++){
            if(diffs[i] != 0){
                if(abs(diffs[i]) > minTimes){
                    minTimes = abs(diffs[i]);
                }
                if(diffs[i+1] > minTimes){
                    minTimes = diffs[i+1];
                }
                diffs[i+1] += diffs[i];
            }
        }
        return minTimes;

    }
};