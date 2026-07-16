class Solution {
public:
    // long long gcd(int a,int b){
    //     if(a==0) return 1LL*b;
    //     if(b==0) return 1LL*a;
    //     if(a>b) return gcd(a-b,b);
    //     return gcd(a,b-a);
    // }
    long long gcdSum(vector<int>& nums) {
        vector<int> prefix_gcd(nums.size());
        int maxi=nums[0];
        prefix_gcd[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            prefix_gcd[i]=std::gcd(maxi,nums[i]);
        }
        sort(prefix_gcd.begin(),prefix_gcd.end());
        int i=0,j=nums.size()-1;
        long long sum=0;
        while(i<j){
            sum+=std::gcd(prefix_gcd[i],prefix_gcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};