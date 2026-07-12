class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>brr=arr;
        sort(brr.begin(),brr.end());
        map<int ,int>mp;
        if(brr.size()>0)mp[brr[0]]=1;
        int count = 2;
        for(int i = 1;i<brr.size();i++){
            if(brr[i-1]==brr[i])mp[brr[i]]=mp[brr[i-1]];
            else {
                 mp[brr[i]]=count++;
            }
           
        }
        for(int i = 0;i<brr.size();i++){
            brr[i]=mp[arr[i]];
        }
        return brr;

    }
};