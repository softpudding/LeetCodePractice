#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int res = 0;
        int topVal = 0, bottomVal = 0;
        vector<int> decStack;
        for(int i = 0; i < size; i++){
            if(decStack.empty()){
                decStack.push_back(i);
                topVal = height[i];
            }
            else{
                if(height[i] <= topVal){
                    decStack.push_back(i);
                    topVal = height[i];
                }
                else{
                    while(height[i] > topVal){
                        int oldTopVal = topVal;
                        decStack.pop_back();
                        if(decStack.size() > 0){
                            topVal = height[decStack.back()];
                            res += (i - decStack.back() - 1)*(min(topVal,height[i]) - oldTopVal);
                        }
                        else{
                            break;
                        }
                    }
                    decStack.push_back(i);
                    topVal = height[i];
                }
            }
        }
        return res;

    }
};