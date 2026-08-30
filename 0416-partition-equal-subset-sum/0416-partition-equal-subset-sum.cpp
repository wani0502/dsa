class Solution {
public:

    bool isSubsetSum(vector<int> arr, int target) {
        int n = arr.size();
        vector<bool> prev(target + 1, false);
        vector<bool> curr(target + 1, false);
        prev[0] = true;
        curr[0] = true; 
        if(arr[0] <= target) {
            prev[arr[0]] = true;
        }
        for(int i = 1; i < n; i++) {
            for(int tar = 1; tar <= target; tar++) {   
                bool nt = prev[tar];
                bool t = false;  
                if(arr[i] <= tar) {
                    t = prev[tar - arr[i]]; 
                } 
                curr[tar] = t || nt;
            }
            prev = curr;
        }
        return prev[target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x: nums){
            sum+=x;
        }
        if(sum%2!=0) return false;
        return isSubsetSum(nums,sum/2);
    }
};