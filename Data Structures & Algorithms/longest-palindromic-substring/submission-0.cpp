class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0;
        string result;
        for (int i = 0; i < s.size(); i++) {
            string word = "";
            for (int j = i; j < s.size(); j++) {
                word += s[j];
                if (isPalindrome(word)) {
                    if (word.size() > longest) {
                        result = word;
                        longest = word.size();
                    }
                }

            }
          
        }
        return result;
    }

        bool isPalindrome(string word) {
            int left = 0;
            int right = word.size() - 1;
            while (left < right) {
                if (word[left] != word[right]) return false;
                left += 1;
                right -= 1;
            }
            return true;
        }
        

};
