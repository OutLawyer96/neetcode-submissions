class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> upper;
    priority_queue<int> lower;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lower.size()==upper.size()){
            lower.push(num);
        }else{
            upper.push(num);
        }
        if(upper.size()>0 && lower.size()>0){
            while(upper.top()<lower.top()){
                lower.push(upper.top());
                upper.pop();
                upper.push(lower.top());
                lower.pop();
            }
        }
    }
    
    double findMedian() {
        if(lower.size()==upper.size()){
            return (upper.top()+lower.top())/2.0;
        }else{
            return lower.top();
        }
    }
};
