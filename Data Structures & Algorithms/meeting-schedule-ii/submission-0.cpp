/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;
        int count = 0;
        for(auto& i: intervals){
            start.push_back(i.start);
            end.push_back(i.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int s = 0, e = 0;
        int res = 0;
        while(s<intervals.size()){
            if(start[s] < end[e]){
                count++;
                s++;
            }
            else{
                e++;
                count--;
            }
            res = max(res,count);
        }
        return res;
    }
};
