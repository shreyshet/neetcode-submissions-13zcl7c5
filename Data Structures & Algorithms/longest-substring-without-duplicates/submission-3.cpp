class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> um;
        int l = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            if (um.find(s[r]) != um.end()) {
                l = max(um[s[r]] + 1, l);
            }
            um[s[r]] = r;
            res = max(res, r - l + 1);
            for(auto i: um){
                cout << i.first << " " << i.second << " ";
            }
            cout << endl;
            cout << r << " " << l << endl;
        }
        
        return res;

    }
};
