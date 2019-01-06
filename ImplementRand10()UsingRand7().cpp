/*题目：用Rand7()实现Rand10() 题号：470
这个题目主要是考你的优化基本功。72ms，99.08%
要善用switch。
*/
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a=rand7(),b=rand7();
        switch(a){
            case 1:
                switch(b){
                    case 5:case 6:case 7:return 2;
                    default:return 1;
                }
            case 2:
                switch(b){
                    case 1:return 2;
                    case 2:case 3:case 4:case 5:return 3;
                    default:return 4;
                }
            case 3:
                switch(b){
                    case 1:case 2:return 4;
                    case 3:case 4:case 5:case 6:return 5;
                    default:return 6;
                }
            case 4:
                switch(b){
                    case 1:case 2:case 3:return 6;
                    default:return 7;
                }
            case 5:
                switch(b){
                    case 1:case 2:case 3:case 4:return 8;
                    default:return 9;
                }
            case 6:
                switch(b){
                    case 1:return 9;
                    case 2:case 3:case 4:case 5:return 10;
                    default:return rand10();
                }
            default:
                return rand10();
        }
                    
        
        
    }

};