class Solution {
public:
    bool ispair(char last,char curr){
        return (last=='('&&curr ==')')||
        (last=='{'&&curr =='}')||
        (last=='['&&curr ==']');
    }
    bool isValid(string s) {
        stack<char>st;

        for(char curr:s){
            if(!st.empty()){
                char last = st.top();
                if(ispair(last,curr)){
                    st.pop();
                    continue;
                }
            }
            st.push(curr);// first case when stack is empty
        }
            return st.empty();
    }
};