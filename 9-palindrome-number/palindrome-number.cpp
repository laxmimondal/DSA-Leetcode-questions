class Solution {
public:
    bool isPalindrome(int x) {
      long long revNum = 0;  // Use long long to handle overflow
       int dup = x;
          while (x > 0) {
            int ld = x % 10;
            revNum = (revNum * 10) + ld;

            // Remove the last digit from x
            x = x/ 10;
           // Check if the reversed number exceeds INT_MAX
            if (revNum > INT_MAX || revNum < INT_MIN) return false;
        }

        // Check if the original number is equal to its reverse
        return dup == revNum;
    }
};
