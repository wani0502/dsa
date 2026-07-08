class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        vector<int> pos;
        vector<long long> prefNum;
        vector<long long> prefSum;

        for (int i = 0; i < s.size(); i++) {
            int d = s[i] - '0';
            if (d == 0) continue;

            pos.push_back(i);

            if (prefNum.empty()) {
                prefNum.push_back(d);
                prefSum.push_back(d);
            } else {
                prefNum.push_back((prefNum.back() * 10 + d) % MOD);
                prefSum.push_back(prefSum.back() + d);
            }
        }

        int m = pos.size();

        vector<long long> pow10(m + 1);
        pow10[0] = 1;

        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[R];
            if (L)
                sum -= prefSum[L - 1];

            int len = R - L + 1;

            long long num = prefNum[R];
            if (L) {
                num = (num - prefNum[L - 1] * pow10[len]) % MOD;
            }

            num = (num + MOD) % MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};