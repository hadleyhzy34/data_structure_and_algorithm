/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
	void dfs(std::vector<NestedInteger> &nestedList,vector<int>&res){
		for(int i=0;i<nestedList.size();i++){
			if(nestedList[i].isInteger()){
				res.push_back(nestedList[i].getInteger());
			}else{
				dfs(nestedList[i].getList(),res);
			}
		}
	}

    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList,res);
    }
    
    int next() {
        if(index<res.size()){
        	return res[index++];
        }else{
            return 0;
        }
    }
    
    bool hasNext() {
        if(index<res.size()){
        	return true;
        }else{
        	return false;
        }
    }
private:
	int index=0;
	vector<int>res;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */