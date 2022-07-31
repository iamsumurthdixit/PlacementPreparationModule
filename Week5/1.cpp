class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int l = 1, r = 1; 
        for(int i = 0; i < n; i++) {
            l = l * nums[i];
            r = r * nums[n - i - 1];
            
            res = max({res, l, r});
            if(l == 0) l = 1; 
            if(r == 0) r = 1; 
        }
        return res;
    }
    
};
