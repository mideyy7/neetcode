class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> check;
        for (char c: allowed) {
            check.insert(c);
        }
        int count = 0;
        for (string& word: words) {
            for (char c: word) {
                if (!check.count(c)) {
                    count += 1;
                    break;
                }
            }
        }
        return words.size() - count;
        
    }
};