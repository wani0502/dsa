class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the only overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine if the final result should be negative
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert both to negative to prevent overflow issues with INT_MIN
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;

        int quotient = 0;

        // Perform long division using bit shifting
        // Since both are negative, "dividend <= divisor" actually means absolute dividend >= absolute divisor
        while (dividend <= divisor) {
            int tempDivisor = divisor;
            int multiple = -1; // Accumulate negatively

            // Shift left until we would exceed the dividend or overflow the 32-bit limit
            // (INT_MIN >> 1) is -1073741824, which ensures tempDivisor << 1 doesn't underflow INT_MIN
            while (tempDivisor >= (INT_MIN >> 1) && dividend <= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            // Subtract the highest found multiple
            dividend -= tempDivisor;
            quotient += multiple;
        }

        // Return the properly signed quotient
        return isNegative ? quotient : -quotient;
    }
};