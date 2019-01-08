/*
题目：数据流的中位数 题号：295 124ms，93.36%
这个题我的思路就是在数据结构里保持一个最大堆一个最小堆
最大堆里是前一半元素 最小堆是后一半元素 然后可以从最大堆的最大值和最小堆的最小值里
根据size的关系找到中位数
*/
class MinHeap{
private:
    vector<int> heap;
    int parent(int i){return (i-1)/2;}
    int left(int i){return i*2+1;}
    int right(int i){return i*2+2;}
    void sift_up(int i){
        if(!i) return;
        while(heap[i]<heap[parent(i)]){
            int temp=heap[i];
            heap[i]=heap[parent(i)];
            heap[parent(i)]=temp;
            i=parent(i);
        }
    }
    void sift_down(int i){
        if(left(i)>heap.size()-1)
            return;
        do{
            i=left(i);
            if(i+1<=heap.size()-1&&heap[i+1]<heap[i])
                i=i+1;
            if(heap[parent(i)]>heap[i]){
                int temp=heap[i];
                heap[i]=heap[parent(i)];
                heap[parent(i)]=temp;
            }
            else return ;
        }while(left(i)<=heap.size()-1);
    }
    void _delete(int i){
        int x=heap[i],y=heap[heap.size()-1];
        heap.pop_back();
        if(i==heap.size())
            return;
        heap[i]=y;
        if(y>x){
            sift_down(i);
        }
        else
            sift_up(i);
    }

public:
    int DeleteMin(){
        int res=heap[0];
        _delete(0);
        return res;
    }
    void MakeHeap(){
        for(int i=parent(heap.size()-1);i>=0;i--){
            sift_down(i);
        }
    }
    void Insert(int x){
        heap.push_back(x);
        if(heap.size()>1)
            sift_up(heap.size()-1);
    }
    int MinVal(){
        return heap[0];
    }
    MinHeap(){}
};
class MaxHeap{
private:
    vector<int> heap;
    int parent(int i){return (i-1)/2;}
    int left(int i){return i*2+1;}
    int right(int i){return i*2+2;}
    void sift_up(int i){
        if(!i) return;
        while(heap[i]>heap[parent(i)]){
            int temp=heap[i];
            heap[i]=heap[parent(i)];
            heap[parent(i)]=temp;
            i=parent(i);
        }
    }
    void sift_down(int i){
        if(left(i)>heap.size()-1)
            return;
        do{
            i=left(i);
            if(i+1<=heap.size()-1&&heap[i+1]>heap[i])
                i=i+1;
            if(heap[parent(i)]<heap[i]){
                int temp=heap[i];
                heap[i]=heap[parent(i)];
                heap[parent(i)]=temp;
            }
            else return ;
        }while(left(i)<=heap.size()-1);
    }
    void _delete(int i){
        int x=heap[i],y=heap[heap.size()-1];
        heap.pop_back();
        if(i==heap.size())
            return;
        heap[i]=y;
        if(y<x){
            sift_down(i);
        }
        else
            sift_up(i);
    }

public:
    int DeleteMax(){
        int res=heap[0];
        _delete(0);
        return res;
    }
    void MakeHeap(){
        for(int i=parent(heap.size()-1);i>=0;i--){
            sift_down(i);
        }
    }
    void Insert(int x){
        heap.push_back(x);
        if(heap.size()>1)
            sift_up(heap.size()-1);
    }
    int MaxVal(){
        return heap[0];
    }
    MaxHeap(){}
};

class MedianFinder {
public:
    MaxHeap left_heap;
    MinHeap right_heap;
    int size=0;
    /** initialize your data structure here. */
    MedianFinder() {
        size=0;

    }

    void addNum(int num) {
        //if size=2n than n in left and n in right
        // median is left_heap.maxNode+right_heap.minNode/2
        //else if size=2n+1 than n+1 in left and n in right
        if(!size){
            left_heap.Insert(num);
            size++;
            return ;
        }
        if(size%2){
            if(num<left_heap.MaxVal()){
                right_heap.Insert(left_heap.DeleteMax());
                left_heap.Insert(num);
            }
            else
                right_heap.Insert(num);
        }
        else
        {
            if(num>right_heap.MinVal()){
                left_heap.Insert(right_heap.DeleteMin());
                right_heap.Insert(num);
            }
            else
                left_heap.Insert(num);
        }
        size++;
    }

    double findMedian() {
        if(size%2)
            return (double)left_heap.MaxVal();
        else return (double)(left_heap.MaxVal()+right_heap.MinVal())/2.0;
    }
};