/*
2018.12.27
每个Node含一个children数组，一个bool值
children数组代表接下来可能的26种走向，bool值代表当前是否为一个单词/还是仅仅是一个前缀
*/

class Trie {
private:
    class Node{
        public:
        bool isWord;
        Node * children[26];
        Node(){
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
        Node * cur_node=root;
        int i=0;
        while(i<word.size()){
            if(cur_node->children[word[i]-'a']==nullptr)
            {
                return false;
            }
            cur_node=cur_node->children[word[i++]-'a'];
        }
        if(cur_node->isWord)
        return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * cur_node=root;
        int i=0;
        while(i<prefix.size()){
            if(cur_node->children[prefix[i]-'a']==nullptr)
            {
                return false;
            }
            cur_node=cur_node->children[prefix[i++]-'a'];
        }
        return true;
        
    }
};

