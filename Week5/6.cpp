class Solution
{
    static int matrixMultiplication(int N, int arr[])
    {
        int[][] matrix=new int[N+1][N+1];
        for(int[] a:matrix)
        {
            Arrays.fill(a,-1);
        }
       return solve(arr,1,N-1,matrix);
    }
    static int solve(int[] arr, int i, int j, int[][] matrix)
    {
        if(i>=j)
        {
            return matrix[i][j]=0;
        }
        if(matrix[i][j]!=-1)
        {
            return matrix[i][j];
        }
        int min=Integer.MAX_VALUE;
        for(int k=i;k<j;k++)
        {
            int temp=solve(arr,i,k,matrix)+solve(arr,k+1,j,matrix)+(arr[i-1]*arr[k]*arr[j]);
            min=Math.min(min,temp);
        }
        return matrix[i][j]=min;
    }
    
}
