class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return is_palindrome(s, l + 1, r) || is_palindrome(s, l , r - 1);
            }
            l += 1;
            r -= 1;
        }
        return true;
        
    }

    bool is_palindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l += 1;
            r -= 1;
        }
        return true;
    }
};