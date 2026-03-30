class MinStack {
    stack<int> inp;
    stack<int> minstack;
public:
    MinStack() {
    }
    
    void push(int val) {
        this->inp.push(val);
        if (this->minstack.empty()) this->minstack.push(val);
        else this->minstack.push(min(val, this->minstack.top()));
    }
    
    void pop() {
        if (!inp.empty())
        {
            this->inp.pop();
            this->minstack.pop();
        }
    }
    
    int top() {
        return inp.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
