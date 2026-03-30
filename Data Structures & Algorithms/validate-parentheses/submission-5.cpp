class Solution {
public:
    bool isValid(string s) {
        stack<char> x;
        for(auto i: s){
            
            if(i == '(' or i == '{' or i == '['){
                x.push(i);
            }
            else{
                if (x.empty()) return false;

                if((i == ')') and (x.top() == '(') ){
                    x.pop();
                }
                else if((i == ']') and (x.top() == '[') ){
                    x.pop();
                }
                else if((i == '}') and (x.top() == '{') ){
                    x.pop();
                }
                else{
                    return false;
                }
                
            }
        }
        
        return x.empty();
    }
};
