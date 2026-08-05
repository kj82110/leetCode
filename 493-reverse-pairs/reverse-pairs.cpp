class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

        // Count reverse pairs across the two halves
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long)nums[i] > 2L * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge the two sorted halves
        vector<int> merged(right - left + 1);
        int i = left, k = mid + 1, idx = 0;
        while (i <= mid && k <= right) {
            if (nums[i] <= nums[k]) {
                merged[idx++] = nums[i++];
            } else {
                merged[idx++] = nums[k++];
            }
        }
        while (i <= mid) merged[idx++] = nums[i++];
        while (k <= right) merged[idx++] = nums[k++];

        for (int x = 0; x < merged.size(); x++) {
            nums[left + x] = merged[x];
        }

        return count;
    }
};