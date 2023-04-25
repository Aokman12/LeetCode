class SmallestInfiniteSet {
    set<int> s;
    int curr;
public:
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        int answer;
        
        if (!s.empty()) {
            answer = *s.begin();
            s.erase(s.begin());
        } 
        
        else {
            answer = curr;
            curr = curr + 1;
        }
        return answer;
    }
    
    void addBack(int num) {
        if (curr <= num || 
            s.find(num) != s.end()) {
            return;
        }
        
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */