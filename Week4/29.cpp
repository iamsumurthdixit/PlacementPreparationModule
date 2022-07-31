class DSU {
private:
    vector<int> root;
    vector<int> siz;
public:
    void make_dsu() {
        root.resize(90005);
        siz.resize(90005);
        for(int i = 0; i < 90005; i++) {
            root[i] = i; 
            siz[i] = 0; 
        }
    }
    void set_siz(int x) {
        siz[x] = 1; 
    }
    int find(int x) {
        while(x != root[x]) {
            x = root[root[x]];
        } 
        return x; 
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b); 
        if(a == b) return; 
        if(siz[a] < siz[b]) {
            swap(a, b); 
        }
        siz[a] += siz[b];
        root[b] = a; 
    }
    void print(int limit) {
        for(int i = 0; i < limit; i++) cout << root[i] << " "; cout << endl;         
        for(int i = 0; i < limit; i++) cout << siz[i] << " "; cout << endl; 
    }
    int ans(int limit) {
        int cnt =0;
        for(int i = 0; i <= limit; i++) {
             if(find(i) == i) cnt += siz[i];
        }
        return cnt;
    }
};
class Solution {
private:
    vector<int> dx = {0, -1}; 
    vector<int> dy = {-1, 0};    
public:
    bool isSafe(int a, int b, int n, int m) {
        if(a < 0 or a >= n) return false; 
        if(b < 0 or b >= m) return false; 
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        DSU d; d.make_dsu(); 
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    d.set_siz(i * (m + 1) + j);
                    for(int k = 0; k < 2; k++) {
                        if(isSafe(i + dx[k], j + dy[k], n, m)) {
                            if(grid[i + dx[k]][j + dy[k]] == 1) {
                                int a = i * (m + 1) + j; 
                                int l = i + dx[k], r = j + dy[k];
                                int b = l * (m + 1) + r; 
                                d.unite(a, b);
                                cout << "a: " << a << " ,b: " << b << endl;
                            }
                        }
                    }
                }
            }
        }
        d.print((n * m));
        return d.ans((n * m) - 1); 
    }
};
