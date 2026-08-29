class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        int result = 0;
        if (dead.count("0000")) return -1;
        deque<string> dq;
        unordered_set<string> visited;
        dq.push_back("0000");
        visited.insert("0000");

        while (!dq.empty()) {
            int n = dq.size();
            while (n--) {
                string t = dq.front(); dq.pop_front();
                if (t == target) return result;
                for (int i = 0; i < 4; i++) {
                    char o = t[i];
                    char a = (((t[i] - '0') + 1) % 10) + '0';
                    char b = ((10 + (t[i] - '0') - 1) % 10) + '0';
                    t[i] = a;
                    if (!dead.count(t) && !visited.count(t)){
                        dq.push_back(t);
                        visited.insert(t);
                    } 
                    t[i] = b;
                    if (!dead.count(t) && !visited.count(t)){
                        dq.push_back(t);
                        visited.insert(t);
                    } 
                    t[i] = o;
                } 
            }
            result++;

        }
        return -1;
    }
};