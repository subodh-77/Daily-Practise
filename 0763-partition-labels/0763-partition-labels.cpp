class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int>res;
        vector<int>freq(26,0);
        for(int i = 0;i<n;i++){
            freq[s[i]-'a']=i;
        }
        int max_so_far = 0;
        int j = 0;
        for(int i = 0;i<n;i++){
           int last_index = freq[s[i]-'a'];
           max_so_far = max(max_so_far,last_index);
          if(max_so_far==i){res.push_back(max_so_far-j+1);j=last_index+1;}
            
            
        }
        return res;
    }
};