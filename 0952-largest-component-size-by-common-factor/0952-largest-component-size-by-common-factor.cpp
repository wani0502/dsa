class Solution {
public:
    class DSU {
    public:
        vector<int> parent, sz;

        DSU(int n) {
            parent.resize(n);
            sz.assign(n, 1);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b) return;

            if (sz[a] < sz[b])
                swap(a, b);

            parent[b] = a;
            sz[a] += sz[b];
        }
    };

    int largestComponentSize(vector<int>& nums) {

        int n = nums.size();

        DSU dsu(n);

        unordered_map<int, int> factorOwner;

        for (int i = 0; i < n; i++) {

            int x = nums[i];

            for (int d = 2; d * d <= x; d++) {

                if (x % d == 0) {

                    if (factorOwner.count(d))
                        dsu.unite(i, factorOwner[d]);
                    else
                        factorOwner[d] = i;

                    while (x % d == 0)
                        x /= d;
                }
            }

            if (x > 1) {
                if (factorOwner.count(x))
                    dsu.unite(i, factorOwner[x]);
                else
                    factorOwner[x] = i;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
            ans = max(ans, dsu.sz[dsu.find(i)]);

        return ans;
    }
};