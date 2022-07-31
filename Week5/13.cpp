int palindromicPartition(string str)
{
    int n = str.size();
    vector<vector<bool>> dp(n, vector<bool>(n, true));
    for(int g=1; g<n; g++){
        for(int i=0; i+g<n; i++){
            int j = i+g;
            dp[i][j] = dp[i+1][j-1] && (str[i]==str[j]);
        }
    }
    vector<int> minPartition(n+1, INT_MAX);
    minPartition[n]=-1;
    for(int i=n-1; i>=0; i--){
        for(int j=i; j<n; j++){
            if(dp[i][j]) minPartition[i] = min(minPartition[i], 1+minPartition[j+1]);
        }
    }
    return minPartition[0];
}
