class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        const int MOD = 1e9 + 7;
        int maxVal = *max_element(instructions.begin(), instructions.end());
        vector<int> bit(maxVal + 1, 0);
        
        auto update = [&](int i) {
            for (; i <= maxVal; i += i & (-i))
                bit[i]++;
        };
        
        auto query = [&](int i) -> int {
            int sum = 0;
            for (; i > 0; i -= i & (-i))
                sum += bit[i];
            return sum;
        };
        
        long long totalCost = 0;
        for (int i = 0; i < instructions.size(); i++) {
            int val = instructions[i];
            int less = query(val - 1);
            int lessOrEqual = query(val);
            int greater = i - lessOrEqual;
            
            totalCost += min(less, greater);
            update(val);
        }
        
        return totalCost % MOD;
    }
};