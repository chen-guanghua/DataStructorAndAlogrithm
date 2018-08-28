#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
//时间复杂度M*N,空间复杂度M*N
int minPathSum1(vector<vector<int> > & m)
{
    if(m.size() == 0 || m[0].size() == 0)
        return 0;
    int row = m.size();
    int col = m[0].size();
    vector<vector<int> > dp(row, vector<int>(col, 0));
    dp[0][0] = m[0][0];
    for(int i = 1; i < col; ++i)
        dp[0][i] = dp[0][i - 1] + m[0][i];
    for(int i = 1; i < row; ++i)
        dp[i][0] = dp[i - 1][0] + m[i][0];
    for(int i = 1; i < row; ++i)
        for(int j = 1; j < col; ++j)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + m[i][j];
    return dp[row - 1][col - 1];
}
//时间复杂度M*N,空间复杂度min(M,N)
int minPathSum2(vector<vector<int> > &m)
{
    if(m.size() == 0 || m[0].size() == 0)
        return 0;
    int more = max(m.size(), m[0].size());
    int less = more == m.size() ? m[0].size() : m.size();
    bool rowmore = more == m.size();//行数是否大于等于列数
    vector<int> arr(less);
    arr[0] = m[0][0];
    for(int i = 1; i < less; ++i)
        arr[i] = arr[i - 1] + (rowmore ? m[0][i] : m[i][0]);
    for(int i = 1; i < more; ++i)
    {
        arr[0] = arr[0] + (rowmore ? m[i][0] : m[0][i]);
        for(int j = 1; j < less; ++j)
            arr[j] = min(arr[j - 1], arr[j]) + (rowmore ? m[i][j] : m[j][i]);
    }
    return arr[less - 1];
}

void printMatrix(vector<vector<int> > &m) {
    if (m.size() == 0 || m[0].size() == 0) {
        return;
    }

    size_t row = m.size();
    cout<<"row:"<<row<<endl;
    size_t column = m[0].size();
    cout<<"row: "<<row<<", colum:"<<column<<endl;
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < column; j++) {
            cout<< m[i][j];
            if( j != column -1)
                cout<<", ";
        }
        cout << endl;
    }
}

int minPathSum(vector<vector<int> > &m) {
    if (m.size() == 0 || m[0].size() == 0) {
        return 0;
    }
    int row = m.size();
    int col = m[0].size();
    vector<vector<int> > dp(row);
    for (int i = 0; i < row; i++) {
        dp[i].resize(col);
    }
    dp[0][0] = m[0][0];
    for (int i = 1;  i < row; i++) {
        dp[i][0] = dp[i - 1][0] + m[i][0];
    }
    for (int j = 1; j < col; j++) {
        dp[0][j] = dp[0][j - 1] + m[0][j];
    }
    for (int i = 1; i < row; i++){
        for (int j = 1; j < col; j++) {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + m[i][j];
        }
    }
    printMatrix(dp);
    return dp[row - 1][col - 1];
}

int minPathSum2Ex(vector<vector<int> >&m) {
    if (m.size() == 0 || m[0].size() == 0) {
         return 0;
    }
    int more = std::max(m.size(), m[0].size());
    int less = std::min(m.size(), m[0].size());

    bool row_more = more == m.size();
    vector<int> arr(less);
    arr[0] = m[0][0];
    for (int i = 1; i < less; i++) {
        arr[i] = arr[i - 1] + (row_more ? m[0][i] : m[i][0]);
    }
    for (int i = 1; i < more; i++) {
        arr[0] = arr[0] + (row_more ? m[i][0] : m[0][i]);
        for (int j = 1; j < less; j++) {
            arr[j] = std::min(arr[j-1], arr[j])
                + (row_more ? m[i][j] : m[i][j]);
        }
    }
    return arr[less - 1];
}

int main()
{
    vector<vector<int> > input; 
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(3);
    tmp.push_back(5);
    tmp.push_back(9);
    input.push_back(tmp);

    tmp[0] = 8;
    tmp[1] = 1;
    tmp[2] = 3;
    tmp[3] = 4;
    input.push_back(tmp);

    tmp[0] = 5;
    tmp[1] = 0;
    tmp[2] = 6;
    tmp[3] = 1;
    input.push_back(tmp);

    tmp[0] = 8;
    tmp[1] = 8;
    tmp[2] = 4;
    tmp[3] = 0;
    input.push_back(tmp);
    printMatrix(input);

    minPathSum(input);
    cout<<minPathSum2Ex(input)<<endl;
#if 0
    vector<vector<int> > res;
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(4);
    tmp.push_back(9);
    tmp.push_back(18);
    res.push_back(tmp);
    tmp[0] = 9;
    tmp[1] = 5;
    tmp[2] = 8;
    tmp[3] = 12;
    res.push_back(tmp);
    tmp[0] = 14;
    tmp[1] = 5;
    tmp[2] = 11;
    tmp[3] = 12;
    res.push_back(tmp);
    tmp[0] = 22;
    tmp[1] = 12;
    tmp[2] = 15;
    tmp[3] = 12;
    res.push_back(tmp);
    cout << minPathSum1(res) << endl;
    cout << minPathSum2(res) << endl;
#endif
}
