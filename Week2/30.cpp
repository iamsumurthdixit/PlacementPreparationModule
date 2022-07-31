class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; 
        for(int x : nums) m[x]++; 
        auto comp = [& m](int x, int y) {
            return m[x] > m[y]; 
        }; 
        priority_queue<int, vector<int>, decltype(comp)> pq(comp); 
        
        for(auto x : m) {
            pq.push(x.first); 
            if(pq.size() > k)
                pq.pop(); 
        }
        vector<int> res; 
        while(!pq.empty()) {
            res.push_back(pq.top()); 
            pq.pop(); 
        }
        return res; 
    }
};
