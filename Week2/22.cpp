class Solution{
   public:
   vector<string>res;
   int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
   unordered_map<int,char>mp;


   void travel(int i,int j,string curr,vector<vector<int>> &m)
   {
       int n=m.size();
       if(i==n || j==n || i<0 || j<0 || !m[i][j])
           return;
       else if(i==n-1 && j==n-1)
       {
           res.push_back(curr);
           return;
       }
       m[i][j]=0;
       for(int k=0;k<4;k+=1)
           travel(i+dx[k],j+dy[k],curr+mp[k],m);
       m[i][j]=1;
       
   }
   vector<string> findPath(vector<vector<int>> &m, int n) {
       mp[0]='U';
       mp[1]='R';
       mp[2]='D';
       mp[3]='L';
       travel(0,0,"",m);
       return res;
   }
};
