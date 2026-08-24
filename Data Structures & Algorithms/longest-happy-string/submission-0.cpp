class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        std::priority_queue<std::pair<int, char>, std::vector<std::pair<int,char>>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        std::string result = "";
        int streak = 0;
        char prev = 'd';
        while (!pq.empty()) {
            auto [count, letter] = pq.top(); pq.pop();
            if (letter == prev && streak == 2) {
                if (pq.empty()) return result;
                auto [count2, letter2] = pq.top(); pq.pop();
                pq.push({count, letter});
                count = count2;
                letter = letter2;
                streak = 0;
            } else if (letter != prev) {
                streak = 0;
            }
            prev = letter;
            streak++;
            result += letter;
            count--;
            if (count > 0) pq.push({count, letter});
        }
        return result;    
    }
};