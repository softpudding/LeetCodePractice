#include <iostream>
#include <cassert>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
// a class to represent the formula
enum ExpressionTypes{
    // 0 or 1
    EXP_BOOL,
    // a formula that consists of a|b
    EXP_OR,
    // a formula that consists of a&b
    EXP_AND,
    // a formula that is included in a parenthesis (a)
    EXP_PAR
};
class Expressions{
public:
    ExpressionTypes type;
    // used with EXP_OR or EXP_AND
    Expressions * left;
    Expressions * right;
    // only used with type EXP_PAR
    Expressions * sub_expressions;
    // only used with type EXP_INT
    bool val;
    // only generated after calculation
    bool calculatedVal;

    Expressions(){
        left = nullptr;
        right = nullptr;
        sub_expressions = nullptr;
    }
    bool calculate(){
        if(type == EXP_PAR){
            calculatedVal = sub_expressions->calculate();
        }
        else if(type == EXP_AND){
            calculatedVal = left->calculate()&right->calculate();
        }
        else if(type == EXP_OR){
            calculatedVal = left->calculate()|right->calculate();
        }
        else{
            calculatedVal = val;
        }
        return calculatedVal;
    }
    // minOps to change the value rerpesented by this expression
    int minOps(){
        if(type == EXP_PAR){
            return sub_expressions->minOps();
        }
        else if(type == EXP_BOOL){
            return 1;
        }
        else if(type == EXP_AND){
            if(calculatedVal == true){
                // then left and right must all be one
                // cout<<"EXP_AND left:"<<left->minOps()<<" right:"<<right->minOps()<<" res:"<<min(left->minOps(),right->minOps());
                return min(left->minOps(),right->minOps());
            }
            else{
                if(left->calculatedVal == true && right->calculatedVal == false){
                    // change and to or is easiest
                    return 1;
                }
                else if(left->calculatedVal == false && right->calculatedVal == true){
                    return 1;
                }
                else{
                    assert(left->calculatedVal == false && right->calculatedVal == false);
                    // change and to or, change left or right
                    return min(left->minOps(),right->minOps())+1;
                }
            }
        }
        else{
            // EXP_OR
            if(calculatedVal == true){
                if(left->calculatedVal == true && right->calculatedVal == false){
                    return 1;
                }
                else if(left->calculatedVal == false && right->calculatedVal == true){
                    return 1;
                }
                else{
                    assert(left->calculatedVal == true && right->calculatedVal == true);
                    return 1+min(left->minOps(),right->minOps());
                }
            }
            else{
                return min(left->minOps(),right->minOps());
            }
        }
    }
};
class Scanner{
private:
    string & expStr;
    int * parenMap;
public:
    Scanner(string & s):expStr(s){
        int size = s.size();
        parenMap = new int[size];
        memset(parenMap,0,size);
        vector<int> parenthesisPairsStack;
        for(int i = 0; i < size;i++){
            if(s[i] == '('){
                parenthesisPairsStack.push_back(i);
            }
            else if(s[i] == ')'){
                int a = parenthesisPairsStack.back();
                parenthesisPairsStack.pop_back();
                parenMap[a] = i;
                parenMap[i] = a;
            }
        }
    }
    Expressions * getExpressionsInSubStr(int start, int end){
        int i = end;
        int j = i;
        Expressions * res = new Expressions();
        //cout<<"start: "<<start<<" end:"<<end<<endl;
        switch(expStr[i]){
            case ')':{
                // find the corresponding ')'
                int pairCt = 0;
                j = parenMap[i];
                assert(j >= start);
                if(j == start){
                    // just return the parenthesis expression
                    res->type = EXP_PAR;
                    res->sub_expressions = getExpressionsInSubStr(j+1,i-1);
                }
                else if(expStr[j-1] == '&'){
                    res->left = getExpressionsInSubStr(start,j-2);
                    res->type = EXP_AND;
                    res->right = getExpressionsInSubStr(j+1,i-1);
                }
                else if(expStr[j-1] == '|'){
                    res->left = getExpressionsInSubStr(start,j-2);
                    res->type = EXP_OR;
                    res->right = getExpressionsInSubStr(j+1,i-1);
                }
                else{
                    assert(0);
                }
                break;
            }
            default:{
                assert(expStr[i] == '0' || expStr[i] == '1');
                // simplify because boolean expression only
                if(j == start){
                    res->type = EXP_BOOL;
                    res->val = expStr[i] == '1';
                }
                else{
                    res->right = new Expressions();
                    res->right->type = EXP_BOOL;
                    res->right->val = expStr[i] == '1';
                    j--;
                    if(expStr[j] == '&'){
                        res->type = EXP_AND;
                        res->left = getExpressionsInSubStr(start,j-1);
                    }
                    else if(expStr[j] == '|'){
                        res->type = EXP_OR;
                        res->left = getExpressionsInSubStr(start,j-1);
                    }
                    else{
                        assert(0);
                    }
                }
                break;
            }
            
        }
        return res;
    }
    Expressions * getExpressions(){
        return getExpressionsInSubStr(0,expStr.size()-1);
    }  
};
class Solution {
public:
    int minOperationsToFlip(string expression) {
        // scan through expression and generate data structrues
        Scanner s(expression);
        Expressions * exps = s.getExpressions();
        bool initVal = exps->calculate();
        //cout<<"init val : "<<initVal<<endl;
        int minOps = exps->minOps();
        return minOps;
    }
};