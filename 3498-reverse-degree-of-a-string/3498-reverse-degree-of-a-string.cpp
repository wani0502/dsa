class Solution {
public:
 
    int reverseDegree(string s) {
        int ans = 0;
        
        for (int i = 0; i < s.size(); i++) {
            
            int reversed_pos = 26 - (s[i] - 'a');
            ans += reversed_pos * (i + 1);
        }
        
        return ans;
    }
};