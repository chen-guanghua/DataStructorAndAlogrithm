#include <iostream>
#include <string>
#include <vector>
using namespace std;

void func(int n, string from, string mid, string to){
    if (n == 1) {
        cout<<"move from "<<from<<" to "<<to<<endl;
    } else {
        func(n - 1, from, to, mid);
        func(1, from, mid, to);
        func(n - 1, mid, from, to);
    }
}

void hanoi(int n) {
    if (n > 0) {
        func(n, string("left"), string("mid"), string("right"));
    }
}

int process(vector<int> arr, int i, int from, int mid, int to) {
    if (i == -1) {
        return 0;
    }
    if (arr[i] != from && arr[i] != to) {
        return -1;
    }
    if (arr[i] == from) {
        return process(arr, i - 1, from, to, mid);
    } else {
        int rest = process(arr, i - 1, mid, from, to);
        if (rest == -1) {
            return -1;
        }
        return (1<<i) + rest;
    }
}

int step1(vector<int> arr) {
    if (arr.size() == 0) {
        return -1;
    }
    return process(arr, arr.size() - 1, 1, 2, 3);
}

int step2(vector<int> arr) {
    if (arr.size() == 0) {
        return -1;
    }
    int from = 1;
    int mid = 2;
    int to = 3;
    int i = arr.size() - 1;
    int res = 0;
    int tmp = 0;
    while (i >= 0) {
        if (arr[i] != from && arr[i] != to) {
            return -1;
        }
        if (arr[i] == to) {
            res += 1<<i;
            tmp = from;
            from = mid;
        } else {
            tmp = to;
            to = mid;
        }
        mid = tmp;
        i--;
    }
    return res;
}

int main(int argc, char** argv) {
    int n = 4;
    hanoi(n);

    int arr[] = { 3, 3, 2, 1};
    vector<int> v_arr(arr, arr + sizeof(arr)/sizeof(int));
    cout<<step1(v_arr)<<endl;
    cout<<step2(v_arr)<<endl;
}
