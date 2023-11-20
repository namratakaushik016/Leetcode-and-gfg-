class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
            int pickp=0;
            int pickg=0;
            int pickm=0;
        
        
        int travelp=0;
        int travelg=0;
        int travelm=0;
        
        int lastp=0;
        int lastg=0;
        int lastm=0;
        
        //calculating pick time and travel time
        for(int i=0;i<garbage.size();i++){
            string curr=garbage[i];
            for(int j=0;j<curr.length();j++){
                char ch=curr[j];
                
                if(ch=='P'){
                    pickp++;
                    lastp=i;
                }
                else if(ch=='G'){
                    pickg++;
                    lastg=i;
                }
                else if(ch=='M'){
                    pickm++;
                    lastm=i;
                }
            }
        }
        //calculating travel time
        for(int i=0;i<lastp;i++){
            travelp+=travel[i];
        }
        for(int i=0;i<lastg;i++){
            travelg+=travel[i];
        }
        for(int i=0;i<lastm;i++){
            travelm+=travel[i];
        }
        int ans=(pickp+travelp)+(pickg+travelg)+(pickm+travelm);
        return ans;
    }
};