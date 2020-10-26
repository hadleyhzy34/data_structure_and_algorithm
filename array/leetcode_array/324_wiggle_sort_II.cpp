//sort
class Solution1 {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()<=1)return;
        vector<int>temp(nums);
        sort(temp.begin(),temp.end());

        int j=0,k=(nums.size()-1)/2+1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i&1){
                nums[i]=temp[k++];
            }else{
                nums[i]=temp[j++];
            }
        }
    }
};

