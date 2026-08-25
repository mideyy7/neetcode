class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        /*
        use 2 q's -> current and next

        current: all jobs that capital <= w .... max_heap: large profits
        next: all jobs that capital > w .... min_heap: small capital

        after each iteration: pop from next and add to capital if capital <= w

        */

        int n = profits.size();
        auto comp = [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        };

        auto check = [](const std::pair<int,int>& a , const std::pair<int,int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        };

        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, decltype(check)> current(check);
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, decltype(comp)> next(comp);
        for (int i = 0; i < n; i++) {
            std::pair<int,int> t = {profits[i], capital[i]};
            if (capital[i] <= w) {
                current.push(t);
            } else {
                next.push(t);
            }
        }

        while (!current.empty() && k > 0) {
            std::pair<int,int> t = current.top(); current.pop();
            w+= t.first;
            k--;
            while (!next.empty() && next.top().second <= w) {
                t = next.top(); next.pop();
                current.push(t);
            }
        }
        return w; 
    }
};