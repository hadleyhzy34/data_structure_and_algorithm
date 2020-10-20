/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    ret =-1;
        peeked=false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(peeked){
            return ret;
        }
        peeked=true;
        ret = Iterator::next();
        return ret;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(peeked){
            peeked=false;
            return ret;
        }
        ret=Iterator::next();
        return ret;
	}
	
	bool hasNext() const {
	    return Iterator::hasNext()||peeked;
	}
private:
    int ret;
    bool peeked;
};