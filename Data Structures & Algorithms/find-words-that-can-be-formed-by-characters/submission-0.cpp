class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> count_map;
        for (char c: chars){
            count_map[c]++;
        }

        int invalid = 0;
        int total = 0;
        for (string& word: words) {
            unordered_map<char, int> temp_map = count_map;
            total += word.size();
            for (char c: word) {
                if(!temp_map.count(c) || temp_map[c] == 0) {
                    invalid += word.size();
                    break;
                } else {
                    temp_map[c]--;
                }
            }
        }
        return total - invalid;
        
    }
};