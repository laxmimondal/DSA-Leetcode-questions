class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;

        long long revNum = 0;  // Use long long to handle overflow
        int dup = x;

        while (x > 0) {
            int ld = x % 10;
            revNum = (revNum * 10) + ld;

            // Remove the last digit from x
            x /= 10;

            // Check if the reversed number exceeds INT_MAX
            if (revNum > INT_MAX) return false;
        }

        // Check if the original number is equal to its reverse
        return dup == revNum;
    }
};
