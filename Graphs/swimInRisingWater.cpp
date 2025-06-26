class Solution {
    //djiktra
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n= grid.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>visit(n, vector<int>(n,0));
        
        pq.push({grid[0][0],{0,0}});
        //mark as visited
        visit[0][0]=1;

        while(!pq.empty()) {
            int elevate= pq.top().first;
            int x= pq.top().second.first;
            int y= pq.top().second.second;
            pq.pop();

            if(x==n-1 && y==n-1) return elevate;

            //check for neighbours
            vector<int> xdir={-1,0,1,0};
            vector<int> ydir={0,1,0,-1};

            for(int i=0; i<4; i++) {
                int newx= x+xdir[i];
                int newy= y+ydir[i];

                //validity
                if(newx<0 || newx>=n || newy<0 || newy>=n || visit[newx][newy]) continue;
                //else
                visit[newx][newy]=1;
                pq.push({max(elevate,grid[newx][newy]),{newx,newy}});
            }
        }
        return 0;
    }
};

// Time Complexity: O(N^2 * log(N)), where N is the number of cells in the grid.
/*
n^2 cells in the grid, and each cell can be processed at most once. 
The priority queue operations (insertions and deletions) take O(log(N)) time, leading to an overall time complexity of O(N^2 * log(N)).

neighbour traversal:
checking 4 neighbours for each cell
4*n^2 = O(n^2) and each check takes O(1) time, so the neighbour traversal contributes O(n^2) to the time complexity.

Total Time Complexity: O(N^2 * log(N)) + O(N^2) = O(N^2 * log(N))

SC: O(N^2)
The space complexity is O(N^2) due to the visit matrix and the priority queue
*/