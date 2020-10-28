/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
    	for(int i=0, j=0;i<n;i++){
    		//i is celebrity candidate
    		for(j=0;j<n;j++){
    			//i is not celebrity
    			if(i!=j&&knows(i,j))break;
    			//j does not know i
    			if(i!=j&&!knows(j,i))break;
    		}
    		if(j==n)return i;
    	}
    	return -1;
    }
};