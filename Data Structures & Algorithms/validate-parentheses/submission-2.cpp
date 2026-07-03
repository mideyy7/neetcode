class Solution {
public:
    bool isValid(string s) {
        std::map<char,char> mp = {{')', '('}, {'}', '{'}, {']','['}};
        std::stack<char> st;

        for (char c : s) {
            if (mp.find(c) != mp.end()){
                if (st.empty()) return false;
                char top = st.top(); st.pop();
                if (top != c) return false;
            } else {
                st.push(c);
            }
        }
        return (st.empty()) ? true : false;
        
    }
};
