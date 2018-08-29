#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> >getdp(vector<char> str1, vector<char> str2) {
    vector<vector<int> >dp;
    int m = str1.size();
    int n = str2.size();
    if (m == 0 || n == 0) {
        return dp;
    }
    dp.resize(m);
    for (int i = 0; i < m; i++) {
        dp[i].resize(n);
    }

    dp[0][0] = str1[0] == str2[0] ? 1 : 0;
    for (int i = 1; i < m; i++) {
        dp[i][0] = std::max(dp[i-1][0], str1[i] == str2[0] ? 1 : 0);
    }
    for (int j = 1; j < n; j++) {
        dp[0][j] = std::max(dp[0][j-1], str1[0] == str2[j] ? 1 : 0);
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            if (str1[i] == str2[j]) {
                dp[i][j] = std::max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    return dp;
}

string lcse(string str1, string str2) {
    if (str1.empty() || str2.empty()) {
        return "";
    }

    vector<char> v_str1;
    for(int i = 0; i < str1.length(); i++) {
        v_str1.push_back(str1[i]);
    }
    vector<char> v_str2;
    for(int i = 0; i < str2.length(); i++) {
        v_str2.push_back(str2[i]);
    }

    vector<vector<int> > dp = getdp(v_str1, v_str2);
    if (dp.size() == 0) {
        return "";
    }

    /*
    cout<<"dp, m="<<dp.size()<<", n="<<dp[0].size()<<endl;;
    for(int i = 0; i < dp.size(); i++) {
        for(int j = 0; j < dp[i].size(); j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    int m = v_str1.size() - 1;
    int n = v_str2.size() - 1;

    //cout<<dp[m][n]<<endl;

    vector<char> res(dp[m][n]);
    int index = res.size() - 1;
    while (index >= 0) {
        if (n > 0 && dp[m][n] == dp[m][n - 1]) {
            n--;
        } else if (m > 0 && dp[m][n] == dp[m - 1][n]) {
            m--;
        } else {
            res[index--] = v_str1[m];
            m--;
            n--;
        }
    }
    return string(res.begin(), res.end());

}

int main(int argc, char** argv) {
    string str1 = "1AB2345CD";
    string str2 = "12345EF";
    cout<<"str1: "<<str1<<endl;
    cout<<"str2: "<<str2<<endl;
    cout<<lcse(str1, str2)<<endl;;
    return 0;
}
