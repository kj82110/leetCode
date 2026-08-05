#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Fenwick {
        int n;
        vector<long long> bit;
        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void add(int idx, long long val) { // idx is 1-based
            for (; idx <= n; idx += idx & -idx) bit[idx] += val;
        }

        long long sumPrefix(int idx) { // idx is 1-based
            long long s = 0;
            for (; idx > 0; idx -= idx & -idx) s += bit[idx];
            return s;
        }
    };

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = (int)nums1.size();
        vector<long long> a(n);
        for (int i = 0; i < n; i++) a[i] = (long long)nums1[i] - (long long)nums2[i];

        // Compress raw a[i], because we update with a[i] and query <= (a[j] + diff).
        vector<long long> coords = a;
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        Fenwick fw((int)coords.size());
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            long long target = a[j] + diff;

            // number of i < j with a[i] <= target
            int pos = (int)(upper_bound(coords.begin(), coords.end(), target) - coords.begin());
            // pos elements satisfy, BIT is 1-based, so prefix sum over first pos entries:
            ans += fw.sumPrefix(pos);

            // insert a[j] for future
            int insertIdx = (int)(lower_bound(coords.begin(), coords.end(), a[j]) - coords.begin()) + 1;
            fw.add(insertIdx, 1);
        }

        return ans;
    }
};