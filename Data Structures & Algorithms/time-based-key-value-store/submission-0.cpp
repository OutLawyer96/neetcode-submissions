class TimeMap {
public:
    unordered_map<string,vector <pair<int,string>>> map;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int high=map[key].size()-1;
        int low=0;
        int mid=(high+low)/2;
        string maxi;
        while(low<=high){
            mid=(high+low)/2;
            if(map[key][mid].first==timestamp){
                return map[key][mid].second;
            }else if(map[key][mid].first>timestamp){
                high=mid-1;
            }else{
                maxi=map[key][mid].second;
                low=mid+1;
            }
        }
        return maxi;
    }
};
