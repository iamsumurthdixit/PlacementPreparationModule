class Solution {
public:
    void solve(int ind, vector<vector<int>>& res, vector<int>& ds, vector<int>& nums) {
        res.push_back(ds); 
        for(int i = ind; i < nums.size(); i++) {
            if(i > ind and nums[i] == nums[i - 1]) continue; 
            ds.push_back(nums[i]); 
            solve(i + 1, res, ds, nums); 
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res; vector<int> ds; 
        solve(0, res, ds, nums); 
        return res; 
    }
};
