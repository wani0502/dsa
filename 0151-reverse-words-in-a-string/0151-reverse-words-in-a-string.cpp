class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = 0; 
        int n = s.size();
        while (i < n) {
            while (i < n && s[i] == ' ') {
                i++;
            }
            if (i < n) { 
                if (j > 0) {
                    s[j++] = ' ';
                }
                int start = j;
                while (i < n && s[i] != ' ') {
                    s[j++] = s[i++];
                }
                
               
                reverse(s.begin() + start, s.begin() + j);
            }
        }
        
       
        s.resize(j);
        
       
        reverse(s.begin(), s.end());
        
        return s;
    }
};