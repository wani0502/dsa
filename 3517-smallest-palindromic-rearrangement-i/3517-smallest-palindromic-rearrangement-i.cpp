class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        int k=n/2;
        string left=s.substr(0,k);
        sort(left.begin(),left.end());
        string result=left;
        if(n%2!=0){
            result+=s[k];
        }
        string right=left;
        reverse(right.begin(),right.end());
        result+=right;
        return result;
    }
};