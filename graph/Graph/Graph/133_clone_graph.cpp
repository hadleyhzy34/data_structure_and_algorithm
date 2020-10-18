// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    void graphClone(Node* node, Node* clone){
        clone->val=node->val;
        if(clonelist.size()<=clone->val){
            clonelist.resize(clone->val+1);
            clonelist[clone->val]=clone;
        }else{
            clonelist[clone->val]=clone;
        }
        for(auto x:node->neighbors){
            if(x->val>=clonelist.size()||clonelist[x->val]==nullptr){
                Node* adj=new Node(x->val);
                clone->neighbors.push_back(adj);
                graphClone(x, adj);
            }else{
                clone->neighbors.push_back(clonelist[x->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        vector<Node*>clonelist;
        Node* clone = new Node();
        graphClone(node, clone);
        return clone;
    }
private:
    vector<Node*>clonelist;
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        Node* clone=new Node(node->val);
        list[node->val]=clone;

        for(auto &x:node->neighbors){
            if(list.find(x->val)==list.end()){
                Node* adj=cloneGraph(x);
                clone->neighbors.push_back(adj);
            }else{
                clone->neighbors.push_back(list[x->val]);
            }
        }
        return clone;
    }
private:
    unordered_map<int,Node*>list;
};