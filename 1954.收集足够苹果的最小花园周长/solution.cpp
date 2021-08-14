typedef long long ll;
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        ll ans=2;
        ll cur=12;
        ll lst=12;
        ll step=2;
        while (cur<neededApples) {
            ans+=2;
            step+=4;
            ll now=lst+6*step;
            cur+=now;
            lst=now;
        }
        return ans*4;
    }
};