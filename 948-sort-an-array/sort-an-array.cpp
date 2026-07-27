const int LEN = 5e5 + 5;
const int BUCK_SIZE = (1 << 16);
const int REM = (1 << 16) - 1;

typedef unsigned int ui;

int N;
int psa[BUCK_SIZE];
ui arr[LEN];

inline void sort(ui *a) {
    for(int i = 0; i < N; ++i)
        a[i] ^= (1 << 31);

    memset(psa, 0, sizeof(psa));

    for(int i = 0; i < N; ++i)
        psa[a[i] & REM]++;

    for(int i = 1; i < BUCK_SIZE; ++i)
        psa[i] += psa[i - 1];

    for(int i = N-1; i >= 0; --i)
        arr[--psa[a[i] & REM]] = a[i];
    
    memset(psa, 0, sizeof(psa));

    for(int i = 0; i < N; ++i)
        psa[(arr[i] >> 16) & REM]++;

    for(int i = 1; i < BUCK_SIZE; ++i)
        psa[i] += psa[i - 1];

    for(int i = N-1; i >= 0; --i)
        a[--psa[(arr[i] >> 16) & REM]] = arr[i];
    
    for (int i = 0; i < N; i ++) 
        a[i] ^= (1 << 31);
    
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        N = nums.size();
        sort((ui*) &(*nums.begin()));
        return nums;
    }
};