/*
 * 题目：存在重复元素II 题号：219 44ms 46%set
 * 用了一个map来记录每个值出现的位置 但是效率看起来并不理想
 * 大概看了一下别人的答案 好像把map换成hashset会快一些
 */
#include <vector>
#include <map>
using namespace std;
// 哈希表方法
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0) return false;
        map<int,int> v_p_map;
        std::map<int,int>::iterator it;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            int val = nums[i];
            it = v_p_map.find(val);
            if(it == v_p_map.end()){
                v_p_map[val] = i;
            }
            else{
                if(i - it->second <= k){
                    return true;
                }
                else{
                    it->second = i;
                }
            }
        }
        return false;
    }
};