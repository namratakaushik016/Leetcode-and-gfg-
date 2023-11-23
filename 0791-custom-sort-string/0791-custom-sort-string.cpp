class Solution {
public:
    static string str;
        static bool compare(char char1,char char2){
         //this will retunr true if position of char1 in str string is less than the position   
            // char2 in str string 
            
            return (str.find(char1)<str.find(char2));
        }
        
    
    string customSortString(string order, string s) {
        
        str=order;
        sort(s.begin(),s.end(),compare);
        return s;
        
        
    }
    
};
string Solution::str;