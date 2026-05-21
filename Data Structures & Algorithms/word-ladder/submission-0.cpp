class Solution {
   public:
    bool isEdgePossible(string a, string b) {
        if (a.size() != b.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
            }
        }
        return diff == 1;
    }
    int bfs(string& start, string& end, unordered_map<string, vector<string>>& adj) {
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({start, 0});
        while (!q.empty()) {
            pair<string, int> topPair = q.front();
            q.pop();
            visited.insert(topPair.first);
            if (topPair.first == end) {
                return topPair.second + 1;
            }
            for (auto& neighbour : adj[topPair.first]) {
                if (visited.find(neighbour) == visited.end()) {
                    q.push({neighbour, topPair.second + 1});
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        unordered_map<string, vector<string>> adj;
        adj[beginWord] = vector<string>();
        for (auto& word : wordList) {
            adj[word] = vector<string>();
        }
        for (auto& word : wordList) {
            if (isEdgePossible(beginWord, word)) {
                adj[word].push_back(beginWord);
                adj[beginWord].push_back(word);
            }
        }
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (isEdgePossible(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        return bfs(beginWord, endWord, adj);
    }
};