class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // make this like there is left half such that, first occ of a number is at even index and next occ is at next odd indx. and after that, there is a single element(including which marks the start of right half), then there is a right half such that first occ is at odd indx and next occ is at next even indx. so we need to find the point where this property of left index fails. if that is valid, do left = mid + 1, to check upto where it is vaild, likewise, if it is not vaild, means we are in right half, so do high = mid - 1, to limit that region.
        
        int low = 0, high = nums.size() - 2; 
        while(low <= high) {
            int mid = (low + high) >> 1; 
            if(nums[mid] == nums[mid ^ 1]) {
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }
        return nums[low];
    }
};
