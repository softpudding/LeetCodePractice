class Solution {
public:
    int multiply(int A, int B) {
        if(A == 0)
            return 0;
        else
        {
            return (A & 1 ? B : 0) + (multiply(A>>1,B) << 1);
        }
    }
};