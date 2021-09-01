#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
class StackOfPlates {
private:
    int capability;
    vector<vector<int>> stacks;
public:
    StackOfPlates(int cap) {
        capability = cap;
        stacks = vector<vector<int>&>();
    }
    
    void push(int val) {
        if(stacks.size() == 0 || stacks[stacks.size()-1].size() == capability){
            stacks.push_back(vector<int>());
        }  
        vector<int> & subStack = stacks[stacks.size()-1];
        subStack.push_back(val);
    }
    
    int pop() {
        vector<int> & subStack = stacks[stacks.size()-1];
        int res;
        res = subStack.back();
        subStack.pop_back();
        if(subStack.size() == 0){
            stacks.pop_back();
        }
        return res;
    }
    
    int popAt(int index) {
        vector<int> & subStack = stacks[index];
        int res = subStack.back();
        subStack.pop_back();
        if(subStack.size() == 0){
            for(int i = index+1; i < stacks.size(); i++){
                stacks[i - 1] = stacks[i];
            }
            stacks.pop_back();
        } 
        return res;

    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */