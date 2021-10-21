class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int flag = false;
        digits[size - 1] += 1;
        if(digits[size - 1] == 10){
            flag = true;
            digits[size - 1] = 0;
        }
        else{
            flag = false;
        }
        for(int i = size - 2; i >= 0; i--){
            if(flag){
                digits[i]++;
                if(digits[i] == 10){
                    digits[i] -= 10;
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};