/*
2018.12.28 题号 212 单词搜索 II
这个学期没怎么写代码，第一次做LeetCode上标注为困难的题目感觉就有点吃力了...
主要是感觉代码写的少了，然后写出来好多细节就注意不到了，所以一定要勤加练习才行啊。
而且写出来也不是很尽人意，只有50%这样子。还要继续改才可以。
实现其实不难，也没什么难想的，就是回溯的思想配合前缀树的数据结构。
当然要注意的是，我用了一个bool的表来表示哪些位置是搜索过的，以免造成无限的递归搜索。

2018.12.28 稍微优化了一下，60ms->48ms
*/
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

class Trie {
private:
    class Node{
    public:
        bool isWord;
        //hasBeenFound is special added for word search
        bool hasBeenFound;
        Node * children[26];
        Node(){
            hasBeenFound=false;
            isWord=false;
            for(int i=0;i<26;i++)
                children[i]=nullptr;
        };
    };

    Node * root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * cur_node= root;
        int i=0;
        while(i<word.size()){
            if(cur_node->children[word[i]-'a']==nullptr)
            {
                cur_node->children[word[i]-'a']=new Node();
            }
            cur_node=cur_node->children[word[i]-'a'];
            i++;
        }
        cur_node->isWord=true;

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        //if already hasbeen found just return false
        //because we don't want to add same word into results again and again
        Node * cur_node=root;
        int i=0;
        int length=word.size();
        while(i<length){
            if(!cur_node->children[word[i]-'a'])
            {
                return false;
            }
            cur_node=cur_node->children[word[i++]-'a'];
        }
        if(cur_node->isWord&&!cur_node->hasBeenFound)
        {
            cur_node->hasBeenFound=true;
            return true;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * cur_node=root;
        int i=0;
        int length=prefix.size();
        while(i<length){
            if(cur_node->children[prefix[i]-'a']==nullptr)
            {
                return false;
            }
            cur_node=cur_node->children[prefix[i++]-'a'];
        }
        return true;

    }
};
class Solution {
public:
    int COL,ROW;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> results;
        Trie * trie=initiateTrie(words);
        COL= board.size(), ROW= board[0].size();
        bool ** takenSteps=(bool **)new (bool * [COL]);
        for(int t=0;t<COL;t++)
            takenSteps[t]=new bool[ROW];
        string str="";
        for(int a=0;a<COL;a++)
            for(int b=0;b<ROW;b++)
                takenSteps[a][b]=false;
        for(int i=0;i<COL;i++)
            for(int j=0;j<ROW;j++)
            {
                str="";
                recursiveSearch(board,results,trie,i,j,str,0,takenSteps);
            }
        return results;

    }
    Trie * initiateTrie(vector<string>& words)
    {
        Trie * trie=new Trie;
        for(int i=0;i<words.size();i++)
            trie->insert(words[i]);
        return trie;
    }
    void recursiveSearch(vector<vector<char>> & board,vector<string>& results,Trie * trie,int x, int y,string &cur_string,int lastStep,bool ** takenSteps)
    {
        if(x<0||y<0||x>=COL||y>=ROW||takenSteps[x][y])
            return;
        cur_string.push_back(board[x][y]);
        takenSteps[x][y]=true;
        if(trie->startsWith(cur_string))
        {
            if(trie->search(cur_string)){
                results.push_back(cur_string);
                //but cur_string may as well be a prefix to another word
            }
            //1 left 2 right 3 down 4 up
            if(lastStep!=2)recursiveSearch(board,results,trie,x-1,y,cur_string,1,takenSteps);
            if(lastStep!=1)recursiveSearch(board,results,trie,x+1,y,cur_string,2,takenSteps);
            if(lastStep!=4)recursiveSearch(board,results,trie,x,y-1,cur_string,3,takenSteps);
            if(lastStep!=3)recursiveSearch(board,results,trie,x,y+1,cur_string,4,takenSteps);
        }
        else
        {
            cur_string.pop_back();
            takenSteps[x][y]=false;
            return;
        }
        cur_string.pop_back();
        takenSteps[x][y]=false;
    }
};

int main (void) 
{
    clock_t time_s=clock();
    vector<vector<char>> board={{'a','b','c','d','e','f','g'},{'a','b','c','d','e','f','g'},{'a','b','c','d','e','f','g'},{'a','b','c','d','e','f','g'}};
    vector<string> words={"abcdefg","aaa","bccd","aabbdd"};
    vector<string> results=Solution().findWords(board,words);
    clock_t time_e=clock();
    for(int i=0;i<results.size();i++)
        cout<<results[i]<<' ';
    cout<<"TIME:"<<(float)(time_e-time_s)/CLOCKS_PER_SEC;
    return 0;
}
int main (void)
{
    vector<vector<char>> board={{'a'},{'a'},{'b'},{'b'},{'a'}};
    vector<string> words={"baa","abba","baab","aba"};
    vector<string> results=Solution().findWords(board,words);
    for(int i=0;i<results.size();i++)
        cout<<results[i]<<' ';
    return 0;
}