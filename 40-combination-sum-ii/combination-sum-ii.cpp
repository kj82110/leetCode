class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue; // Skip duplicates

            if (candidates[i] > target)
                break;

            path.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return ans;
    }
};