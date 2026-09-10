class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int maxLength = 0;
        unordered_map<int, int> basket; // Stores fruit type and its count
        
        for (int right = 0; right < fruits.size(); right++) {
            // Add the current fruit to the basket
            basket[fruits[right]]++;
            
            // If we have more than 2 types of fruit, shrink the window
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            
            // Update the maximum amount of fruits we can pick
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};