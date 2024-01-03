class Solution {
public:
    
    //unordered map to store mappings between indices before and after flipping element
   unordered_map <int, int> holes;
   int n;//for rows
   int m;//for columns
   int size;//m*n
    
    
   Solution(int n_rows, int n_cols) {
       
      srand(time(NULL));//Seeds the random number generator with the current time
      n = n_rows;
      m = n_cols;
      size = n * m;
   }
    
    
    vector<int> flip() {
    
     int id = rand() % size;//Generates a random index id within the current size.
     size--;// Decrements the size to represent that an element has been flipped.
     int rid = id;//creates the copy of the original index;
      if(holes.count(id)){
         id = holes[id];
      }
      holes[rid] = holes.count(size) ? holes[size] : size;
      return {id / m, id % m};   
    }
    
    void reset() {
      size = n * m;
      holes.clear();   
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */