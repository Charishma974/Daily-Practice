class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> st(bank.begin(),bank.end());
        queue<string> que;
        que.push(startGene);
        int level=0;
        vector<char> choices{'A','C','G','T'};
        while (!que.empty()){
            int size=que.size();
            for (int i=0;i<size;i++){
                string currStr=que.front();
                if (currStr==endGene) return level;
                que.pop();
                for (auto ch:choices){
                    for (int i=0;i<currStr.size();i++){
                        char currCh=currStr[i];
                        currStr[i]=ch;
                        if (st.find(currStr)!=st.end()){
                            que.push(currStr);
                            st.erase(currStr);
                        }
                        currStr[i]=currCh;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};