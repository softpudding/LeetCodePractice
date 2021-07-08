class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int charsCount[256] = {0};
        int len1 = s1.size(), len2 = s2.size();
        if(len1 != len2)
            return false;
        for(int i = 0; i < len1; i++)
            charsCount[s1[i]]++;
        for(int i = 0; i < len1; i++)
            charsCount[s2[i]]--;
        for(int i = 0; i < 256; i++)
            if(charsCount[i])
                return false;
        return true;
    }
};