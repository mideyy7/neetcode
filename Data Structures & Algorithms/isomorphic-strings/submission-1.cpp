class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_map<char,char> m2;
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); ++i) {
       
            if (m.count(s[i]) && m[s[i]] != t[i]) {
                    return false;
            }            
            if (m2.count(t[i]) && m2[t[i]] != s[i]) {
                    return false;
            }
                
         
            m[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        return true;
        
    }
};