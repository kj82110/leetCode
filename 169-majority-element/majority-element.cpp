class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n = nums.size();
       int half = n/2;

    vector<bool> v(n,false);

    for(int i=0;i<n;i++){
        int count = 1;
        if(!v[i]){
            for(int j = i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                    v[j]=true;
                }
            }
        }
        if(count>half){
            return nums[i];
        }
    }
    return 0;

    }
};