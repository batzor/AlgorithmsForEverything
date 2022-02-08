class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int clockwise_dist = 0;
        int total_dist = 0;
        
        for(int i = 0;i < distance.size(); i++){
            if(i >= min(start,destination) && i < max(start, destination)){
                clockwise_dist += distance[i];
            }
            total_dist += distance[i];
        }
        
        if(total_dist / 2 >= clockwise_dist)
            return clockwise_dist;
        else
            return total_dist - clockwise_dist;
    }
};