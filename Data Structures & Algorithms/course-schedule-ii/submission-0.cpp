class Solution {
public:
    bool dfs(vector<int> adjlist[],int i ,vector<int>& visited,vector<int>& path,vector<int>& ans){
        if(visited[i]==1){
            return false;
        }
        visited[i]=1;
        path[i]=1;
        vector<int> res;
        for(int k=0;k<adjlist[i].size();k++){
            if(path[adjlist[i][k]]==1){
                    return true;
            }
            if(visited[adjlist[i][k]]!=1){
                if(dfs(adjlist,adjlist[i][k],visited,path,ans)){
                    return true;
                }
            }
        }
        path[i]=0;
        ans.push_back(i);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjlist[numCourses];
        vector<int> visited(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adjlist[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if(dfs(adjlist,i,visited,path,ans)){
                    return {};
                }
            }
        }
        return ans;
    }
};
