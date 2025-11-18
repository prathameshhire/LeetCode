class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() == 1) return true;
        for(int i=0;i<bits.size()-1;i++){
            if(bits[i] == 1){
                if(i+1 == bits.size()-1) return false;
                else i++;
            }
        }
        return true;
    }
};
