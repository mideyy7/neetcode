class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        sort(strs.begin(), strs.end());
        std::string curr_prefix = strs[0];
        for (int index  = 1; index < strs.size(); index++) {
            std::string current = strs[index];
            int j = 0;
            while (j < curr_prefix.size() && curr_prefix[j] == current[j]) {
                j += 1;
            }
            curr_prefix = curr_prefix.substr(0,j);
        }
        return curr_prefix;
        
    }
};