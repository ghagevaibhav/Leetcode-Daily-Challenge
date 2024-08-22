class Solution {
public:
    int findComplement(int num) {
        // Initialize mask with all bits set to 1 (e.g., 0xFFFFFFFF)
        unsigned mask = ~0;
        
        // Shift the mask left until it is just larger than the number
        while(mask & num) 
            mask = mask << 1;
        
        // The complement is found by flipping all bits of 'num' and
        // then using XOR with the mask to zero out the leading 1 bits
        return ~num ^ mask;
    }
};
