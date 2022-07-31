class Solution {
public:
    // void solve(vector<int>&nums, vector<vector<int>>&ans, vector<int>&ds, vector<int>&hashMap) {
    //     if(ds.size() == nums.size()) {
    //         ans.push_back(ds); 
    //         return; 
    //     }
    //     for(int i = 0; i < nums.size(); i++) {
    //         if(!hashMap[i]) {
    //             ds.push_back(nums[i]); 
    //             hashMap[i] = 1; 
    //             solve(nums, ans, ds, hashMap);
    //             ds.pop_back();
    //             hashMap[i] = 0;
    //         }
    //     }
    // }
    
    void recur(int indx, vector<int>& nums, vector<vector<int>>& ans) {
        if(indx == nums.size()) {
            vector<int> ds; 
            for(int i = 0; i < nums.size(); i++) 
                ds.push_back(nums[i]);
            ans.push_back(ds);
            return;
        }
        for(int i = indx; i < nums.size(); i++) {
            swap(nums[i], nums[indx]);
            recur(indx + 1, nums, ans);
            swap(nums[i], nums[indx]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) { // time: O(n! * n), space: O(n + n)
        // vector<vector<int>> ans; vector<int> ds; 
        // vector<int> hashMap(nums.size(), 0); 
        // solve(nums, ans, ds, hashMap);
        // return ans; 
        
        vector<vector<int>> ans; 
        recur(0, nums, ans);
        return ans; 
    }
};
