class Solution {
public:
    void solve(int ind, int tar, vector<int>& cand, vector<vector<int>>& res, vector<int>& ds) {
        if(tar == 0) {
            res.push_back(ds); 
            return; 
        }
        for(int i = ind; i < cand.size(); i++) {
            if(i > ind and cand[i] == cand[i - 1]) continue; 
            if(cand[i] > tar) break; 
            ds.push_back(cand[i]); 
            solve(i + 1, tar - cand[i], cand, res, ds); 
            ds.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> res; vector<int> ds; 
        solve(0, target, candidates, res, ds); 
        return res;
    }    
  
        
//     void solve(int ind, int tar, vector<int>& cand, vector<vector<int>>& ans, vector<int>& ds) {
//         if(tar == 0) {
//             ans.push_back(ds);
//             return;
//         }
//         for(int i = ind; i < cand.size(); i++){ 
//             if(i > ind && cand[i] == cand[i-1]) continue;
//             if(cand[i] > tar) break;
//             ds.push_back(cand[i]);
//             solve(i + 1, tar - cand[i], cand, ans, ds);
//             ds.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int>> ans; vector<int> ds; 
      
//         solve(0, target, candidates, ans, ds);
//         return ans;
//     }
};
