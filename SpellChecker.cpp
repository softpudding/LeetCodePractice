#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        // 由于存在三种比较方式 我们提供三种字典
        // 原始的 全部小写的 全部元音字母被'*'替代的
        // 由于vector线性搜索时间会超标 所以改用map
        unordered_map<string,int> original_wordlist;
        unordered_map<string,int> lower_case_wordlist;
        unordered_map<string,int> non_vowel_wordlist;
        int size = wordlist.size();
        for(int i = 0; i < size; i++){
            string s = wordlist[i];
            string * s1 = new string(s), * s2 = new string(s);
            int len = s.length();
            for(int j = 0; j < len; j ++){
                if(s[j] >= 'A' && s[j] <= 'Z'){
                    (*s1)[j] += 32;
                    (*s2)[j] += 32;
                }
                if((*s1)[j] == 'a' || (*s1)[j] == 'e' || (*s1)[j] == 'i' || (*s1)[j] == 'o' || (*s1)[j] == 'u'){
                    (*s2)[j] = '*';
                }
            }
            original_wordlist.insert(std::pair<string,int>(s,i));
            if(lower_case_wordlist.find(*s1) == lower_case_wordlist.end())
                lower_case_wordlist.insert(std::pair<string,int>(*s1,i));
            if(non_vowel_wordlist.find(*s2) == non_vowel_wordlist.end())
                non_vowel_wordlist.insert(std::pair<string,int>(*s2,i));
        }
        vector<string> results;
        int q_size = queries.size();
        bool hasFound = false;
        for(int i = 0; i < q_size; i++){
            hasFound = false;
            string q_string = queries[i];
            // 在original_wordlist里面找
            if(original_wordlist.find(q_string) != original_wordlist.end()){
                results.push_back(wordlist[original_wordlist[q_string]]);
                continue;
            }
            int q_len = q_string.length();
            for(int j = 0; j < q_len; j++){
                if(q_string[j] >= 'A' && q_string[j] <= 'Z')
                    q_string[j] += 32;
            }
            // 在lower_case_wordlist里找
            if(lower_case_wordlist.find(q_string) != lower_case_wordlist.end()){
                results.push_back(wordlist[lower_case_wordlist[q_string]]);
                continue;
            }
            for(int j = 0; j < q_len; j++){
                if(q_string[j] == 'a' || q_string[j] == 'e' || q_string[j] == 'i' || q_string[j] == 'o' || q_string[j] == 'u')
                    q_string[j] = '*';
            }
            // 在non_vowel_wordlist里找
            if(non_vowel_wordlist.find(q_string) != non_vowel_wordlist.end()){
                results.push_back(wordlist[non_vowel_wordlist[q_string]]);
                continue;
            }
            results.push_back("");

        }
        return results;
        
    }
};
int main (void){
    string wordlist[4] = {
        "KiTe","kite","hare","Hare"
    };
    string queries[10] = {
        "kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"
    };
    vector<string> v_wordlist(wordlist,wordlist+4);
    vector<string> v_queries(queries,queries+10);
    Solution solution;
    vector<string> results = solution.spellchecker(v_wordlist,v_queries);
    for(int i = 0; i < results.size();i++){
        if(results[i] == "")
            std::cout<<"\"\" ";
        else
            std::cout<<"\""<<results[i]<<"\" ";
    }
    return 0;
}