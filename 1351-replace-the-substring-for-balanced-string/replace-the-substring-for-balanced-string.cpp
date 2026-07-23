class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char, int> cnt;

        for (char c : s)
            cnt[c]++;

        int target = n / 4;
        int ans = n;
        int left = 0;

        for (int right = 0; right < n; right++) {
            cnt[s[right]]--;

            while (left < n &&
                   cnt['Q'] <= target &&
                   cnt['W'] <= target &&
                   cnt['E'] <= target &&
                   cnt['R'] <= target) {

                ans = min(ans, right - left + 1);
                cnt[s[left]]++;
                left++;
            }
        }

        return ans;
    }
};