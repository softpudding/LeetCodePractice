class Solution {
public:
    int lengthOfLastWord(string s) {
        int startIndex = -1, endIndex = -1, tempStartIntdex = -1;
        int size = s.size();
        for(int i = 0; i < size; i++){
            if(s[i] != ' '){
                if(tempStartIntdex == -1){
                    startIndex = tempStartIntdex = i;
                }
                endIndex = i;
            }
            else{
                tempStartIntdex = -1;
            }
        }
        if(endIndex == -1)
            return 0;
        return endIndex - startIndex + 1;
    }
};