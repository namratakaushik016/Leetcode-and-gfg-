class Solution {
public:
    bool isvowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
    
    string reverseVowels(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<r){
            if(isvowel(s[l]) && isvowel(s[r])){
                swap(s[l],s[r]);
                l++;
                r--;
            }
            else if(!isvowel(s[l])){
                l++;
            }
               
            
            else{
                r--;
            }
        }
        return s;
    }
};