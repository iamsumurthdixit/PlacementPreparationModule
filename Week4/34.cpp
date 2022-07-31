class Solution{
    public void shortest_distance(int[][] mat){
        int n=mat.length, m=mat[0].length;
        for(int k=0; k<n; k++){
            for(int i=0; i<n ; i++){
                for(int j=0; j<m; j++){
                    if(mat[i][k]==-1 || mat[k][j]==-1) continue;
                    if(mat[i][j]==-1) mat[i][j]=mat[i][k]+mat[k][j];
                    else mat[i][j]=Math.min(mat[i][j], mat[i][k] + mat[k][j] );
                }
            }
        }
    }
}
