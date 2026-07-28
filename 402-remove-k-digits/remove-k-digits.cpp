class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int removals = 0;
        for(int i = 0;i <num.size();i++){
            while(!st.empty() && st.top()>num[i] && removals<k){
                st.pop();
                removals++;
            }
            if(num[i] == '0' && st.empty())continue;
            st.push(num[i]);
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        ans = ans.substr(0,ans.size() - min((int)ans.size(),(k-removals)));
        if(ans == "" )return "0";
        return ans;
    }
};