class DataStream {
    private:
    int Val=0;
    int count=0;
    int K=0;
public:
    DataStream(int value, int k) {
        Val=value;
        count=0;
        K=k;
    }
    
    bool consec(int num) {
        if(num==Val){
            count++;
            return count>=K;
        }
        else{
            count=0;
            return false;
        }
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */