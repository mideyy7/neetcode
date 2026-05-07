class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        /*
        0. if n -> move original pointer
        1, if char at index equal -> increment the pointers
        2. if not equal and digit: -> add to n
        3. if not equal -> return false
        */
        int n = 0;
        int original = 0;
        int fresh = 0;
        while (fresh < abbr.size()) {
            if (isdigit(abbr[fresh])) {
                if (abbr[fresh] - '0' == 0) return false;
                while (fresh < abbr.size() && isdigit(abbr[fresh])) {
                    n = (n * 10) + abbr[fresh] - '0';
                    fresh += 1;
                }
            original += n;
            n = 0;
            continue;
            }
            // cout << original << "\n" << fresh << "\n";
            if (original >= word.size() || word[original] != abbr[fresh]) {
                return false;
            }
            original += 1;
            fresh += 1;
        }
        return true;
    }
};