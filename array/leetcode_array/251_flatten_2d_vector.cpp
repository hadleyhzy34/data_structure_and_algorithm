class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
    	for(int i=0;i<v.size();i++){
    		for(int j=0;j<v[i].size();j++){
    			q.push(v[i][j]);
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
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */