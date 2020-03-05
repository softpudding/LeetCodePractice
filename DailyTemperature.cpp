/*
 * 题目：每日温度 题号：728 52ms 89.40%
 * 做法是维持了一个队列+二分查找 时间复杂度在nlogn级别
 * 不过值得注意的是这个队列我用了比较多的空间 这样子可以避免一些插入/删除操作占用过多时间
 * 如果用一个大小和T数组相同的vector来实现这个队列 在特殊情况下这个题目时间复杂度会变成n^2 
 * 这里需要留心
 */
#include <vector>
#include <algorithm>
using namespace std;
struct ValAndIndex{
    int val;
    int index;
    ValAndIndex():val(0),index(0){}
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int size = T.size();
        vector<int> res(size,0);
        // 用三倍的存储空间 以避免vector的insert erase等操作
        ValAndIndex * undealt_queue = new ValAndIndex [3*size];
        int l_bound = size, u_bound = -1;
        for(int i = 0; i < size; i++){
            // 根据三倍的存储空间后续进行修改
            // TODO
            int cur_val = T[i];
            int low = l_bound, high = u_bound, mid = (low + high) / 2;
            int mid_val = undealt_queue[mid].val;
            if(u_bound == - 1){
                undealt_queue[size].index = i;
                undealt_queue[size].val = cur_val;
                u_bound = size;
                continue;
            }
            else{
                /* undealt_queue是一个有序队列
                 * 他的起始是 l_bound 终点是 u_bound
                 * 我们需要在队列里找到第i个元素
                 * 他满足 undealt_queue[i]->val >= cur_val && undealt_queue[i-1]->val <= cur_val
                 */ 
                int magic_index = -1;      
                while(true){
                    mid = (low + high) / 2;
                    mid_val = undealt_queue[mid].val;
                    if(mid_val < cur_val){
                        if(mid + 1 <= u_bound && undealt_queue[mid + 1].val >= cur_val){
                            // 满足情况二
                            // 处理
                            // 0..mid 都是小于当前T的
                            magic_index = mid + 1;
                            break;
                        }
                        else if(mid + 1 <= u_bound && undealt_queue[mid + 1].val < cur_val){
                            // mid 和 mid + 1 处的值都小于我们的cur_val
                            low = mid + 1;
                            mid = (low + high) / 2;
                            continue;
                        }
                        else{
                            magic_index = u_bound + 1;
                            break;
                        }
                    }
                    else{
                        if(mid - 1 >= l_bound && undealt_queue[mid - 1].val < cur_val){
                            magic_index = mid;
                            break;
                        }
                        else if(mid - 1 >= l_bound && undealt_queue[mid - 1].val >= cur_val){
                            // mid 和 mid-1 处的值都大于我们的cur_val
                            high = mid - 1;
                            mid = (low + high) / 2;
                            continue;
                        }
                        else{
                            //mid 是对头 且队伍中所有元素值都比当前这个大
                            magic_index = l_bound;
                            break;
                        }

                    }
                }
                // 处理magic_index
                if(magic_index == l_bound){
                    l_bound --;
                    undealt_queue[l_bound].index = i;
                    undealt_queue[l_bound].val = cur_val;
                }
                else if(magic_index == u_bound + 1){
                    for(int j = l_bound; j <= u_bound; j++){
                        res[undealt_queue[j].index] = i - undealt_queue[j].index;
                        undealt_queue[j].val = 0;
                    }
                    u_bound = l_bound;
                    undealt_queue[l_bound].index = i;
                    undealt_queue[l_bound].val = cur_val;
                }
                else{
                    for(int j = l_bound; j < magic_index; j++){
                        res[undealt_queue[j].index] = i - undealt_queue[j].index;
                    }
                    l_bound = magic_index - 1;
                    undealt_queue[l_bound].index = i;
                    undealt_queue[l_bound].val = cur_val;
                }
            }
        }

        return res;
    }
};