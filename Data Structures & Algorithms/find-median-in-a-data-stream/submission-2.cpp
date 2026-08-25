class MedianFinder {
private:
        static inline auto comp = [](int a , int b) {
            return a > b;
        };
        std::priority_queue<int, vector<int>> lower;
        std::priority_queue<int, vector<int>, decltype(comp)> upper{comp};
public:
    MedianFinder() {}
    
    void addNum(int num) {
        lower.push(num);
        upper.push(lower.top());
        lower.pop();

        if (upper.size() > lower.size() + 1) {
            lower.push(upper.top());
            upper.pop();        
        } 
    }
    
    double findMedian() {
        int check = lower.size() + upper.size();
        if (check % 2 != 0) return upper.top();
        return (lower.top() + upper.top()) / 2.0;
    }
};
