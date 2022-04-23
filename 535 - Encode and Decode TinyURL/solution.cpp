class Solution {
public:
    unordered_map<int, string> mp;
    int num = 0;
    string url = "http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = url + to_string(num);
        mp[num++] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int idx = stoi(shortUrl.substr(19));
        return mp[idx];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));