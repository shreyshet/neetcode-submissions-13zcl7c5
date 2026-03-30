class Solution {
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
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> retstr;
        if (strs.empty()) return retstr;
        for (int i = 0; i < strs.size(); i++) {
            int flag = 0;
            for (int k = 0; k < retstr.size(); k++) {
                if(isAnagram(retstr[k][0], strs[i])) {
                    retstr[k].push_back(strs[i]);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                retstr.push_back({strs[i]});
            }
        }
        return retstr;
    }
};
