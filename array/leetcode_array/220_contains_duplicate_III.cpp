class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int, int>> hh;
        int sz= nums.size();
        cout<<sz<<endl;
        for( int i = 0; i < nums.size(); i ++)
            hh.push_back( make_pair(nums[i], i));
        
        
        sort( hh.begin(), hh.end());
        
        for(int i =0; i < nums.size()-1; i ++){
            cout<<nums.size()-1<<" "<<sz<<" "<<i<<endl;
            for( int j =i +1; j < sz; j ++){
                cout<<nums.size()-1<<" "<<sz<<" "<<j<<endl;
                if(hh[i].first +t < hh[j].first)
                   break;
                
                if( abs(hh[j].second - hh[i].second) <= k)
                    return true;
            }
        }
                   
        return false;
    }
};

class Solution2{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k==0){
            return false;
        }
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j-i<=k&&j<nums.size();j++){
                long temp=long(nums[j])-long(nums[i]);
                if(temp<=long(t)&&temp>=long(-t)){
                    return true;
                }
            }
        }           
        return false;
    }
}

class Solution3{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int,int>map;
        int n=num.size();

        for(int i=0;i<nums.size();i++){
            auto it=map.lower_bound((long)nums[i]-t);
            if(it!=map.end()){
                return true;
            }
            map[nums[i]]=i;
            if(map.size()==k+1){
                map.erase(nums[i-k]);
            }
        }

        return false;

    }
}