class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = 0; // Initialize the result variable
        
        // Iterate through the string from left to right
        for (int i = 0; i < s.length(); ++i) {
            // Add the integer value of the current symbol to the result
            result += romanValues[s[i]];
            // Check for special cases where subtraction is required
            if (i > 0 && romanValues[s[i]] > romanValues[s[i - 1]]) {
                result -= 2 * romanValues[s[i - 1]]; // Subtract twice the previous symbol's value
            }
        }
        
        return result;
    }
};