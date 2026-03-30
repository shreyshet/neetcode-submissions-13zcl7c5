class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> s1map;
        for(auto i: s1 ){
            s1map[i]++;
        }
        if(s2.length() < s1.length()) return false;
        for(int l = 0; l <= (s2.length()-s1.length()); l++){
            unordered_map<char,int> s2map;
            cout << endl << l << endl;
            string a = s2.substr(l, s1.length());
            cout << a << endl;
            for(auto i: a){
                s2map[i]++;
            }
            for (auto i : s2map){
                cout << endl << i.first << " " <<  i.second;
            }
            cout << endl;
            if(s1map == s2map){
                return true;
            }   
        }

        return false;
    }
};
