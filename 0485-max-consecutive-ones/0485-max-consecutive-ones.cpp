class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int r=0,cnt=0,ans=0;
       while(r<nums.size()){
            if(nums[r]==1){
                cnt++;
            }
            if(nums[r]==0){
                ans=max(cnt,ans);
                cnt=0;
            }
            r++;
       } 
       ans=max(cnt,ans);
       return ans;
    }
};