class Solution {
private:
    int validNums(string & s, int l, int r){
        if(l == r){
            if(s[l] == '*')
                // 1~9
                return 9;
            else if(s[l] == '0')
                // not possible
                return 0;
            else   
                // s[l]
                return 1;
        }
        else{
            // r = l+1
            if(s[l] == '1'){
                if(s[r] == '*'){
                    // 11~19
                    return 9;
                }
                else
                    return 1;
            }
            else if(s[l] == '2'){
                if(s[r] == '*'){
                    // 21~26
                    return 6;
                }
                else if(s[r] - '0' <= 6)
                    return 1;
                else
                    // 27~29
                    return 0;
            }
            else if(s[l] == '*'){
                if(s[r] == '*'){
                    // 11~19
                    // 21~26
                    return 15;
                }
                else if(s[r] - '0' <= 6){
                    return 2;
                }
                else{
                    return 1;
                }
            }
            else
                return 0;
        }
    }
public:
    int numDecodings(string s) {
        int size = s.size();
        if(size == 0)
            return 0;
        vector<long long> numDecodings(size,0);
        numDecodings[0] = validNums(s,0,0);
        for(int i = 1; i < size; i++){
            numDecodings[i] = numDecodings[i-1]*validNums(s,i,i)%1000000007;
            if(i-2 == -1){
                numDecodings[i] += validNums(s,i-1,i)%1000000007;
                numDecodings[i] %= 1000000007;
            }
            else{
                numDecodings[i] += numDecodings[i-2]*validNums(s,i-1,i)%1000000007;
                numDecodings[i] %= 1000000007;
            }
        }
        return numDecodings[size - 1];
    }
};