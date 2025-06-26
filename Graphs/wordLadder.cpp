class Solution {
    //TC: O(N*word_length*26)
    //SC: O(N*L+N*L)=O(N*L)   (queue+set)
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //bfs technique
        queue<pair<string,int>>q;
        //copy to set for searching
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        

        while(!q.empty()) {
            string word= q.front().first;
            int steps= q.front().second;
            q.pop();

            if(word==endWord) return steps;

            //perform bfs
            for(int i=0; i<word.size(); i++) {
                char original= word[i];
                for(char ch='a'; ch<='z'; ch++) {
                    word[i]=ch;
                    //if it exists in set
                    if(st.find(word)!=st.end()) {
                        //push into queue and mark vis
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};