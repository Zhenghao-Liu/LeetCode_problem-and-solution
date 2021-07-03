/*
 * 设置一个dp的pair类型{x,y}
   x表示变成0的最小步数，y表示变成1的最小步数
 * 对于数字0，dp的步数是{0,1}
   对于数字1，dp的步数是{1,0}
 * 假设有数字a，和数字b，当前操作是&操作，暂且只考虑变换数字不考虑变换运算符
   对于数字a来说步数是{x1,y1}，对于数字b来说步数是{x2,y2}，
   那么对于&运算后的结果，步数是{min(x1+x2,x1+y2,x2+y1),y1+y2}
   因为只有1&1==1，其他情况答案都是0，所以取最小情况
 * 假设有数字a，和数字b，当前操作是|操作，暂且只考虑变换数字不考虑变换运算符
   对于数字a来说步数是{x1,y1}，对于数字b来说步数是{x2,y2}，
   那么对于|运算后的结果，步数是{x1+x2,min{x1+x2,x2+y1,y1+y2}}
   因为只有0|0==0，其他情况答案都是1，所以取最小情况
 * 那么加上考虑变换运算符呢
 * 对于&运算，只需要在运算完|运算后，将结果的数字进行修改即可
   所以&运算下步数是{min(xAnd,xOr+1),min(yAnd,yOr+1)}
 * 对于|运算，只需要在运算完&运算后，将结果的数字进行修改即可
   所以|运算下步数是{min(xOr,xAnd+1),min(yOr,yAnd+1)}
 * 为了去模拟这个dp运算，需要用一个dp结果栈，以及一个符号栈
 * 且其中是有括号()的，设计思想有运算就进行运算，
   直到左边没有数字符号了，或者是左边遇到了'('，就停止
   如果向右遍历遇到了')'，因为括号内运算已经完成，所以符号栈直接出栈就行
 */
typedef pair<int, int> pii;
class Solution
{
public:
    int minOperationsToFlip(string expression) {
        stack<pii> dp;
        stack<char> sign;
        for (char i : expression) {
            if (i == '(' || i == '&' || i == '|') {
                sign.push(i);
                continue;
            }
            if (i == '0') {
                dp.push({0, 1});
            }
            else if (i == '1') {
                dp.push({1, 0});
            }
            else if (i == ')') {
                if (sign.empty() || sign.top() != '(') {
                    throw "wa";
                }
                sign.pop();
            }
            while (!sign.empty() && sign.top() != '(') {
                auto [x2, y2] = dp.top();
                dp.pop();
                auto [x1, y1] = dp.top();
                dp.pop();
                auto [xAnd, yAnd] = dpAnd(x1, x2, y1, y2);
                auto [xOr, yOr] = dpOr(x1, x2, y1, y2);
                char sig = sign.top();
                sign.pop();
                if (sig == '&') {
                    dp.push({min(xAnd, xOr + 1), min(yAnd, yOr + 1)});
                }
                else if (sig == '|') {
                    dp.push({min(xOr, xAnd + 1), min(yOr, yAnd + 1)});
                }
            }
        }
        return max(dp.top().first, dp.top().second);
    }
    pii dpAnd(int x1, int x2, int y1, int y2)
    {
        return {min(x1 + x2, min(x1 + y2, x2 + y1)), y1 + y2};
    }
    pii dpOr(int x1, int x2, int y1, int y2)
    {
        return {x1 + x2, min(x1 + y2, min(x2 + y1, y1 + y2))};
    }
};