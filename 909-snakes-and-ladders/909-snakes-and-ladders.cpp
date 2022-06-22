class Solution {
public:
    void findRC(int n,int currPos,int &row,int &col)
    {
        row=n-1-(currPos-1)/n;
        col=(currPos-1)%n;
        if((n%2==0 && row%2==0) || (n%2==1 && row%2==1))
            col=n-1-col;
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<pair<int,int>> q1;
        q1.push({1,0});
        vector<bool> visited(n*n+1,false);
        visited[1]=true;
        while(q1.size())
        {
            pair<int,int> front=q1.front();
            q1.pop();
            int row,col,curr=front.first,dist=front.second;
            if(curr==n*n)
                return dist;
            for(int i=1;i<=6 && curr+i<=n*n;i++)
            {
                findRC(n,curr+i,row,col);
                int currPos=board[row][col]==-1?curr+i:board[row][col];
                if(visited[currPos]==false){
                    visited[currPos]=true;
                q1.push({currPos,1+dist});
                }
                    
            }
        }
        return -1;
    }
};