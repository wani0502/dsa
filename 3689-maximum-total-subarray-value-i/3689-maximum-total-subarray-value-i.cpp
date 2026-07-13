class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans=0;
        int maxi=nums[0],mini=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>maxi) maxi=nums[i];
            if(nums[i]<mini) mini=nums[i];
        }
        ans=1LL*(maxi-mini)*k;
        return ans;
    }
};