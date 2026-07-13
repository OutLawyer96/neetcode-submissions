class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        int d=beginWord.length();
        vector<int> visited(n,0);
        queue<string> q;
        q.push(beginWord);
        int count=1;
        while(!q.empty()){
            int l=q.size();
            for(int k=0;k<l;k++){
                string curr=q.front();
                q.pop();
                for(int i=0;i<n;i++){
                    if(visited[i]){
                        continue;
                    }
                    int c=0;
                    for(int j=0;j<d;j++){
                        if(curr[j]==wordList[i][j]){
                            c++;
                        }
                    }
                    if(c==d-1){
                        if(wordList[i]==endWord){
                            return count+1;
                        }
                        q.push(wordList[i]);
                        visited[i]=1;
                    }
                }
            }
            count++;
        }
        return 0;
    }
};
