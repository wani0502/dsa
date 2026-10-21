class Solution {
public:
    bool canSplit(vector<int>& nums,int k,int limit){
        int count=1;
        long long sum=0;
        for(int x : nums){
            if(sum+ x<=limit){
                sum+=x;
            }
            else{
                sum=x;
                count++;
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0,high=0;
        for(int i=0;i<n;i++){
            low=max(low,nums[i]);
            high+=nums[i];
        }
        int ans=0;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(canSplit(nums,k,mid)){
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