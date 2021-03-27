class AuthenticationManager {
    int live;
    unordered_map<string,int> ump;
public:
    AuthenticationManager(int timeToLive) {
        live=timeToLive-1;
        ump.clear();
    }
    
    void generate(string tokenId, int currentTime) {
        ump[tokenId]=currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if (ump.find(tokenId)==ump.end() || ump.at(tokenId)+live<currentTime) {
            return;
        }
        ump.at(tokenId)=currentTime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans=0;
        for (auto &i:ump) {
            int st=i.second,ed=i.second+live;
            if (currentTime>=st && currentTime<=ed) {
                ans++;
            }
        }
        return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */