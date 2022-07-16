class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); 
        int leftmax = 0, rightmax = 0; 
        int l = 0, r = n - 1, res = 0; 
        while(l <= r) {
            if(height[l] <= height[r]) {
                if(height[l] >= leftmax) 
                    leftmax = height[l]; 
                else 
                    res += leftmax - height[l];
                ++l; 
            } else {
                if(height[r] >= rightmax) 
                    rightmax = height[r]; 
                else
                    res += rightmax - height[r]; 
                --r; 
            }
        }
        return res; 
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // BRUTE FORCE : O(N * N)
        
//         int res  = 0; int n = height.size(); 
//         for(int i = 1; i < n - 1; i++) {
//             if(height[i] < height[i - 1]) {
//                 int x = 0; 
//                 for(int j = i + 1; j < n; j++) {
//                     if(height[j] >= height[i - 1]) {
//                         x = height[j]; 
//                         break;
//                     }
//                 }
//                 int k = min(height[i - 1], x) - height[i]; 
//                 if(k > 0) {
//                     height[i] += k; 
//                     res += k;  
//                 }
//             }
//         }
//         return res;
        
        
        
        
        // FIRST TIME WRITTEN CODE
        
//         // 2 pointers, time: O(N), space: O(1)
//         int left = 0, right = height.size() - 1; 
//         int maxleft = 0, maxright = 0; 
//         int res = 0; 
        
//         while(left < right) {
//             if(height[left] <= height[right]) {  
//                 if(height[left] > maxleft) 
//                     maxleft = height[left];
//                 else 
//                     res += maxleft - height[left];
//                 ++left;
//             } else {
//                 if(height[right] > maxright) 
//                     maxright = height[right];
//                 else
//                     res += maxright - height[right];
//                 --right;
//             }
//         }
//         return res;
    }
};
