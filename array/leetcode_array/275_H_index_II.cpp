class Solution {
public:
    int hIndex(vector<int>& citations) {
        reverse(citations.begin(),citations.end());
        int hIndex=0;
        for(int i=0;i<citations.size();i++){
        	if(citations[i]>=(i+1)){
        		hIndex=i+1;
        	}
        }
        return hIndex;
    }
};

//binary search
class Solution2 {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int i=0,j=n-1,mid,h_index;
        while(i<=j){
            mid=i+(j-i)/2;
            if(citations[mid]==n-mid){
                // cout<<citations[mid]<<" "<<mid<<" "<<n-mid<<endl;
                return n-mid;
            }else{
                if(citations[mid]<n-mid){
                    i=mid+1;
                }else{
                    if(mid==0||citations[mid-1]<n-mid+1){
                        // cout<<citations[mid]<<" "<<mid<<" "<<n-mid<<endl;
                        return n-mid;
                    }else{
                        j=mid-1;
                    }
                }
            }
        }
        return 0;
    }
};