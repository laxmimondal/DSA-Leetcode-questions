#include <string>

class Solution {
private:
    bool valid(char ch) {
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {
            return true;
        }
        return false;
    }

    char lower(char ch) {
        if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') {
            return ch;
        } else {
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool checkPalindrome(const std::string& a) {
        int l = 0;
        int r = a.size() - 1;
        while (l <= r) {
            if (a[l] != a[r]) {
                return false;
            } else {
                l++;
                r--;
            }
        }
        return true;
    }

public:
    bool isPalindrome(std::string s) {
        // Remove non-alphanumeric characters
        std::string temp = "";
        for (int j = 0; j < s.size(); j++) {
            if (valid(s[j])) {
                temp.push_back(s[j]);
            }
        }
        // Convert to lowercase
        for (int j = 0; j < temp.size(); j++) {
            temp[j] = lower(temp[j]);
        }
        // Check if the string is a palindrome
        return checkPalindrome(temp);
    }
};
