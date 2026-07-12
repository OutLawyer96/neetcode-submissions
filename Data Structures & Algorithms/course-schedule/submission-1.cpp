class Solution {
public:
    
    bool dfs(vector<vector<int>>& courses,int start,vector<int>& visited,vector<int>& path){
        visited[start]=1;
        path[start]=1;
        for(int i=0;i<courses.size();i++){
            if(courses[i][0]==start){
                if(path[courses[i][1]]==1){
                    return true;
                }
                if(visited[courses[i][1]]!=1){
                    if(dfs(courses,courses[i][1],visited,path)){
                        return true;
                    }
                }
            }
        }
        path[start]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs(prerequisites,i,visited,path)){
                return false;
            }
        }
        return true;
    }
};
