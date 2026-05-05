class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                if (m.find(s[i]) != m.end() && m[s[i]] != t[i]) {
                    return false;
                }
                
            }
            m[s[i]] = t[i];
            m[t[i]] = s[i];
        }
        return true;
        
    }
};