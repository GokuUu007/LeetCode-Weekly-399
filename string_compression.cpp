class Solution {
public:
    string compressedString(string word) {
        vector<int> len;
        char prev = '0';
        for (auto &c : word) {
            if (prev != c) {
                len.push_back(1);
            } else {
                len.back() += 1;
            }
            prev = c;
        }
        word.resize(unique(begin(word), end(word)) - begin(word));
        string ans;
        for (int i = 0; i < int(word.size()); ++i) {
            while (len[i] >= 9) {
                ans += '9', ans += word[i], len[i] -= 9;
            }
            if (len[i])
                ans += char(len[i] + '0'), ans += word[i];
        }
        return ans;
    }
};
