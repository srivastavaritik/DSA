class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i=0, j=tokens.size()-1, score=0, maxScore=0;
        while(i<=j)
        {
            if(power >= tokens[i])
            {
                power -= tokens[i];
                i++;
                score++;
                maxScore = max(maxScore, score);
            }
            else if(score>0)
            {
                score--;
                power += tokens[j];
                j--;
            }
            else break;
        }
        return maxScore;
    }
};