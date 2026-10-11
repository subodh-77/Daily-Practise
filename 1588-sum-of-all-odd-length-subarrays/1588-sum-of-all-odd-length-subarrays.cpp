class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
         vector<int>psum(n);
         psum[0]=arr[0];
         for(int i = 1;i<n;i++){
           psum[i]=arr[i]+psum[i-1];
            
         }
    int sum = 0;
         for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if((j-i+1)%2!=0){
                    if(i==0){sum+=psum[j];
                    cout<<sum<<endl;}
                    else if(i==j)sum+=arr[j];
                    else{
                        sum+=psum[j]-psum[i-1];
                        cout<<sum<<endl;
                    }
                }
            }
         }
         return sum;

    }
};