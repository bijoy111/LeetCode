class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int size1=rowSum.size();
        int size2=colSum.size();
        vector<vector<int>> vec(size1, vector<int>(size2, 0));
        for(int i=0;i<size1;i++)
        {
            for(int j=0;j<size2;j++)
            {
                vec[i][j]=min(rowSum[i],colSum[j]);
                rowSum[i]-= vec[i][j];
                colSum[j]-=vec[i][j];
            }
        }
        return vec;

    }
};