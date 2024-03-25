class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + nums[i];
        }
        vector<int> ans;
        for (int& x : queries) {
            int len = upper_bound(pref.begin(), pref.end(), x) - pref.begin();
            ans.push_back(len);
        }
        return ans;
    }
};
