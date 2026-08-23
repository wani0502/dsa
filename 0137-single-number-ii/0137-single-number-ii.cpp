class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ones=0;
       int twos=0;
       for(int x:nums){
        ones=(ones^x)&~twos;
        twos=(twos^x)&~ones;
       }
        return ones;
    }
};