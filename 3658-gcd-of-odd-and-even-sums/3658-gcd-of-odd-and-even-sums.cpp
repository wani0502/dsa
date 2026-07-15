class Solution {
public:
    int gcd(int a,int b){
        if(a==0) return b;
        if(b==0) return a;
        if(a==b) return a;
        if(a>b) return gcd(a-b,b);
        return gcd(a,b-a);
    }
    int gcdOfOddEvenSums(int n) {
        int oddSum=n*n;
        int evenSum=n*(n+1);
        int ans=gcd(oddSum,evenSum);
        return ans;
    }
};