#include <set>
#include <string>

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        std::set<std::string> unique_emails;
        for (std::string email : emails) {
            int split = email.find('@');
            std::string domain = "";
            for(int i = 0; i < split; i++) {
                if (email[i] == '.') {
                    continue;
                } else if (email[i] == '+') {
                    break;
                } else {
                    domain += email[i];
                }
            }
            unique_emails.insert(domain + email.substr(split));
        }
        return unique_emails.size();    
    }
};