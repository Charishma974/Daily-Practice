class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for (auto str1:queries){
            for (auto str2:dictionary){
                int mismatchCnt=0;
                for (int i=0;i<str1.size();i++){
                    if (str1[i]!=str2[i]){
                        mismatchCnt++;
                        if (mismatchCnt>2) break;
                    }
                }
                if (mismatchCnt<=2){
                    result.push_back(str1);
                    break;
                }
            }
        }
        return result;
    }
};