class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e= *max_element(piles.begin(), piles.end());
        int ans=0;

        while(s<=e) {
            long long total=0;
            int mid= s+(e-s)/2;
            //try using this
            for(int pile: piles) {
                total+= ceil((double)pile/mid);
            }

            if(total<=h) {
                //store and find min
                ans=mid;
                e=mid-1;
            } else s=mid+1;
        }
        return ans;
    }
};