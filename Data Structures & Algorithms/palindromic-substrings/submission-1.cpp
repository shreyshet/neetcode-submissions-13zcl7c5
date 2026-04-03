class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        int ind = 0;
        int flag = 0;

        for(int i = 0; i < n; i++){
            for (int j = 0; i - j >= 0 && i + j < n; j++) {
                if (s[i - j] == s[i + j]) {
                    flag += 1;
                    ind = j;
                } 
                else break;
            }
            //if (flag) cout << i << " " << ind <<  endl; 
            count += flag;
            flag = 0;
            for  (int j = 0; i - j >= 0 && i + j + 1 < n; j++){
                if (s[i - j] == s[i + j + 1]) {
                    flag += 1;
                    ind = j;
                }   
                else break;
            }
            //if (flag) cout << i << " " << ind <<  endl;
            count += flag;
            flag = 0;
        }
        return count;
    }
};
