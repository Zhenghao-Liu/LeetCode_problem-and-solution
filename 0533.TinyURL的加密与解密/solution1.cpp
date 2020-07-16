//按存入的顺序序号来压缩
class Solution {
    vector<string> dict;
    int i=0;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        dict.push_back(longUrl);
        ++i;
        return "http://tinyurl.com/"+to_string(i-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int index=stoi(shortUrl.substr(19));
        return dict.at(index);
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
