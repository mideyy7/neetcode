class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int pointer = s.size() - 1;
        while (pointer >= 0 && s[pointer] == ' '){
            pointer -= 1;
        }
        int end;
        if(pointer != -1) {
            end = pointer;
        } else {
            return 0;
        }
        while (pointer >= 0 && s[pointer] != ' ') {
            pointer -= 1;
        }
        cout << end << "\n";
        cout << pointer << "\n";
        int result =  end - pointer;  
        return result;
    }
};