class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps,
                                 vector<vector<int>>& queries) {

        unordered_map<long long, int> row, col, diag, anti;
        unordered_set<long long> on;

        auto key = [](long long x, long long y) {
            return (x << 32) | y;
        };

        // Initialize active lamps
        for (auto &l : lamps) {
            long long r = l[0], c = l[1];
            long long k = key(r, c);
            if (on.insert(k).second) {
                row[r]++;
                col[c]++;
                diag[r - c]++;
                anti[r + c]++;
            }
        }

        vector<int> ans;

        int dirs[9][2] = {
            {0,0},{-1,-1},{-1,0},{-1,1},
            {0,-1},{0,1},
            {1,-1},{1,0},{1,1}
        };

        for (auto &q : queries) {
            long long r = q[0], c = q[1];

            if (row[r] > 0 || col[c] > 0 ||
                diag[r - c] > 0 || anti[r + c] > 0)
                ans.push_back(1);
            else
                ans.push_back(0);

            // Turn off lamps in 3x3 area
            for (auto &d : dirs) {
                long long nr = r + d[0];
                long long nc = c + d[1];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                long long k = key(nr, nc);

                if (on.erase(k)) {
                    row[nr]--;
                    col[nc]--;
                    diag[nr - nc]--;
                    anti[nr + nc]--;
                }
            }
        }

        return ans;
    }
};