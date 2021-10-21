// 50%
class MaxQueue {
private:
    int max;
    // 这个栈用来记录当前队列里 在pop之后会对当前最大值造成影响的一系列值
    deque<int> decreasingStack;
    // 这个是一个完整的队列
    list<int> fullList;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if(fullList.size()){
            return max;
        }
        return -1;
    }
    
    void push_back(int value) {
        fullList.push_back(value);
        while(!decreasingStack.empty() && decreasingStack.back() < value){
            decreasingStack.pop_back();
        }
        decreasingStack.push_back(value);
        max = decreasingStack.front();
    }
    
    int pop_front() {
        if(fullList.empty()){
            return -1;
        }
        int res = fullList.front();
        fullList.pop_front();
        if(res == decreasingStack.front()){
            decreasingStack.pop_front();
            max = decreasingStack.front();
        }
        return res;
    }
};