class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi=nums[0],mini=nums[0];
        for(int i=1;i<nums.size();i++){
            if(maxi<nums[i]) maxi=nums[i];
            if(mini>nums[i]) mini=nums[i];
        }
        int ans=gcd(maxi,mini);
        return ans;
    }
};