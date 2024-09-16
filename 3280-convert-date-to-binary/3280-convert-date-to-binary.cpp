class Solution {
public:
    string convertDateToBinary(string date) {
        int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
        int month = (date[5] - '0') * 10 + (date[6] - '0');
        int day = (date[8] - '0') * 10 + (date[9] - '0');
        long long yr=0;
        int mn=0;
        int d=0;
        int i=0;
        int j=0;
        int k=0;
        while (year!=0) {
            int bit = year & 1;
            yr = (bit * pow(10,i)) + yr;
            year = year >> 1;
            i++;
        }
        while (month!=0) {
            int bit = month & 1;
            mn = (bit * pow(10,j)) + mn;
            month = month >> 1;
            j++;
        }
        while (day!=0) {
            int bit = day & 1;
            d = (bit * pow(10,k)) + d;
            day = day >> 1;
            k++;
        }
        string syear = "";
        string smonth = "";
        string sday = "";
        while (yr > 0) {
            int digit = yr % 10;  
            syear += (digit + '0'); 
            yr /= 10;
        }
        while (mn > 0) {
            int digit = mn % 10;  
            smonth += (digit + '0');  
            mn /= 10;
        }
        while (d > 0) {
            int digit = d % 10;  
            sday += (digit + '0');  
            d /= 10;
        }
        reverse(syear.begin(), syear.end());
        reverse(smonth.begin(), smonth.end());
        reverse(sday.begin(), sday.end());
        return syear + "-" + smonth + "-" + sday;
}
};