class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnta=0,cntb=0,cntc=0;
        int l=0,r=0;
        int ans=0;
        while(r<s.size()){
            if(s[r]=='a') cnta++;
            else if(s[r]=='b') cntb++;
            else cntc++;
            while(cnta>=1 && cntb>=1 &&cntc>=1){
                ans+=(s.size()-r);
                if(s[l]=='a') cnta--;
                else if(s[l]=='b') cntb--;
                else cntc--;
                l++;

            }
            r++;
        }
        return ans;
    }
};