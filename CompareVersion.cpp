#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
class Solution {
private:
    vector<int> version2revisions(string & s){
        int l = 0;
        int r = s.find('.');
        vector<int> res;
        while(r != string::npos){
            res.push_back(stoi(s.substr(l,r-l)));
            l = r+1;
            r = s.find('.',l);
        }
        r = s.size();
        res.push_back(stoi(s.substr(l,r-l)));
        return res;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> revisions1,revisions2;
        revisions1 = version2revisions(version1);
        revisions2 = version2revisions(version2);
        int size1 = revisions1.size(), size2 = revisions2.size();
        int i = 0;
        int min = MIN(size1,size2);
        int max = MAX(size1,size2);
        for(i = 0; i < min; i++){
            if(revisions1[i] < revisions2[i]){
                return -1;
            }
            else if(revisions2[i] < revisions1[i]){
                return 1;
            }
            else{
                continue;
            }
        }
        for(; i < max; i++){
            if(size1 < size2 && revisions2[i] != 0){
                return -1;
            }
            else if(size1 > size2 && revisions1[i] != 0){
                return 1;
            }
        }
        return 0;

    }
};