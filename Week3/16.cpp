class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0]; 
        for(int i = 1; i < strs.size(); i++) {
            string x;  
            for(int j = 0; j < min(strs[i].size(), res.size()); j++) {
                if(strs[i][j] == res[j]) x += res[j]; 
                else break; 
            }
            res = x; 
        }
        return res;
    } 
};
