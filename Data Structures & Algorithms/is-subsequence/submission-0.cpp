class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_pointer = 0;
        int t_pointer = 0;

        while (t_pointer < t.size()) {
            while (t_pointer < t.size() && t[t_pointer] != s[s_pointer]) {
                t_pointer += 1;
            }
            if( t_pointer < t.size() &&  (s[s_pointer] == t[t_pointer])) {
                s_pointer += 1;
                t_pointer += 1;
            }
        }
        if (s_pointer == s.size()) {
            return true;
        } else {
            return false;
        } 
    }
};