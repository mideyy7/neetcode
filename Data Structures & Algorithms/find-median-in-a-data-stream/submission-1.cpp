class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;

    // keep max heap greater
public:
    MedianFinder() {
        
    }
    void resize() {
        int val;
        if (max_heap.size() > min_heap.size() + 1) {
            val = max_heap.top(); max_heap.pop();
            min_heap.push(val);
        } else if (min_heap.size() > max_heap.size()) {
            val = min_heap.top(); min_heap.pop();
            max_heap.push(val);
        }
    }
    
    void addNum(int num) {
        // 1 , 2, 3, 4 max heap.         5, 6, 7,min heap
        if (!max_heap.empty() && num < max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }
        resize();
    }
    
    double findMedian() {
        if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        } else {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
        
    }
};
