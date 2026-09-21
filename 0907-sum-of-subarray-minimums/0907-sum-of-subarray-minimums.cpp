class Solution {
public:
    vector<int> nse(vector<int>& arr,int n){
        vector<int> nse(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()? n : st.top();
        st.push(i);
        }
        return nse;
    }
    vector<int> psee(vector<int>& arr, int n){
        vector<int> psee(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            psee[i]=st.empty()?-1: st.top();
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> NSE(n,0);
        NSE=nse(arr,n);

        vector <int> PSEE=psee(arr,n);
        long long mod=1e9+7;
        long long total=0;
        for(int i=0;i<n;i++){
            int left=i-PSEE[i];
            int right=NSE[i]-i;
            total=total + (right*left*1LL*arr[i])% mod;
            total=total%mod;


        }
        return total;

    }
};