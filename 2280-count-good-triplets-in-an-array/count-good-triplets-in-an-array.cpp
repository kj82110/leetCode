#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Fenwick {
        int n;
        vector<int> bit;
        Fenwick(int n=0) { init(n); }
        void init(int n_) {
            n = n_;
            bit.assign(n + 1, 0);
        }
        void add(int idx, int val) { // idx: 0-based
            for (idx++; idx <= n; idx += idx & -idx) bit[idx] += val;
        }
        int sumPrefix(int idx) { // sum [0..idx], idx 0-based
            if (idx < 0) return 0;
            int res = 0;
            for (idx++; idx > 0; idx -= idx & -idx) res += bit[idx];
            return res;
        }
    };

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size();

        vector<int> pos1(n);
        for (int i = 0; i < n; i++) pos1[nums1[i]] = i;

        // arr[i] = position of nums2[i] in nums1
        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = pos1[nums2[i]];

        vector<long long> left(n), right(n);

        // left[j] = count of i<j with arr[i] < arr[j]
        {
            Fenwick fw(n);
            for (int j = 0; j < n; j++) {
                left[j] = fw.sumPrefix(arr[j] - 1);
                fw.add(arr[j], 1);
            }
        }

        // right[j] = count of k>j with arr[k] > arr[j]
        {
            Fenwick fw(n);
            for (int j = n - 1; j >= 0; j--) {
                // count of elements with value > arr[j]
                // = total seen so far - count of <= arr[j]
                long long seen = (n - 1 - j);
                long long leq = fw.sumPrefix(arr[j]);
                right[j] = seen - leq;
                fw.add(arr[j], 1);
            }
        }

        long long ans = 0;
        for (int j = 0; j < n; j++) {
            ans += left[j] * right[j];
        }
        return ans;
    }
};