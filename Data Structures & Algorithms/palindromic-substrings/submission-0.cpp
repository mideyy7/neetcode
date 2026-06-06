class Solution {
public:
    int countSubstrings(string s) {
        int total = 0;
        for (int i = 0; i < s.size(); ++i) {
            string word = "";
            for (int j = i; j < s.size(); ++j) {
                word += s[j];
                if (isPalindrome(word)) {
                    total += 1;
                }
            }
        }
        return total;
        
    }

    bool isPalindrome(string word) {
        int left {0};
        int right  = word.size() - 1;
        while (left < right) {
            if (word[left] != word[right]) return false;
            left += 1;
            right -= 1;
        }
        return true;
    }
};
