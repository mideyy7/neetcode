class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[2] < b[2];
        });

        auto comp = [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
            return a.first > b.first;
        };

        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, decltype(comp)>pq(comp);

        int current = 0;
        int n = trips.size();

        for (int i = 0; i < n; i++) {
            int num = trips[i][0], begin = trips[i][1], end = trips[i][2];
            while (!pq.empty() && pq.top().first <= begin) {
                current -= pq.top().second;
                pq.pop();
            }
            current += num;
            if (current > capacity) return false;
            pq.push({end, num});
        }
        return true;  
    }
};