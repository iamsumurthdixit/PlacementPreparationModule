#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void solve(int ind, int sum, vector<int>& arr, vector<int>& res) {
        if(arr.size() == ind) {
            res.push_back(sum); 
            return; 
        }
        solve(ind + 1, sum + arr[ind], arr, res); 
        solve(ind + 1, sum, arr, res);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        sort(arr.begin(), arr.end()); 
        vector<int> res; 
        solve(0, 0, arr, res);
        return res; 
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
