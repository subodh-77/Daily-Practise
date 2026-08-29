class Solution {
public:
bool possibleHa(vector<int>& time,long long givenTime, int totalTrips){
    long long actualTrip = 0;
    for(auto &it:time){
        actualTrip+= givenTime/it;
    }
    return actualTrip>=totalTrips;
}
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1;
        long long r =(long long)*min_element(begin(time),end(time))*totalTrips;

        while(l<r){
            long long mid = l+(r-l)/2;
            if(possibleHa(time,mid,totalTrips)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};