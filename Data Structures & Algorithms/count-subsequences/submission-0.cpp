class Solution {
public:
    int findCS(string text1, string text2, int i, int j, vector<vector<int>>& store){
        if (i > store.size() || j > store[0].size()){
            return 0;
        }
        if (j == store[0].size() and i <= store.size()) {
            return 1;
        }
        if (i == store.size()) return 0;
        if (store[i][j] != -1) return store[i][j];
        if (text1[i] == text2[j]) {
            return store[i][j] = findCS(text1,text2,i+1,j+1, store) + findCS(text1,text2,i+1,j, store);
        }
        else return store[i][j] = findCS(text1,text2,i+1,j, store);
    }
    int numDistinct(string s, string t) {
        if (t.length() > s.length()){
            return 0;
        }
        vector<vector<int>> store(s.length(), vector<int>(t.length(), -1));
        int ret = 0;
        ret = findCS(s,t, 0, 0, store);
        return ret;
        
    }
};
