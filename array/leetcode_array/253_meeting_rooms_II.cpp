//min_heap, sort
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty())return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>&a,vector<int>&b){
        	return a[0]<b[0];
        });


		priority_queue<int,vector<int>,greater<int>>pq;
		pq.push(intervals[0][1]);



        for(int i=1;i<intervals.size();i++){
        	if(intervals[i][0]<pq.top()){
        		pq.push(intervals[i][1]);
        	}else{
                pq.pop();
        		pq.push(intervals[i][1]);
        	}
        }
        return pq.size();
    }
};