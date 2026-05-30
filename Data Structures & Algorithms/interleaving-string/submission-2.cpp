class Solution {
public:
    int checkInterleave(string &s1, string &s2, string &s3, int i, int j, int k){
        if(k == s3.size()) return 1;
        else if (i == s1.size() and j == s2.size()) return 0;
        int a = 0;
        int b = 0;
        if(i< s1.size() and s1[i] == s3[k]) a = checkInterleave(s1,s2,s3,i+1,j,k+1);
        if(j< s2.size() and s2[j] == s3[k]) b = checkInterleave(s1,s2,s3,i,j+1,k+1); 
        return (a or b);
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        return checkInterleave(s1,s2,s3,0,0,0);

    }
};
