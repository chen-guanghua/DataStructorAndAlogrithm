/*
 * 题目：
 * 给定一个非负整数N，返回N！结果的末尾为0的数量。
 *      例如：3! = 6，结果的末尾没有0，所以返回0。5! = 120，结果的末尾有1个0，返回1。1000000000!，结果的末尾有249999999998个0，返回2499999998。
 * 【进阶题目】
 *　给定一个非负整数N，如果用二进制数表达N!的结果，返回最低位的1在哪个位置上，认为最右边的位置为位置0.
 *      例如：1! = 1，最低位的1在位置0上。2! = 2，最低位的1在1位置上。1000000000!，最低位的1在999999987位置上。
 */


#include <iostream>
using namespace std;

int zero_num1(int num) {
    if (num < 0) {
        return 0;
    }
    int res = 0;
    int cur = 0;
    for (int i = 5; i < num + 1; i = i + 5) {
        cur = i;
        while (cur % 5 == 0) {
            res++;
            cur /= 5;
        }
    }
    return res;
}

int zero_num2(int num) {
    if (num < 0) {
        return 0;
    }
    int res = 0;
    while (num != 0) {
        res += num / 5;
        num /= 5;
    }
    return res;
}

int rightOne1(int num) {
    if (num < 1) {
        return -1;
    }
    int res = 0;
    while (num != 0) {
        num >>= 1;
        res += num;
    }
    return res;
}

int rightOne2(int num) {
    if (num < 1) {
        return -1;
    }

    int ones = 0;
    int tmp = num;
    while (tmp != 0) {
        ones += (tmp & 1) != 0 ? 1 : 0;
        tmp >>= 1;
    }
    return num - ones;
}

int main(int argc, char* argv[]) {
    int num = 1000000000;

    cout<<"method1: ";
    cout<<zero_num1(num)<<endl;

    cout<<"method2: ";
    cout<<zero_num2(num)<<endl;
   
    return 0;
}
