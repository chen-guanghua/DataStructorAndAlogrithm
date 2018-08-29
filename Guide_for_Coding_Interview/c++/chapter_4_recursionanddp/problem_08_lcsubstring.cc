#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int> > getdp(vector<char> str1, vector<char> str2) {
    int m = str1.size();
    int n = str2.size();
    vector<vector<int> > dp(str1.size());
    for(int i = 0; i < str1.size(); i++) {
        dp[i].resize(str2.size());
    }

    for (int i = 0; i < m; i++) {
        if (str1[i] == str2[0]) {
            dp[i][0] = 1;
        }
    }
    for (int j = 0; j < n; j++) {
        if (str1[0] == str2[j]) {
            dp[0][j] = 1;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j= 1; j < n; j++) {
            if(str1[i] == str2[j]) {
                dp[i][j] = dp[i - 1][j - 1]  + 1;
            }
        }
    }
    return dp;
}

string lcst1(string str1, string str2) {
    if (str1.empty() || str2.empty()) {
        return "";
    }
    int m = str1.length();
    vector<char> v_str1;
    for(int i = 0; i < m; i++) {
        v_str1.push_back(str1[i]);
    }
    int n = str2.length();
    vector<char> v_str2;
    for(int j = 0; j < n; j++) {
        v_str2.push_back(str2[j]);
    }

    int end = 0;
    int max = 0;

    vector<vector<int> > dp = getdp(v_str1, v_str2); 
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            if (dp[i][j] > max) {
                end = i;
                max= dp[i][j];
            }
        }
    }
    return str1.substr(end - max + 1, max);
}

string lcst2(string str1, string str2) {
    if (str1.empty() || str2.empty()) {
        return "";
    }

    int m = str1.length();
    vector<char> v_str1;
    for(int i = 0; i < m; i++) {
        v_str1.push_back(str1[i]);
    }
    int n = str2.length();
    vector<char> v_str2;
    for(int j = 0; j < n; j++) {
        v_str2.push_back(str2[j]);
    }
    int row = 0;
    int col = n - 1;
    int max = 0;
    int end = 0;

    while (row < m) {
        int i = row;
        int j = col;
        int len = 0;
        while (i < m && j < n) {
            if (v_str1[i] != v_str2[j]) {
                len = 0;
            } else {
                len++;
            }
            if (len > max) {
                end = i;
                max = len;
            }
            i++;
            j++;
        }
        if (col > 0) {
            col--;
        } else {
            row++;
        }
    }
    return str1.substr(end - max + 1,  max);
}

int main(int argc, char** argv) {
    string str1 = "ABC1234567DEFG";
    string str2 = "HIJKL1234567MNOP";
    cout<<lcst1(str1,str2)<<endl;
    cout<<lcst2(str1,str2)<<endl;

    return 0;
}
