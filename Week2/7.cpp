class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int l = 0, r = 0;
        int cnt = 0; 
        while(r < nums.size()) {
            if(nums[r] == 1) {
                cnt = max(cnt, (r - l + 1));
                r++;
            } else {
                r++;
                l = r; 
            }
        }
        return cnt;
    }
};
