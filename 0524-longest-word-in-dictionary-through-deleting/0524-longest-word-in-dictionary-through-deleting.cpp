
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string res;
        for (int i = 0; i < dictionary.size();i++)
        {
            string &word = dictionary[i];

            if (word.size() > s.size() ||  word.size() < res.size())
                continue;

            auto found =  s.find(word[0]); 

            int j = 1;
            for (j; j < word.size(); j++)
            {    
                found = s.find(word[j],found+1);
                if (found == string::npos)
                    break;                                              
            }
            if (found == string::npos)
                continue;

            if (j > res.size())
            {
                 res = word;
                 continue;
            }
            if (j == res.size())
            {
                for (int i = 0; i < res.size();i++)
                {
                    if (word[i] < res[i])
                    {
                        res = word;
                        break;
                    }
                    else if (word[i] == res[i])
                        continue;
                    else
                        break;
                }
            }
        }
        return res;
    }
};