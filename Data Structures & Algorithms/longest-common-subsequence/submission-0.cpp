class Solution {
public:
    int findCS(string text1, string text2, int i, int j, vector<vector<int>>& store){
        if (i >= store.size() || j >= store[0].size()){
            return 0;
        }
        if (store[i][j] != -1) return store[i][j];
        if (text1[i] == text2[j]) return store[i][j] = findCS(text1,text2,i+1,j+1, store) + 1;
        else return store[i][j] = max(findCS(text1,text2,i,j+1, store), findCS(text1,text2,i+1,j, store));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> store(text1.length(), vector<int>(text2.length(), -1));
        int ret = 0;
        ret = findCS(text1,text2, 0, 0, store);
        return ret;
    }
};
