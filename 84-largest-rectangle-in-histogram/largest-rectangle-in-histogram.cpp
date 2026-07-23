class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        int n=heights.size();
        vector<int> area(n);
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        /*Left Array*/
        for (int i=0;i<n;i++) {
            while (!st.empty() && heights[st.top()]>=heights[i]) {
                st.pop();
            }
            if (st.empty()){
                left[i]=-1;
            }
            else{
                left[i]=st.top();
            }
            st.push(i);
        }
        while (!st.empty()){
            st.pop();
        }
        /*Right Array*/
        for (int i=n-1;i>=0;i--) {
            while (!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if (st.empty()){
                right[i]=n;
            }
            else{
                right[i]=st.top();
            }
            st.push(i);
        }
        for (int i=0;i<n;i++) {
            area[i]=heights[i]*(right[i]-left[i]-1);
        }
        int maxArea=area[0];
        for (int i=1;i<area.size();i++){
            if (maxArea<area[i]){
                maxArea=area[i];
            }
        }
        return maxArea;
    }
};