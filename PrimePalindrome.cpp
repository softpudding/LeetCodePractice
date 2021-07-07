#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
class Solution {
private:
    static inline int pow10(int n){
        switch(n){
            case 0:
                return 1;
            case 1:
                return 10;
            case 2:
                return 100;
            case 3:
                return 1000;
            case 4:
                return 10000;
            case 5:
                return 100000;
            case 6:
                return 1000000;
            case 7:
                return 10000000;
            case 8:
                return 100000000;
            case 9:
                return 1000000000;
            case 10:
                return 10000000000;
            case 11:
                return 100000000000;
            default:
                assert(0);
        }
    } 
    /*
     * 比较有效的判断质数方法：
     * 通常而言一个质数会是6n+1或者6n+5 其中n>=0
     * 因为显然 6n+2 = 2*(3n+1) 6n+3 = 3*(2n+1) 6n+4 = 2*(3n+2)
     * 都不是质数
     */
    static bool isPrime(int n){
        if(n <= 1)
            return false;
        if(n == 2 || n == 3 || n == 5){
            return true;
        }
        if(n % 6 != 5 && n % 6 != 1){
            return false;
        }
        int k = 1;
        for(int i = 2; i*i <= n; i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }
    /* 
     * 基于给出的k位的n生成一个t位（t必须是2k或者2k-1）的palindrome
     * 例如输入12 2 4 返回1221 输入12 2 3 返回121
     */
    static int getPalindrome(int n, int k, int t){
        int res = 0;
        int a = 1, b = 1;
        a = pow10(k-1);
        if(t == 2*k){
            // 结果的前k位
            res += n*a*10;
            // 填充结果的后k位
            while(a){
                res += (n/a%10)*b;
                b *= 10;
                a /= 10;
            }
        }
        else if(t == 2*k - 1){
            // 结果的前k位
            res += n*a;
            while(a > 1){
                res += (n/a%10)*b;
                b *= 10;
                a /= 10;
            }
        }
        else
            assert(0);
        return res;
    }
    static inline int digitsOf(int n){
        int res = 0;
        while(n){
            res++;
            n /= 10;
        }
        return res;
    }
public:
    /*
     * 思路很简单：先按照升序生成Pilindrome
     * 然后去测试他是不是prime 
     * 按照升序生成Palindrome的方法基于 if a > b than palindrome of a > palindrome of b 这个思路来做
     */
    int primePalindrome(int n) {
        int digitsOfN = digitsOf(n);
        // d是用于生成回文数字的“原料”的位数
        int digitsOfMaterial = digitsOfN % 2 ? digitsOfN/2+1 : digitsOfN/2;
        // d是用于生成回文数字的“原料”的最小值
        int material =pow10(digitsOfMaterial-1);
        int palindrome = 0;
        // 当前生成的palindrome的位数
        int currentDigits = digitsOfN;
        while(true){
            // 检查material是不是需要更新
            if(material == pow10(digitsOfMaterial)){
                if(digitsOfMaterial*2 == currentDigits){
                    // 从生成abba型回文串变成abcba型回文串
                    digitsOfMaterial++;
                    currentDigits++;
                }
                else if(digitsOfMaterial*2 - 1 == currentDigits){
                    // 从生成aba型变成abba型
                    currentDigits++;
                    material = pow10(digitsOfMaterial-1);
                }
            }

            palindrome = getPalindrome(material,digitsOfMaterial,currentDigits);
            if(palindrome < n){
                material++;
                continue;
            }
            if(isPrime(palindrome)){
                return palindrome;
            }
            else{
                //cout<<material;
                material++;
            }
        }
        return 0;
    }
};