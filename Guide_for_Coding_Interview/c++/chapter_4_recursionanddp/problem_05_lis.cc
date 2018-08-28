#include <iostream>
#include <vector>
using namespace std;

vector<int> getdp1(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp;
}

vector<int> generateLIS(vector<int> arr, vector<int> dp) {
    int len = 0;
    int index = 0;
    for (int i = 0; i < dp.size(); i++) {
        if (dp[i] > len) {
            len = dp[i];
            index = i;
        }
    }
    vector<int> lis(len);
    lis[--len] = arr[index];
    for (int i = index; i >= 0; i--) {
        if (arr[i] < arr[index] && dp[i] == dp[index] - 1) {
            lis[--len] = arr[i];
            index = i;
        }
    }
    return lis;
}

vector<int> lis1(vector<int> arr) {
    vector<int> dp;
    if (arr.size() == 0) {
        return dp;
    }
    dp = getdp1(arr);
    return generateLIS(arr, dp);
}

vector<int> getdp2(vector<int> arr) {
    int n = arr.size();
    vector<int> dp(n);
    vector<int> ends(n);
    ends[0] = arr[0];
    dp[0] = 1;
    int right = 0;
    int l = 0;
    int r = 0;
    int m = 0;
    for(int i = 1; i < n; i++) {
        l = 0;
        r = right;
        while (l <= r) {
            m = (l + r) / 2;
            if (arr[i] > ends[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        right = std::max(right, l);
        ends[l] = arr[i];
        dp[i] = l + 1;
    }
    return dp;
}

vector<int> lis2(vector<int> arr) {
    vector<int> dp;
    if (arr.size() == 0) {
        return dp;
    }
    dp = getdp2(arr);
    return generateLIS(arr, dp);
}


void printVector(vector<int> arr) {
    for (int i = 0; i != arr.size(); i++) {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}

int main(int argc, char** argv) {
    int arr[] = { 2, 1, 5, 3, 6, 4, 8, 9, 7};
    vector<int> v_arr(arr, arr + sizeof(arr)/sizeof(int));
    printVector(v_arr);
    printVector(lis1(v_arr));
    printVector(lis2(v_arr));
}
