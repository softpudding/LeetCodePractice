/*
题目：网络延迟时间 题号：743
这个题我看有评论说是最小生成树然后用了迪杰斯特拉算法...我觉得不对啊，这个应该是最短路径吧。
所以我用的是BFS的搜索算法。但是这个搜索算法确确实实很慢，搞得我有点迷茫。 
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // BFS which modifies result in process
        int time[N]={0};
        for(int i=0;i<N;i++){
            time[i]=INT32_MAX;
        }
        vector<int> edges[N];
        for(int i=0;i<times.size();i++){
            edges[times[i][0]-1].push_back(times[i][1]-1);
            edges[times[i][0]-1].push_back(times[i][2]);
        }
        time[K-1]=0;
        BFS(edges,time,K-1,0);
        int max=0;
        for(int i=0;i<N;i++){
            if(time[i]>max)
                max=time[i];
        }
        if(max==INT32_MAX)
            return -1;
        else return max;
    }
    void BFS(vector<int> edges[],int time[],int cur_node,int cur_time){

        for(int i=0;i<edges[cur_node].size();i+=2){
            if(cur_time+edges[cur_node][i+1]<time[edges[cur_node][i]]){
                time[edges[cur_node][i]]=cur_time+edges[cur_node][i+1];
                BFS(edges,time,edges[cur_node][i],cur_time+edges[cur_node][i+1]);
            }
        }
    }

};