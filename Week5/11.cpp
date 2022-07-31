int eggDrop(int n, int k) 
    {
        //dp[i][j]-> minimum number of trails neede for i eggs and j floors.
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=1;i<=n;i++){//i->egg
            for(int j=1;j<=k;j++){//j->floor
                if(i==1)dp[i][j]=j;// we need j trails for 1 egg and j floors
                else if(j==1)dp[i][j]=1;//we need one trial for one floor 
                else{
                    for(int x=1;x<=j;x++){
                        dp[i][j]=1+min(dp[i][j],max(dp[i][j-x],dp[i-1][x-1]));
                    }
                }
            }
        }
        return dp[n][k];
    }
