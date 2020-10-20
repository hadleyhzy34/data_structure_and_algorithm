class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    	int n1=v1.size(),n2=v2.size();
    	bool even=true;
    	for(int i=0;i<max(n1,n2);i++){
    		if(i>=n1){
    			q.push(v2[i]);
    		}else if(i>=n2){
    			q.push(v1[i]);
    		}else{
    			if(even){
    				q.push(v1[i]);
    				even=false;
                    i--;
    			}else{
    				q.push(v2[i]);
    				even=true;
    			}
    		}
    	}
    }

    int next() {
        int n=q.front();
        q.pop();
        return n;
    }

    bool hasNext() {
        return !q.empty();
    }
private:
	queue<int> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */