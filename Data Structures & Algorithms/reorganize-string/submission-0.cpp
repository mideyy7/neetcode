class Solution {
public:
    string reorganizeString(string s) {
        std::unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        std::priority_queue<std::pair<int,char>, std::vector<std::pair<int,char>>> pq;
        for (auto t : mp) {
            pq.push({t.second,t.first});
        }

        std::string result;
        std::pair<int,char> prev = {INT_MAX, 'a'};
        while (!pq.empty() || prev.first != INT_MAX) {
            if (!pq.empty()) {
                std::pair temp = pq.top(); pq.pop();
                if (prev.first != INT_MAX) pq.push(prev);
                temp.first--;
                result += temp.second;
                if (temp.first > 0) {
                    prev = temp;
                } else {
                    prev = {INT_MAX, 'a'};
                }
            } else {
                return "";
            }
        }
        return result;
        
    }
};