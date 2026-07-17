class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()- 1;
        int j = b.length() - 1;
        int carry = 0;
        string result = "";
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) {
                sum = sum + (a[i] -'0');
                i--;
            }
            if (j >= 0) {
                sum=sum+(b[j]-'0');
                j--;
            }
            if(sum==0){
                result='0'+result;
                carry=0;
            }
            else if(sum==1){
                result='1'+result;
                carry=0;
            }
            else if(sum==2){
                result='0'+result;
                carry=1;
            }
            else {   
                result='1'+result;
                carry=1;
            }
        }
        if(carry==1){
            result='1'+result;
        }
        return result;
    }
};