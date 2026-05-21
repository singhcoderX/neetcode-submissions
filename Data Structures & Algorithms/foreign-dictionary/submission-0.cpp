class Solution {
   public:
    vector<char> getUniqueLetters(vector<string>& words, unordered_set<char>& lettersBucket) {
        vector<char> ans;
        for (auto& word : words) {
            for (auto& letter : word) {
                if (lettersBucket.find(letter) == lettersBucket.end()) {
                    ans.push_back(letter);
                    lettersBucket.insert(letter);
                }
            }
        }
        return ans;
    }
    pair<char, char> getEdgeFromWord(string a, string b) {
        int i = 0;
        while (i < a.size() && i < b.size()) {
            if (a[i] == b[i]) {
                i++;
            } else {
                return {a[i], b[i]};
            }
        }
        // a is prefix of b
        if (i == a.size()) {
            return {'1', '1'};
        }
        // b is prefix of a - wrong input
        return {'0','0'};
    }
    void findTopoSort(char letter, unordered_set<char>& visited,
                      unordered_map<char, vector<char>>& adj, stack<char>& st,
                      unordered_set<char>& current, bool& isCyclePresent) {
        if (current.find(letter) != current.end()) {
            isCyclePresent = true;
            return;
        }
        if (visited.find(letter) != visited.end()) {
            return;
        }
        visited.insert(letter);
        current.insert(letter);
        for (auto& neighbour : adj[letter]) {
            findTopoSort(neighbour, visited, adj, st, current, isCyclePresent);
            if (isCyclePresent) {
                return;
            }
        }
        st.push(letter);
        current.erase(letter);
    }
    string foreignDictionary(vector<string>& words) {
        unordered_set<char> lettersBucket;
        // Important to have ordering preserved
        vector<char> letters = getUniqueLetters(words, lettersBucket);
        unordered_map<char, vector<char>> adj;
        for (auto& letter : letters) {
            adj[letter];  // initialize
        }
        for (int i = 1; i < words.size(); i++) {
            pair<char, char> edge = getEdgeFromWord(words[i - 1], words[i]);
            if (edge.first == '0' && edge.second == '0') {
                return "";
            } else if (edge.first != '1' && edge.second != '1') {
                // valid Edge
                adj[edge.first].push_back(edge.second);
            }
        }
        stack<char> st;
        unordered_set<char> visited;
        unordered_set<char> current;
        bool isCyclePresent = false;
        for (auto& letter : letters) {
            if (visited.find(letter) == visited.end()) {
                findTopoSort(letter, visited, adj, st, current, isCyclePresent);
            }
        }
        if (isCyclePresent) {
            return "";
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
