class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ng;
        vector<int> ps;
        vector<int> ans(nums.size());
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ps.push_back(nums[i]);
            } else if(nums[i]<0) {
                ng.push_back(nums[i]);
            }
        }
        
        for(int i = 0; i < ps.size(); i++){
            ans[2 * i] = ps[i];
        }
        
        for(int i = 0; i < ng.size(); i++){
            ans[2 * i + 1] = ng[i];
        }
        
        return ans;
    }
};