class Solution {
public:
    int minimumPushes(string word) {
        // Step 1: Count frequency of each letter
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }

        // Step 2: Sort frequencies in descending order
        sort(freq.rbegin(), freq.rend());

        // Step 3: Assign letters to keys (8 keys available: 2 to 9)
        int totalPushes = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break; // No more letters left

            // Determine how many pushes this letter needs (1st pos = 1 push, 9th = 2 pushes, etc.)
            int pushesPerChar = (i / 8) + 1;
            totalPushes += freq[i] * pushesPerChar;
        }

        return totalPushes;
    }
};