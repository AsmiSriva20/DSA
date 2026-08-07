class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> givenWords(wordList.begin(), wordList.end());

        if (givenWords.find(endWord) == givenWords.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        givenWords.erase(beginWord);

        int steps = 1;

        while (!q.empty()) {

            int n = q.size();

            while (n--) {

                string word = q.front();
                q.pop();

                if (word == endWord)
                    return steps;

                for (int i = 0; i < word.size(); i++) {

                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        word[i] = ch;

                        if (givenWords.find(word) != givenWords.end()) {

                            q.push(word);
                            givenWords.erase(word);
                        }
                    }

                    word[i] = original;
                }
            }

            steps++;
        }

        return 0;
    }
};