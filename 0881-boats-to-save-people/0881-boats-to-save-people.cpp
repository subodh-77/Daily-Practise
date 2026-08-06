// class Solution {
// public:
//     int numRescueBoats(vector<int>& people, int limit) {
//         int n = people.size();
//         sort(people.begin(),people.end());
//         int count = 0;
//         int sum = 0;
//         int i = 0,j=n-1;

//         while(j>=0&&i<=j){
//             if(people[j]==limit){count++;j--;}
//             else if(people[j]<limit){
//                 sum = sum+ people[j]+people[i];
//                 cout<<"sumfirst"<<sum<<endl;
//                 if(sum==limit){
//                     count++;
//                     i++;
//                     j--;
//                     sum = 0;
//                     cout<<"sumsec"<<sum<<endl;
//                 }
//                 else if(sum>limit){
//                     count++;
//                     sum-=people[j];
//                     j--;
                    
//                     cout<<"sumthird"<<sum<<endl;
//                 }
//                 else if(sum<limit){
//                     while(i<j&&sum<=limit){
//                         cout<<"sumfourth bef"<<sum<<endl;
//                         i++;
//                         sum += people[i];
//                         cout<<"sumfourth"<<sum<<endl;
//                     }
//                 }
//             }
            
//         }
//         cout<<sum<<endl;
//         return count;
//     }
// };
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int sum = 0;
        sort(people.begin(),people.end());
        int count = 0;
        int i = 0,j=n-1;
        while(i<=j){
            sum = people[i]+people[j];
            if(sum<=limit){
                count++;
                i++;
                j--;
            }
            else {
                j--;
                count++;
            }
        }
        return count;
    }
};