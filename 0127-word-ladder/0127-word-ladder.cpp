class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> que;
        que.push(beginWord);
        set<string> st(wordList.begin(),wordList.end());
        int level=1;
        while (!que.empty()){
            int size=que.size();
            for (int i=0;i<size;i++){
                string currStr=que.front();
                if (currStr==endWord) return level;
                que.pop();
                for (int i=0;i<currStr.size();i++){
                    char tempChar=currStr[i];
                    for (char ch='a';ch<='z';ch++){
                        currStr[i]=ch;
                        if (st.find(currStr)!=st.end()){
                            que.push(currStr);
                            st.erase(currStr);
                        }
                    }
                    currStr[i]=tempChar;
                }
            }
            level++;
        }
        return 0;
    }
};