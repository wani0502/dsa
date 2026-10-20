class Solution {
public:
    int maxi(vector<int>& ans){
        int m=INT_MIN;
        for(int i=0;i<ans.size();i++){
            if(m<ans[i]) m=ans[i];
        }
        return m;
    }
    bool isposs(int mid,vector<int>& a,int h){
        long long  ans=0;
        for(int i=0;i<a.size();i++){
            ans+=(a[i]+mid-1)/mid;
        }
        return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=maxi(piles);
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isposs(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            
        }
        }
        return ans;
    }
};