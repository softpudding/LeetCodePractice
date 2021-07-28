class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colorCt[3] = {0};
        int size = nums.size();
        for(int i = 0; i < size;i++)
            colorCt[nums[i]]++;
        for(int i = 0; i < size; i++){
            if(colorCt[0] > 0){
                nums[i] = 0;
                colorCt[0]--;
            }
            else if(colorCt[1] > 0){
                nums[i] = 1;
                colorCt[1]--;
            }
            else{
                nums[i] = 2;
                colorCt[2]--;
            }
        }
    }
};