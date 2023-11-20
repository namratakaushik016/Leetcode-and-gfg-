class Solution {
public:
    string decodeMessage(string key, string message) {
        //creating mapping
        
        char start='a';
        char mapping[280]={0};//0 islie dia ha jisse double mapping na ho ek hi albhabet ko 2 bar                                       mapping n krni pde
        
        for(auto ch: key){
            if(ch!=' ' && mapping[ch]==0){
                mapping[ch]=start;
                start++;
            }
        }
        
        string ans;
        for(auto ch:message){
            if(ch==' '){
                ans.push_back(' ');
            }
            else{
                char decodedChar=mapping[ch];
                ans.push_back(decodedChar);
            }
        }
        return ans;
    }
};