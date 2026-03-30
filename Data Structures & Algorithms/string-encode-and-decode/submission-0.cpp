class Solution {
public:

    string encode(vector<string>& strs) {
        string send;
        for(auto str: strs){
            send.append(to_string(str.length()) + "#" + str);

        }
        // for (auto k: send){
        //     cout << k;
        // }
        return send;

    }

    vector<string> decode(string s) {
        vector<string> rec;
        for(int i=0; i<s.length();){
            size_t pos = s.find('#', i);
            int len = stoi(s.substr(i, pos - i));
            string content = s.substr(pos + 1, len);
            rec.push_back(content);
            i = pos + 1 + len;
        }
        return rec;
    }
};
