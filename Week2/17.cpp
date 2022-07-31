class Solution {
public:
    bool isPalind(int l, int r, string s) {
        while(l <= r) 
            if(s[l++] != s[r--]) 
                return false; 
        return true; 
    }
    void solve(int ind, string s, vector<vector<string>>& res, vector<string>& ds) {
        if(ind == s.length()) {
            res.push_back(ds);
            return; 
        }
        for(int i = ind; i < s.length(); i++) {
            if(isPalind(ind, i, s)) {
                string x; 
                for(int j = ind; j <= i; j++) x += s[j]; 
                ds.push_back(x);
                solve(i + 1, s, res, ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {    
        vector<vector<string>> res; vector<string> ds; 
        solve(0, s, res, ds); 
        return res; 
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // bool isPalindrome(string s, int l, int r) {
    //     while(l <= r) {
    //         if(s[l++] != s[r--]) 
    //             return false;
    //     }
    //     return true;
    // }
    // void partition(int indx, string s, vector<vector<string>>&res, vector<string>&ds) {
    //     if(indx == s.length()) {
    //         res.push_back(ds); 
    //         return; 
    //     }
    //     for(int i = indx; i < s.length(); i++) {
    //         if(isPalindrome(s, indx, i)) {
    //             ds.push_back(s.substr(indx, i - indx + 1));
    //             partition(i + 1, s, res, ds); 
    //             ds.pop_back();
    //         }
    //     }
    // }
    // vector<vector<string>> partition(string s) {
    //     vector<vector<string>> res; 
    //     vector<string> ds; 
    //     partition(0, s, res, ds);
    //     return res;
    // }
};
