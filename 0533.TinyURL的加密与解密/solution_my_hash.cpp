//自己写哈希映射
class Solution {
    unordered_map<long long,string> dict;
    int base=INT_MAX;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        long long index=my_hash(longUrl);
        dict[index]=longUrl;
        return "http://tinyurl.com/"+to_string(index);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        long long index=stoll(shortUrl.substr(19));
        return dict.at(index);
    }

    long long my_hash(string &s)
    {
        long long ans=0;
        for (char &i:s)
        {
            ans=ans*41%base+i-'a'+1;
            ans%=base;
        }
        return ans;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
