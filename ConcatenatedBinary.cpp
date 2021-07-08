class Solution {
private:
    const static int MODULO = 1000000007;
public:
    int concatenatedBinary(int n) {
        int i = 1;
        int shift = 1;
        int res = 0;
        while(i <= n){
           res = (((long long)res<<shift))%MODULO;
           res += i;
           res %= MODULO;
           i++;
           if((i&(i-1)) == 0)
                shift++;
        }
        return res;
    }
};