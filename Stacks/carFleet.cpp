class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n= position.size();
        vector<pair<int,int>>cars;
        for(int i=0; i<n; i++) cars.push_back({position[i], speed[i]});

        sort(cars.begin(), cars.end());

        stack<double>st;

        for(int i=n-1; i>=0; i--) {
            int pos= cars[i].first;
            int speed= cars[i].second;
            double t= (double) (target-pos)/speed;

            if(st.empty() || t>st.top()) st.push(t);
            //else do nothing
        }

        return st.size();
    }
};

//TC: O(N log N) for sorting the cars, and O(N) for processing each car, leading to an overall time complexity of O(N log N).
//SC: O(N) for the stack used to store the time taken by each car to reach the target.