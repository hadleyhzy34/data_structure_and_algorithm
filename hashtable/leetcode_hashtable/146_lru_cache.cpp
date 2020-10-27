class LRUCache {
public:
    LRUCache(int capacity):size(capacity) {
    }
    
    int get(int key) {
        if(kv.count(key)==0){
        	return -1;
        }else{
        	update(key);
        	return kv[key];
        }
    }
    
    void put(int key, int value) {
        if(kv.count(key)==0){
        	if(lru.size()==size){
        		evict();
        	}
        	update(key);
        	kv[key]=value;
        }else{
        	update(key);
        	kv[key]=value;
        }
    }

    void update(int key){
    	if(kv.count(key)){
    		lru.erase(kp[key]);
    	}
    	lru.push_front(key);
    	kp[key]=lru.begin();
    }

    void evict(){
    	kv.erase(lru.back());
    	kp.erase(lru.back());
    	lru.pop_back();
    }
private:
	//lru
	list<int>lru;
	//key->value
	unordered_map<int,int>kv;
	//key->position at lru
	unordered_map<int,list<int>::iterator>kp;
	int size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */