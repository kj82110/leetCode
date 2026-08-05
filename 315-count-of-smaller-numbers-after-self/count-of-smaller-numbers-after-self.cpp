class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<int> indices(n);
        for (int i = 0; i < n; i++) indices[i] = i;
        
        mergeSort(nums, indices, counts, 0, n - 1);
        
        return counts;
    }
    
private:
    void mergeSort(vector<int>& nums, vector<int>& indices, vector<int>& counts, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSort(nums, indices, counts, left, mid);
        mergeSort(nums, indices, counts, mid + 1, right);
        merge(nums, indices, counts, left, mid, right);
    }
    
    void merge(vector<int>& nums, vector<int>& indices, vector<int>& counts, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        int rightCount = 0;
        
        while (i <= mid && j <= right) {
            if (nums[indices[j]] < nums[indices[i]]) {
                rightCount++;
                temp[k++] = indices[j++];
            } else {
                counts[indices[i]] += rightCount;
                temp[k++] = indices[i++];
            }
        }
        
        while (i <= mid) {
            counts[indices[i]] += rightCount;
            temp[k++] = indices[i++];
        }
        
        while (j <= right) {
            temp[k++] = indices[j++];
        }
        
        for (int p = 0; p < temp.size(); p++) {
            indices[left + p] = temp[p];
        }
    }
};