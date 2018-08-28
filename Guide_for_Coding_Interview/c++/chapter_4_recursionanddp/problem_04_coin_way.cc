#include <iostream>
#include <vector>
#include <sys/time.h>

using namespace std;

int process1(vector<int> arr, int index, int aim) {
    int res = 0;
    if (index == arr.size()) {
        res = aim == 0 ? 1 : 0;
    } else {
        for (int i = 0; arr[index] * i <= aim; i++) {
            res += process1(arr, index + 1, aim - arr[index] * i);
        }
    }
    return res;
}

int coins1(vector<int> arr, int aim) {
    if (arr.size() == 0 || aim < 0) {
        return 0; 
    }
    return process1(arr, 0, aim);
}

int process2(vector<int> arr, int index, int aim, vector<vector<int> > map) {
    int res = 0;
    if (index == arr.size()) {
        res = aim == 0 ? 1 : 0;
    } else {
        int mapValue = 0;
        for (int i = 0; arr[index] * i <= aim; i++) {
            mapValue = map[index + 1][aim - arr[index] * i];
            if (mapValue != 0) {
                res += mapValue == -1 ? 0 : mapValue;
            } else {
                res += process2(arr, index + 1, aim - arr[index] * i, map);
            }
        }
    }
    map[index][aim] = res == 0 ? -1 : res;
    return res;
}

int coins2(vector<int> arr, int aim) {
    if (arr.size() == 0 || aim < 0) {
        return 0;
    }
    int n = arr.size();
    vector<vector<int> > map(n + 1);
    for (int i = 0; i < n + 1; i++) {
        map[i].resize(aim + 1);
    }
    return process2(arr, 0, aim, map);
}

int coins3(vector<int> arr, int aim) {
    if (arr.size() == 0 || aim < 0) {
        return 0;
    }
    int n = arr.size();
    vector<vector<int> > dp(n);
    for (int i = 0; i < n; i++) {
        dp[i].resize(aim + 1);
    }
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    for (int j = 1; arr[0] * j <= aim; j++) {
        dp[0][arr[0] * j] = 1;
    }
    int num = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= aim; j++) {
            num = 0;
            for (int k = 0; j - arr[i] * k >= 0; k++) {
                num += dp[i - 1][j - arr[i] * k];
            }
            dp[i][j] = num;
        }
    }
    return dp[n - 1][aim];
}

int coins4(vector<int> arr, int aim) {
    if (arr.size() == 0 || aim < 0) {
        return 0;
    }
    int n = arr.size();
    vector<vector<int> > dp(n);
    for (int i = 0; i < n; i++) {
        dp[i].resize(aim + 1);
    }
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    for (int j = 1; arr[0] * j <= aim; j++) {
        dp[0][arr[0] * j] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= aim; j++) {
            dp[i][j] = dp[i-1][j];
            dp[i][j] += j - arr[i] >= 0 ? dp[i][j - arr[i]] : 0;
        }
    }
    return dp[n -1][aim];
}

int coins5(vector<int> arr, int aim) {
    if (arr.size() == 0 || aim < 0) {
        return 0;
    }
    int n = arr.size();
    vector<int> dp(aim + 1);
    for (int j = 0; arr[0] * j <= aim; j++) {
        dp[arr[0] * j] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= aim; j++) {
            dp[j] += j - arr[i] >= 0 ? dp[j - arr[i]] : 0;
        }
    }
    return dp[aim];
}

int64_t getCurrentTime() 
{
    struct timeval tv;
    gettimeofday(&tv,NULL); 
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}


int main(int argc, char** argv) {
    int coins[] = { 10, 5, 1, 25 };
    vector<int> arr(coins, coins + sizeof(coins)/sizeof(int));
    int aim = 2000;

    uint64_t start = 0;
    uint64_t end = 0;

    start = getCurrentTime();
    cout<<coins2(arr, aim)<<endl;
    end = getCurrentTime();
    cout<<"coins1 cost time : " << end - start << "(ms)" << endl;

    aim = 20000;

    start = getCurrentTime();
    //cout<<coins2(arr, aim)<<endl;
    end = getCurrentTime();
    cout<<"coins2 cost time : " << end - start << "(ms)" << endl;

    start = getCurrentTime();
    cout<<coins3(arr, aim)<<endl;
    end = getCurrentTime();
    cout<<"coins3 cost time : " << end - start << "(ms)" << endl;

    start = getCurrentTime();
    cout<<coins4(arr, aim)<<endl;
    end = getCurrentTime();
    cout<<"coins4 cost time : " << end - start << "(ms)" << endl;

    start = getCurrentTime();
    cout<<coins5(arr, aim)<<endl;
    end = getCurrentTime();
    cout<<"coins5 cost time : " << end - start << "(ms)" << endl;
}
