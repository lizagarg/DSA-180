class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lmax(n,0);
        vector<int>rmax(n,0);
        lmax[0]=height[0];
        rmax[n-1]=height[n-1];

        for(int i=1; i<n; i++) {
            lmax[i]=max(lmax[i-1], height[i]);
        }

        for(int i=n-2; i>=0; i--) {
            rmax[i]=max(rmax[i+1], height[i]);
        }

        int ans=0;
        for(int i=0; i<n; i++) {
            ans+= min(lmax[i], rmax[i])-height[i];
        }
        return ans;
    }
};

/*
TC: O(N)
SC: O(N) for the lmax and rmax arrays, where N is the size of the input array height.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int lmax=0, rmax=0;
        int l=0, r= n-1;
        while(l<r) {
            //boundaries
            lmax= max(lmax, height[l]);
            rmax= max(rmax, height[r]);
            if(lmax<rmax) {
                //deciding factor is lmax
                ans+= lmax-height[l];
                l++;
            } else {
                ans+=rmax-height[r];
                r--;
            }
        }
        return ans;
    }
};

//SC:O(1)