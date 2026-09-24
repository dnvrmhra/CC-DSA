class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score){
        vector<string> answer;
        vector<int> sorted=score;
        sort(sorted.begin(), sorted.end(), greater<>());
        for (int i=0;i<score.size();i++){
            int rank=find(sorted.begin(), sorted.end(), score[i])-sorted.begin()+1;
            if (rank==1){
                answer.push_back("Gold Medal");
            }
            else if (rank==2){
                answer.push_back("Silver Medal");
            }
            else if (rank==3){
                answer.push_back("Bronze Medal");
            }
            else{
                answer.push_back(to_string(rank));
            }
        }
        return answer;
    }
};