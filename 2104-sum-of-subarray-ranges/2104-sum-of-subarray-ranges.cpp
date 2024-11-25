class Solution {
    vector<int> NSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> NSE(n);
        stack <int> st;
        for (int i = n-1; i>=0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return NSE;
    }

    vector<int> PSEE (vector<int> &arr) {
        int n = arr.size();
        vector<int> PSEE(n);
        stack<int> st;
        for (int i = 0; i<n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            PSEE[i] = st.empty() ? -1 : st.top();
            st.push(i); 
        }
        return PSEE;
    }


    long long subMin (vector<int> &arr) {
        int n = arr.size();
        long long sum = 0;
        vector<int> nse = NSE(arr);
        vector<int> psee = PSEE(arr);
        for (int i = 0; i<n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            sum = sum + (left*right*arr[i]);
        }
        return sum;
    } 


    vector<int> NGE(vector<int> &arr) {
        int n = arr.size();
        vector<int> NGE(n);
        stack<int> st;
        for (int i = n-1; i>=0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            NGE[i] = st.empty() ? n : st.top();
            st.push(i); 
        }
        return NGE;
    }

    vector<int> PGEE(vector<int> &arr) {
        int n = arr.size();
        vector<int> PGEE(n);
        stack<int> st;
        for (int i = 0; i<n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            PGEE[i] = st.empty() ? -1 : st.top();
            st.push(i); 
        }
        return PGEE;
    }


    long long subMax (vector<int> &arr) {
        int n = arr.size();
        long long sum = 0;
        vector<int> nge = NGE(arr);
        vector<int> pgee = PGEE(arr);
        for (int i = 0; i<n; i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            sum = sum + (left*right*arr[i]);
        }
        return sum;
    } 

public:
    long long subArrayRanges(vector<int>& arr) {
        long long max = subMax(arr);
        long long min = subMin(arr);
        return max - min;
    }
};