class MinStack {
public:
    stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) st.push({val,val});
        else {
            int mini= min(val, st.top().second);
            st.push({val,mini});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};


 /*
 Tc: O(1) for push, pop, top, and getMin operations.
 SC: O(2*N) for double stack storage
 */

 class MinStack {
public:
    stack<long long> st;  // Stores actual or encoded values
    long long currentMin;        // Always holds the current minimum

    MinStack() {
        currentMin = LLONG_MAX;  // Start with maximum possible
    }

    void push(int value) {
        long long val = value;
        if (st.empty()) {
            currentMin = val;
            st.push(val);
        } else {
            if (val < currentMin) {
                // Encode the new minimum in stack
                long long encodedVal = 2 * val - currentMin;
                st.push(encodedVal);
                currentMin = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (!st.empty()) {
            long long topElement = st.top();
            st.pop();

            if (topElement < currentMin) {
                // Decode previous minimum
                currentMin = 2 * currentMin - topElement;
            }
        }
    }

    int top() {
        if (!st.empty()) {
            long long topElement = st.top();
            if (topElement < currentMin) {
                // It's an encoded value; return current minimum
                return currentMin;
            } else {
                return topElement;
            }
        }
        return -1;
    }

    int getMin() {
        return currentMin;
    }
};

//SC: O(N) for the stack storage, where N is the number of elements in the stack.
//TC: O(1) for push, pop, top, and getMin operations.