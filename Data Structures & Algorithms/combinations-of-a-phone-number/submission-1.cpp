class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string subset;
        if(digits.empty()){
            return ret;
        }
        unordered_map<char,vector<char>> um;
        
        um['2'] = {'a','b','c'};
        um['3'] = {'d','e','f'};
        um['4'] = {'g','h','i'};
        um['5'] = {'j','k','l'};
        um['6'] = {'m','n','o'};
        um['7'] = {'p','q','r','s'};
        um['8'] = {'t','u','v'};
        um['9'] = {'w','x','y','z'};

        dfs(0, digits, ret, subset, um);

        return ret;
    }
private:
    void dfs(int i, string digits, vector<string>& ret, string& subset, unordered_map<char,vector<char>> um){ 
        if(i >= digits.length()){
            ret.push_back(subset);
            return;
        }
        for(auto j: um[digits[i]])
        {   
            subset.push_back(j);
            dfs(i+1,digits, ret, subset, um);
            subset.pop_back();
        }
    }

};
