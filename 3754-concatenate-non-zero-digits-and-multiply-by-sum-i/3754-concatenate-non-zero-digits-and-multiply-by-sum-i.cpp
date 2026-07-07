class Solution {
public:
    long long sumAndMultiply(int n) {
        long long val = 0;
        long long place = 1;
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;

            if (digit != 0) {
                sum += digit;
                val += 1LL * digit * place;
                place *= 10;
            }

            n /= 10;
        }

        return val * sum;
    }
};