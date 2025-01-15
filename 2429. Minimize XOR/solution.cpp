class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Count the number of set bits in num2
        int countSetBitsNum2 = __builtin_popcount(num2);

        int result = 0;

        // Step 1: Set bits in `result` from `num1`'s bits (most significant ones first)
        for (int i = 31; i >= 0 && countSetBitsNum2 > 0; --i) {
            if (num1 & (1 << i)) {
                result |= (1 << i); // Set the bit in `result`
                --countSetBitsNum2; // Decrease the number of set bits to add
            }
        }

        // Step 2: If more set bits are needed, set them starting from the least significant bit
        for (int i = 0; i <= 31 && countSetBitsNum2 > 0; ++i) {
            if (!(result & (1 << i))) { // If the bit is not already set
                result |= (1 << i); // Set the bit
                --countSetBitsNum2; // Decrease the count
            }
        }

        return result;
    }
};
