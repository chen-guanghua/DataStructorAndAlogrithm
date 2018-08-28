#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int minCoins1(vector<int> arr, int aim) {
    if(arr.size() == 0 || aim < 0) {
        return -1;
    }

    int n = arr.size();
    int max = numeric_limits<int>::max();
    vector<vector<int> > dp(n);
    for (int i = 0; i < n; i++) {
        dp[i].resize(aim + 1);
    }
    for (int j = 1; j <= aim; j++) {
        dp[0][j] = max;
        if (j - arr[0] >= 0 && dp[0][j - arr[0]] != max) {
            dp[0][j] = dp[0][j - arr[0]] + 1;
        }
    }
    int left = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= aim; j++) {
            left = max;
            if (j - arr[i] >= 0 && dp[i][j - arr[i]] != max) {
                left = dp[i][j - arr[i]] + 1;
            }
            dp[i][j] = std::min(left, dp[i - 1][j]);
        }
    }
    return dp[n - 1][aim] != max ? dp[n-1][aim] : -1;
}

int minCoins2(vector<int> arr, int aim) {
    if(arr.size() == 0 || aim < 0) {
        return -1;
    }

    int n = arr.size();
    int max = numeric_limits<int>::max();
    vector<int> dp(aim + 1);
    for (int j = 1; j <= aim; j++) {
        dp[j] = max;
        if (j - arr[0] >= 0 && dp[j - arr[0]] != max) {
            dp[j] = dp[j - arr[0]] + 1;
        }
    }
    int left = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= aim; j++) {
            left = max;
            if (j - arr[i] >= 0 && dp[j - arr[i]] != max) {
                left = dp[j - arr[i]] + 1;
            }
            dp[j] = std::min(left, dp[j]);
        }
    }
    return dp[aim] != max ? dp[aim] : -1;
}

int minCoins3(vector<int> arr, int aim) {
    if(arr.size() == 0 || aim < 0) {
        return -1;
    }
    int n = arr.size();
    int max = numeric_limits<int>::max();
    vector<vector<int> > dp(n);
    for (int i = 0; i < n; i++){
        dp[i].resize(aim + 1);
    }
    for (int j = 1; j <= aim; j++) {
        dp[0][j] = max;
    }
    if (arr[0] <= aim) {
        dp[0][arr[0]] = 1;
    }
    int leftup = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= aim; j++) {
            leftup = max;
            if (j - arr[i] >= 0 && dp[i - 1][j - arr[i]] != max) {
                leftup = dp[i - 1][j - arr[i]] + 1;
            }
            dp[i][j] = std::min(leftup, dp[i - 1][j]);
        }
    }
    return dp[n - 1][aim] != max ? dp[n - 1][aim] : -1;
}

int minCoins4(vector<int> arr, int aim) {
    if(arr.size() == 0 || aim < 0) {
        return -1;
    }
    int n = arr.size();
    int max = numeric_limits<int>::max();
    vector<int> dp(aim + 1);
    for (int j = 1; j <= aim; j++) {
        dp[j] = max;
    }
    if (arr[0] <= aim) {
        dp[arr[0]] = 1;
    }
    int leftup = 0;
    for (int i = 1; i < n; i++) {
        for (int j = aim; j > 0; j--) {
            leftup = max;
            if (j - arr[i] >= 0 && dp[j - arr[i]] != max) {
                leftup = dp[j - arr[i]] + 1;
            }
            dp[j] = std::min(leftup, dp[j]);
        }
    }
    return dp[aim] != max ? dp[aim] : -1;
}

int main(int argc, char* argv[] ) {
    int arr[] = { 100, 20, 5, 10, 2, 50, 1 };
    vector<int> v_arr(arr, arr + sizeof(arr)/sizeof(int));
    int aim = 17019;
    cout<<minCoins1(v_arr, aim)<<endl;
    cout<<minCoins2(v_arr, aim)<<endl;

    int arr2[] = { 10, 100, 2, 5, 5, 5, 10, 1, 1, 1, 2, 100 };
    vector<int> v_arr2(arr2, arr2 + sizeof(arr2)/sizeof(int));
    int aim2 = 223;
    cout<<minCoins3(v_arr2, aim2)<<endl;
    cout<<minCoins4(v_arr2, aim2)<<endl;

    int arr3[] = {5, 2, 3};
    vector<int> v_arr3(arr3, arr3 + sizeof(arr3)/sizeof(int));
    int aim3 = 20;
    cout<<minCoins4(v_arr3, aim3)<<endl;

    int arr4[] = { 5, 2, 5, 3};
    int aim4 = 10;
    int aim5 = 15;
    int aim6 = 0;
    vector<int> v_arr4(arr4, arr4 + sizeof(arr4)/sizeof(int));
    cout<<minCoins4(v_arr4, aim4)<<endl;
    cout<<minCoins4(v_arr4, aim5)<<endl;
    cout<<minCoins4(v_arr4, aim6)<<endl;

    return 0;
}
