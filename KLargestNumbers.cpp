#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
using namespace std;
void swap(vector<int> & arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// lastV是上一次用来完成对数组的分割操作的数字的最新下标
// 在现在的input数组中：input[0] ~ input[lastV-1] 小于input[lastV]
// input[lastV+1] ~ input[input.size()-1] 大于input[lastV]
int doPart(vector<int> & input, int low, int high){
    if(low == high){
        return low;
    }
    int l = low, r = high;
    int val = input[low];
    while(l<r){
        while(l < r && input[r] >= val){
            r--;
        }
        swap(input,l,r);
        while(l < r && input[l] <= val){
            l++;
        }
        swap(input,l,r);
    }
    return l;
}

vector<int> KLargestNumbers(vector<int> & input, int k){
    int lastVPos = 0;
    int size = input.size() - 1;
    vector<int> smaller,bigger;
    int val = input[0];
    int valPos = 0;
    lastVPos = doPart(input,0,size-1);
    int left = 0;
    int right = size - 1;
    // 在每一次循环中 [left..right]是需要我们做分割的子区域
    while(lastVPos != size - k - 1){
        // lastValPos在左边 需要在右边找新的k
        if(lastVPos < size-k-1){
            val = input[lastVPos+1];
            valPos = lastVPos+1;
            left = lastVPos+1;
            lastVPos = doPart(input,left,right);
        }
        // lastValPos在右边 需要在左边找新的k
        else{
            val = input[lastVPos-1];
            valPos = lastVPos-1;
            right = lastVPos-1;
            lastVPos = doPart(input,left,right);
        }
    }
}