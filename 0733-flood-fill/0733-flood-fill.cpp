class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q1;
        q1.push({sr,sc});
        int m=image.size();
        int n=image[0].size();
        while(q1.size()){
            auto it=q1.front();
            q1.pop();
            if(image[it.first][it.second]==color)
                continue;
            if(it.first-1>=0 and image[it.first-1][it.second]==image[it.first][it.second]){
                q1.push({it.first-1,it.second});
            }
            
            if(it.first+1<m and image[it.first+1][it.second]==image[it.first][it.second]){
                q1.push({it.first+1,it.second});
            }
            
            if(it.second-1>=0 and image[it.first][it.second-1]==image[it.first][it.second]){
                q1.push({it.first,it.second-1});
            }
            
            if(it.second+1<n and image[it.first][it.second+1]==image[it.first][it.second]){
                q1.push({it.first,it.second+1});
            }
            
            image[it.first][it.second]=color;
        }
        
        return image;
    }
};