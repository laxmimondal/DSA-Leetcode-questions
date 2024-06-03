class Solution {
public:
    
    int hammingWeight(uint32_t n) {
        int count = 0;  // Initialize a counter for the '1' bits
        while (n>0) {  
           count = count + (n&1);  
           n=n>>1;
        }
        return count;
           
    }
};
