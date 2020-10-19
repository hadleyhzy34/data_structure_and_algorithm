
//hash map
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>map;
    	for(auto &x:nums){
    		map[x]++;
    	}
    	vector<int>res;
    	for(auto &x:map){
    		if(x.second==1){
    			res.push_back(x.first);
    		}
    	}
    	return res; 
    }
};


//bit manipulation
class Solution2 {
public:
    vector<int> singleNumber(vector<int>& nums) {
    	int bit_mask=0;
    	for(auto &x:nums){
    		bit_mask^=x;
    	}

    	//right most 1 bit from bit_mask
    	int x_mask=bit_mask&(-bit_mask);

    	int x=0;
    	for(auto &num:nums){
    		if((x_mask&num)!=0){
    			x^=num;
    		}
    	}
        int y=bit_mask^x;
        return {x,y};
    }
};