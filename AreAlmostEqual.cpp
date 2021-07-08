class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int len = s1.size();
        int difct = 0;
        char s1c, s2c;
        for(int i = 0; i < len; i++){
            if(s1[i] != s2[i]){
                difct++;
                if(difct == 1){
                    s1c = s1[i];
                    s2c = s2[i];
                }
                else if(difct == 2){
                    if(s1c != s2[i] || s2c != s1[i]){
                        return false;
                    }
                }
            }
        }
        return difct == 0 || difct == 2;
    }
};