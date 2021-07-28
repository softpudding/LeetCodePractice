class KthLargest {
private:
    priority_queue<int> maxHeap,minHeap;
    int heapSize,minHeapSize = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        int size = nums.size();
        heapSize = k;
        for(int i = 0; i < size; i++){
            maxHeap.push(nums[i]);
        }
        for(int i = 0; i < min(k,size); i++){
            minHeap.push(-1*maxHeap.top());
            minHeapSize++;
            maxHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(-1*val);
        minHeapSize++;
        if(minHeapSize > heapSize)
        {
            minHeap.pop();
            minHeapSize--;
        }
        return -1*minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */