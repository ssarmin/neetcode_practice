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
    // Comparator function to sort intervals by their start value
    static bool compareIntervals(const Interval& i1, const Interval& i2) {
        return i1.start < i2.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compareIntervals);

        // Min priority queue (min-heap) using greater<int>
        priority_queue<int, vector<int>, greater<int>> minPQ;

        for(auto m_time: intervals){
            if(minPQ.empty()){
                minPQ.push(m_time.end);
            }else{
                if(minPQ.top() > m_time.start){
                    minPQ.push(m_time.end);
                }else{
                    minPQ.pop();
                    minPQ.push(m_time.end);
                }
            }
        }
        return minPQ.size();
    }
    
};

/*
Extra test case:
intervals=[(1,5),(2,6),(3,7),(4,8),(5,9)]
*/
