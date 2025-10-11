
// 739. Daily Temperatures

/*
    Approach: Use Stack, it's the problem of finding the Nearest Greater Right in a Array.
    TC: O(n)

 */
class Solution {
public:
    #define pii pair<int,int> 
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       
        vector<int> result;
        stack<pii> st;
        int n=temperatures.size();
        for(int i=n-1;i>=0;i--){
            if(st.size()==0){
                result.push_back(0);
                
            }else{
                if(st.size()>0 && st.top().first > temperatures[i]){
                    result.push_back((st.top().second-i));
                }else{
                    while(st.size()>0 && st.top().first<=temperatures[i]){
                        st.pop();
                    }
                    if(st.size()==0){
                result.push_back(0);
                
            }
                   else if(st.size()>0 && st.top().first > temperatures[i]){
                    result.push_back((st.top().second-i));
                }
                }
            }
            st.push({temperatures[i],i});
        }
        reverse(result.begin(),result.end());
        return result;
    }
};