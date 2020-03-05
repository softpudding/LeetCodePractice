/*
 * 面试题10.03 搜索旋转数组 12ms 95%
 * 挺简单的 主要是考虑几个cornorcase 其他的用二叉搜索就行了
 */
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& arr, int target) {
        if(arr.size() == 0)
            return -1;
        int max_val = 0, max_index = 0;
        int size = arr.size();
        for(int i = 0; i < size; i++){
            if(arr[i]>max_val){
                max_index = i;
                max_val = arr[i];
            }
        }
        int min_index = (max_index + 1) % size;
        int low = 0, high = size-1, mid = (low + high) / 2;
        while(arr[(mid + min_index) % size] != target){
            if(low >= high){
                return -1;
            }
            if(arr[(mid + min_index) % size] < target){
                low = mid + 1;
                mid = (low + high)/2;
            }
            else{
                high = mid - 1;
                mid = (low + high)/2;
            }
        }
        mid = (mid + min_index) % size;
        if(arr[0] == arr[mid])
            return 0;
        while(arr[mid - 1] == arr[mid] && mid >= 1){
            mid --;
        }
        return mid;
    }
};