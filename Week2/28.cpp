int Solution::books(vector<int> &A, int B) {
    if(B > A.size()) return -1; 
    int low = INT_MAX, high = 0; 
    int ans = 0; 
    for(int i = 0; i < A.size(); i++) {
        low = min(low, A[i]);
        high += A[i];
    }
    auto ok = [&](int mid) {
        int students = 1; int pages =0 ; 
        for(int i = 0; i < A.size(); i++) {
            if(A[i] > mid) return false; 
            if(A[i] + pages <= mid) {
                pages += A[i]; 
            } else {
                ++students;
                pages = A[i];
            }
        }
        return students <= B;
    };
    while(low <= high) {
        int mid = (low + high) / 2; 
        if(ok(mid)) {
            ans = mid; 
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }
    return ans;
}
