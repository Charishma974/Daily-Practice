class Solution {
public:
    string largestGoodInteger(string num) {
        string substring="";
        for (int i=0;i<num.size()-2;i++){
            if (num[i]==num[i+1] && num[i+1]==num[i+2]){
                if (substring.empty() || substring[0]-'0'<num[i]-'0'){
                    substring=num.substr(i,3);
                }
            }
        }
        return substring;
    }
};