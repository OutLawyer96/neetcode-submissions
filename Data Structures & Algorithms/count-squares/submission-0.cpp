class CountSquares {
public:
    unordered_map<int,unordered_map<int,int>> freq;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        freq[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res=0;
        int x=point[0];
        int y=point[1];
        for(auto& [ny,count]:freq[x]){
            if(ny==y){
                continue;
            }
            int d=ny-y;
            res += count * freq[x + d][y] * freq[x + d][ny];
            res += count * freq[x - d][y] * freq[x - d][ny];
        }
        return res;
    }
};
