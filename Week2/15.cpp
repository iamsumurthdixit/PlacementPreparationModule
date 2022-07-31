class Solution {
public:
    void solve(int ind, vector<vector<int>>& res, vector<int>& ds, vector<int>& cand, int tar) {
        if(ind == cand.size()) {
            if(tar == 0)
                res.push_back(ds); 
            return ; 
        }
        if(cand[ind] <= tar) {
            ds.push_back(cand[ind]);
            solve(ind, res, ds, cand, tar - cand[ind]);
            ds.pop_back();
        }
        solve(ind + 1, res, ds, cand, tar);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res; vector<int> ds; 
        solve(0, res, ds, candidates, target); 
        return res; 
    }
    
    
};
