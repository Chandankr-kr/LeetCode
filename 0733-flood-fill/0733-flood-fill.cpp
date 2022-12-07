class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q1;
        int m=image.size();
        int n=image[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        q1.push({sr,sc});
        
        
        while(q1.size()){
            int k=q1.size();
            for(int i=0;i<k;i++){
                int x=q1.front().first;
                int y=q1.front().second;
                q1.pop();
                
                if(x-1>=0 and image[x-1][y]==image[x][y] and visited[x-1][y]==false){
                    q1.push({x-1,y});
                }
                
                if(y-1>=0 and image[x][y-1]==image[x][y] and visited[x][y-1]==false){
                    q1.push({x,y-1});
                }
                
                if(x+1<m and image[x+1][y]==image[x][y] and visited[x+1][y]==false){
                    q1.push({x+1,y});
                }
                
                if(y+1<n and image[x][y+1]==image[x][y] and visited[x][y+1]==false){
                    q1.push({x,y+1});
                }
                // image[x][y]=0;
                visited[x][y]=true;
                image[x][y]=color;
            }
        }
        return image;
    }
};