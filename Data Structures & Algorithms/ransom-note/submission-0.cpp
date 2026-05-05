class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        /*
        vector<int> letters(26, 0);
        iterate through magazine and count each letter
        letters[magazine[i] - 'a']++

        iterate through ransomenote and decrement letters
        after decrement if it becomes negative return false

        return true after loops complete
        O(N) -> TIME COMPLEXITY
        O(26) -> SPACE COMPLEXITY
        */

        vector<int> letters(26, 0);
        for(char c: magazine) {
            letters[c - 'a'] += 1;
        }
        for(char c: ransomNote) {
            letters[c - 'a'] -= 1;
            if (letters[c - 'a'] < 0) return false; 
        }
        return true;
        
    }
};