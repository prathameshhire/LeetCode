class StockSpanner {
public:
    stack<pair<int,int>> st;
    int index = -1;

    StockSpanner() {
        index = -1;
        while (!st.empty()) {
            st.pop();
        }
    }


    int next(int price) {    
        index++;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int count = index - (st.empty() ? -1 : st.top().second);
        st.push({price, index});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */