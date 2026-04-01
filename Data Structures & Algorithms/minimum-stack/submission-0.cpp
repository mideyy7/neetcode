class MinStack {
    private:
        std::vector<int> stack;
        std::vector<int> min_stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        if (min_stack.empty()) {
            min_stack.push_back(val);
        } else {
            min_stack.push_back(std::min(min_stack.back(), val));
        } 
    }
    
    void pop() {
        stack.pop_back();
        min_stack.pop_back();
        
    }
    
    int top() {
        return stack.back();   
    }
    
    int getMin() {
        return min_stack.back();
        
    }
};
