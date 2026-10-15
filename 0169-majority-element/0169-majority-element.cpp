class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int ans=0;
        for(int num : nums){
            if(count==0){
                ans=num;
            }
            if(num==ans){
                count++;
            }
            else{
                count--;
            }
        }
        return ans;
    }
};