class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        stack<string> op;
        int b = 0;
        int val = 0, a = 0;
        for(auto i: tokens){
            if(i == "+"){
                a = s.top();
                s.pop();
                b = s.top();
                val = a + b;
                s.pop();
                s.push(val);
            }
            else if(i == "-"){
                a = s.top();
                s.pop();
                b = s.top();
                val = b - a;
                s.pop();
                s.push(val);
            }
            else if(i == "*"){
                a = s.top();
                s.pop();
                b = s.top();
                val = b * a;
                s.pop();
                s.push(val);
            }
            else if(i == "/"){
                a = s.top();
                s.pop();
                b = s.top();
                val = b / a;
                s.pop();
                s.push(val);
            }
            else{
                s.push(stoi(i));
                val = stoi(i);
            }
            cout << i << " " << val << endl;
        }
        return val;
    }
};
