class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> um;
        int ret = 0;
        int l = 0;
        int rep = 0;
        int mfreq = 0;

        for(int r = 0; r < s.length(); r++){
            um[s[r]]++;
            mfreq = max(mfreq, um[s[r]]);

            //cout << endl << l << " " << r << " "<< mfreq << " " << k << endl;

            while(((r-l+1)-mfreq)>k){
                um[s[l]]--;
                l++;
                //cout << " reducing " << s[l] << " and sliding, l->" << l <<  endl;
            }
            cout << endl;
            ret = max(ret,r-l+1);
             
        }

        return ret;
    }
};
