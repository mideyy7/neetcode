class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (carry == 0) return digits;
            int total = digits[i] + carry;
            digits[i] = total % 10;
            carry = total / 10;
        }
        if (carry == 0) {
            return digits;
        }
        vector<int> result {carry};
        for (int digit : digits) {
            result.push_back(digit);
        }
        return result;
    }
};
