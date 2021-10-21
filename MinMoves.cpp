class Solution {
public:
    int minMoves(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        int min = nums[0];
        int sum = nums[0];
        for(int i = 1; i < size; i++){
            if(nums[i] < min){
                min = nums[i];
            }
            sum += nums[i];
        }
        return sum - min*size;
    }
};