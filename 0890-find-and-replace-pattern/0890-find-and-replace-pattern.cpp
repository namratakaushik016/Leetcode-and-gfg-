class Solution {
public:
    void createMapping(string& str){
        //find mapping
        char start='a';
        char mapping[300]={0};
        
        for(auto ch:str){
            if(mapping[ch]==0){
                mapping[ch]=start;
                start++;
            }
        }
        //update the string
        
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            str[i]=mapping[ch];
            
        }
        
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        
        //first normalise the pattern
        createMapping(pattern);
        //saare words ke sth khelna ha
        for(string s:words){
            string tempString=s;
            //normalising tempString
            createMapping (tempString);
            
            if(tempString == pattern){
                ans.push_back(s);
                
            }
        }
        return ans;
    }
};