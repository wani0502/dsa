class Solution {
public:
    string minWindow(string s, string t) {
       int s_ind=-1,cnt=0,minlen=INT_MAX,r=0,l=0;
       vector<int> hash(256,0);
       int n=s.size(),m=t.size();
       for(int i=0;i<m;i++){
        hash[t[i]]++;
       }
       while(r<s.size()){
        if(hash[s[r]]>0) cnt++;
        hash[s[r]]--;
        while(cnt==m){
            if(r-l+1<minlen){
                minlen=r-l+1;
                s_ind=l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0){
                cnt--;
            }
            l++;
        }
        r++;
       }
       return s_ind==-1?"":s.substr(s_ind,minlen);
    }
};