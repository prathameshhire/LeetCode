class Solution {
public:
    bool isSubstringPresent(string s) {
        int n=s.length();
        if(n<2)return false; 
         string temp1=s;
         string temp2=s;
         reverse(temp2.begin(),temp2.end());
         for(int i=0;i+1<n;i++){
            string sub=temp1.substr(i,2);

            for(int j=0;j+1<n;j++){
                if(temp2[j]==sub[0] && temp2[j+1]==sub[1]){
                    return true;
                }
            }

         }
         return false;
    }
};

    