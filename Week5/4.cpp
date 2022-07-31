class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> z, o; 
        vector<vector<int>> prev(m+1,vector<int>(n+1)); 
        vector<vector<int>> cur(m+1,vector<int>(n+1)); 

        for(auto x : strs) {
            int one = 0, zer  = 0 ; 
            for(auto u : x) {
                if(u == '0') ++zer; 
                else ++one; 
            }
            z.push_back(zer) ;
            o.push_back(one); 
        }

        for(int M = 0; M <= m; M++) {
            for(int N = 0; N <= n; N++) {
                if(z[0] <= M and o[0] <= N) {
                    prev[M][N] = 1; 
                } 
            }
        }

        for(int ind = 1; ind < strs.size(); ind++) {
            for(int M = 0; M <= m; M++) {
                for(int N = 0; N <= n; N++) {
                    int notTake = prev[M][N]; 
                    int take = 0; 
                    if(z[ind] <= M and o[ind] <= N) {
                        take = 1 + prev[M - z[ind]][N - o[ind]]; 
                    }
                    cur[M][N] = max(take, notTake); 
                }
            }
            prev = cur; 
        }
        return prev[m][n]; 
    }
};
