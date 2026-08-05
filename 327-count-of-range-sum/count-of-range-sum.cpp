class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        vector<long long> temp(n + 1);
        return mergeSortCount(prefixSum, temp, 0, n, lower, upper);
    }
    
private:
    int mergeSortCount(vector<long long>& sums, vector<long long>& temp, 
                        int left, int right, int lower, int upper) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        int count = mergeSortCount(sums, temp, left, mid, lower, upper) +
                    mergeSortCount(sums, temp, mid + 1, right, lower, upper);
        
        // Count valid pairs (i in left half, j in right half)
        int lo = mid + 1, hi = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (lo <= right && sums[lo] - sums[i] < lower) lo++;
            while (hi <= right && sums[hi] - sums[i] <= upper) hi++;
            count += hi - lo;
        }
        
        // Merge the two halves (standard merge sort)
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right) {
            if (sums[i] <= sums[j]) temp[k++] = sums[i++];
            else temp[k++] = sums[j++];
        }
        while (i <= mid) temp[k++] = sums[i++];
        while (j <= right) temp[k++] = sums[j++];
        for (int p = left; p <= right; p++) sums[p] = temp[p];
        
        return count;
    }
};