class Solution {
private:
    long long getNum(string & s, int & i){
        assert(s[i] >= '0' && s[i] <= '9');
        long long res = s[i] - '0';
        long long factor = 10;
        --i;
        while(i < s.size() && i >= 0 && s[i] >= '0' && s[i] <= '9'){
            //cout<<"res:"<<res<<endl;
            res = res + factor*(s[i] - '0');
            factor *= 10;
            --i;
        }
        //cout<<"getNum:"<<res<<endl;
        return res;
    }

public:
    int calculate(string s) {
        vector<long long> numStack;
        vector<char> operatorStack;
        int size = s.size();
        int i = size - 1;
        for(i = size - 1; i >= 0; i--){
            if(s[i] >= '0' && s[i] <= '9'){
                //cout<<s[i]<<endl;
                numStack.push_back(getNum(s,i));
                i++;
            }
            else if(s[i] == ' '){
                continue;
            }
            else if(s[i] == '('){
                while(operatorStack.back() != ')'){
                    char op = operatorStack.back();
                    operatorStack.pop_back();
                    long long num1 = numStack.back();
                    numStack.pop_back();
                    long long num2 = numStack.back();
                    numStack.pop_back();
                    if(op == '+'){
                        numStack.push_back(num1+num2);
                    }
                    else if(op == '-'){
                        numStack.push_back(num1-num2);
                    }
                    else{
                        assert(0);
                    }
                }
                operatorStack.pop_back();
            }
            else{
                if(i == 0 || s[i-1] == '('){
                    numStack.back() = s[i] == '+' ? numStack.back(): - numStack.back();
                }
                else
                    operatorStack.push_back(s[i]);
            }
        }
        //cout<<1;
        while(numStack.size() != 1){
            char op = operatorStack.back();
            operatorStack.pop_back();
            long long num1 = numStack.back();
            numStack.pop_back();
            long long num2 = numStack.back();
            numStack.pop_back();
            if(op == '+'){
                numStack.push_back(num2+num1);
            }
            else if(op == '-'){
                numStack.push_back(num1-num2);
            }
            else{
                assert(0);
            }
        }
        return numStack[0];
    }
};