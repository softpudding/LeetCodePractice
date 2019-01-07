/*
题目：第k个最小的素数分数 题号：786
这题大概花了我一万年时间吧，前面没有用最小堆来做，今天上午复习算法顺手写了个最小堆，然后就ac了。
但是还是不快，速度57%。理论上来说，最小堆让这个算法的时间上界是O(klogn)。
*/
class Node{
public:
    float val;
    int index;
    Node(int i,float x):index(i),val(x){}
};
class MinHeap{
private:
    vector<Node *> heap;
    int parent(int i){return (i-1)/2;}
    int left(int i){return i*2+1;}
    int right(int i){return i*2+2;}
    void sift_up(int i){
        if(!i) return;
        while(heap[i]->val<heap[parent(i)]->val){
            Node * temp=heap[i];
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
            if(i+1<=heap.size()-1&&heap[i+1]->val<heap[i]->val)
                i=i+1;
            if(heap[parent(i)]->val>heap[i]->val){
                Node * temp=heap[i];
                heap[i]=heap[parent(i)];
                heap[parent(i)]=temp;
            }
            else return ;
        }while(left(i)<=heap.size()-1);
    }
    void _delete(int i){
        Node * x=heap[i],* y=heap[heap.size()-1];
        heap.pop_back();
        if(i==heap.size())
            return;
        heap[i]=y;
        if(y->val>x->val){
            sift_down(i);
        }
        else
            sift_up(i);
    }
public:
    Node * DeleteMin(){
        Node * res=heap[0];
        _delete(0);
        return res;
    }
    void MakeHeap(){
        for(int i=parent(heap.size()-1);i>=0;i--){
            sift_down(i);
        }
    }
    void Insert(Node * x){
        heap.push_back(x);
        if(heap.size()>1)
            sift_up(heap.size()-1);
    }
    Node * MinNode(){
        return heap[0];
    }
    MinHeap(){}
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        float temp=0,min=0;
        int temp_p=0,temp_q=A.size()-1,size=0,new_pos=0;
        vector<int> p_can={0,1};
        vector<int> q_can={A.size()-2,A.size()-1};
        MinHeap minHeap;
        minHeap.Insert(new Node(0,(float)A[0]/A[A.size()-2]));
        minHeap.Insert(new Node(1,(float)A[1]/A[A.size()-1]));
        for(int i=2;i<=K;i++){

            Node * min=minHeap.DeleteMin();
            temp_p=p_can[min->index];
            temp_q=q_can[min->index];

            q_can[min->index]--;

            if(temp_q-1>temp_p)
                minHeap.Insert(new Node(min->index,(float)A[temp_p]/A[temp_q-1]));

            free(min);

            if(temp_p==p_can.size()-1){
                p_can.push_back(temp_p+1);
                q_can.push_back(A.size()-1);
                minHeap.Insert(new Node(p_can.size()-1,(float)A[temp_p+1]/A[A.size()-1]));
                }
            }
            //rearrange sorted_can

        vector<int> result={A[temp_p],A[temp_q]};
        return result;

    }
};
