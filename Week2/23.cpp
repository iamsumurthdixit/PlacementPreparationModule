int countLessThanEqualToMid(vector<int>& v, int num) {
    int low = 0, high = v.size() - 1; 
    while(low <= high) {
        int mid = (low + high) >> 1; 
        if(v[mid] <= num) low = mid + 1; 
        else high = mid - 1; 
    }
    return low; 
}

int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size(); 

    int low = 1, high = 1e9; 
    while(low <= high) {
        int mid = (low + high) >> 1; 
        int totalCnts = 0; 
        for(int i = 0; i < n; i++){
            totalCnts += countLessThanEqualToMid(A[i], mid);
        }
        if(totalCnts <= ((n * m) >> 1)) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    return low; 
}
