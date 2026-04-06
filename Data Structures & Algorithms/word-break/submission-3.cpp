class Solution {
public:
    bool makeWord(string s, int i, unordered_map<string,int>& wordDictMap, vector<int>& memo){
        if(i == s.size()) return true;
        if(memo[i] != -1) return memo[i];
        //if( i + len > s.size()) return false;
         
        for (int len = 1; i + len <= s.size(); len++) {
            string temp = s.substr(i, len);
            if (wordDictMap.count(temp)) {

                if (makeWord(s, i + len, wordDictMap, memo)) { 
                    return memo[i] = 1; // Found a path!
                }
            }
        }
        return memo[i] = 0; 
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> wordDictMap;
        int count = 0;
        for (auto i: wordDict){
            wordDictMap[i]++;
        }
        vector<int> memo(s.size(), -1);

        return makeWord(s, 0, wordDictMap, memo); 
    }
};
