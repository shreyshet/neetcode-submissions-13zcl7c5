class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um1, um2;
        if( s.length() != t.length()){
            return false;
        }
        else{
        for(auto i: s){
            um1[i]++;
        }
        for(auto i: t){
            um2[i]++;
        }
        for (auto i: um1){
            if (um2[i.first] != i.second){
                return false;
            }
        }
        }
        return true;

    }
};
