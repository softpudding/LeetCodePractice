class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.size() == 0)
            return nums;
        vector<int> res;
        int l = 0, r = 0;
        int midVal = abs(nums[0]);
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(abs(nums[i]) < midVal){
                midVal = abs(nums[i]);
                l = r = i;
            }
        }
        res.push_back(nums[l]*nums[l]);
        r = l + 1;
        l = l - 1;
        while(l >= 0 || r < size){
            if(l < 0){
                res.push_back(nums[r]*nums[r]);
                r++;
                continue;
            }
            if(r >= size){
                res.push_back(nums[l]*nums[l]);
                l--;
                continue;
            }
            if(abs(nums[l]) < abs(nums[r])){
                res.push_back(nums[l]*nums[l]);
                l--;
            }
            else{
                res.push_back(nums[r]*nums[r]);
                r++;
            }
        }
        return res;
    }
};