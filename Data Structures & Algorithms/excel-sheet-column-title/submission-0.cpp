class Solution {
public:
    string convertToTitle(int columnNumber) {
        /*
        single digit is btw 1 and 26. 

        24 % 26 = 24
        char c = 'A' + 24 = 'X'

        30 % 26 = 4 'D'
        30 // 26 = 1
        1 % 26 = 1  'A'. = 'AD'

        SC: 0(1)
        TC: not sure = 0(log 26n) because i divide by 26 each time


        What did i learn:
        note of 1-indexed and 0-indexed and their conversions
        printing to debug actually helps
        */

        std::string result = "";  // #include <string>
        int rem;
        while (columnNumber) {
            columnNumber--;
            rem = columnNumber % 26;
            // std:cout << "Remainder: " << rem << "\n"; // #include <iostream>
            char c = 'A' + rem;
            // std::cout << "Char(+A): " << c << "\n";
            result = c + result;
            columnNumber /=  26;
        }
        return result;
        
    }
};