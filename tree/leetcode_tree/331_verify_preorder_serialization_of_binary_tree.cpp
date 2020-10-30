class Solution {
public:
    bool isValidSerialization(string preorder) {
    	if(preorder.empty())return true;
    	int node=1;
    	for(int i=0;i<preorder.size();i++){
            string temp;
            while(i<preorder.size()&&preorder[i]!=','){
                temp+=preorder[i];
                i++;
            }
            node--;
            if(node<0){
                return false;
            }
            if(temp.size()==1&&temp[0]=='#'){
                
            }else{
                node+=2;
            }
    	}
    	return node==0;
    }
};