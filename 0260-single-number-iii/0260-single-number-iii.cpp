class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xora=0;
        for(int x:nums){
            xora=xora^x;
        }
        long long right=xora&(-xora);
        int b1=0,b2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&right)b1=b1^nums[i];
            else{
                b2=b2^nums[i];
            }
        }
        return {b1,b2};
    }
};