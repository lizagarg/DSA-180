class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int ans=0;
        while(l<r) {
            int width= r-l;
            int minHeight= min(height[l], height[r]);
            int area= width*minHeight;
            ans= max(ans, area);
            if(height[l]<height[r]) l++;
            else r--; //to increase the minheight
        }
        return ans;
    }
};

//TC: O(N)
