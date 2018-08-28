#include <iostream>

using namespace std;
/*
 * fabonacci的递归实现
 */
static int f(int N) {
    if (N < 1) {
        return 0;
    }

    if (N == 1 || N==2) {
        return 1;
    }

    return f(N-1) + f(N-2);
}

/*
 * fabonacci的非递归实现
 */
static int f2(int n) {
    if (n < 1) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    int cur = 1;
    int pre = 1;
    int tmp = 0;
    for (int i = 3; i <= n; i++) {
        tmp = cur;
        cur = cur + pre;
        pre = tmp;
    }
    return cur;
}

class Matrix {
public:
	unsigned int a11, a12, a21, a22;
	Matrix(int a, int b, int c, int d) :a11(a), a12(b), a21(c), a22(d){}
	//重载矩阵的乘法
	Matrix operator*(const Matrix &other)
	{
		Matrix r(0,0,0,0);
		r.a11 = a11*other.a11 + a12*other.a21;
		r.a12 = a11*other.a12 + a12*other.a22;
		r.a21 = a21*other.a11 + a22*other.a21;
		r.a22 = a21*other.a12 + a22*other.a22;
		return r;
	}
};
 
//计算矩阵A的m次方
Matrix MatrixPow(const Matrix &A, unsigned int m)
{
	Matrix res(1, 0, 0, 1);//单位矩阵
	Matrix cur = A;
	while (m)
	{
		if (m & 1)
			res = res*cur;
		cur = cur*cur;
		m = m >> 1;
	}
	return res;
}

Matrix MatrixPowEx(const Matrix &A, unsigned int m) {
    Matrix res(1, 0, 0, 1);// 单位矩阵
    Matrix cur = A;
    for (; m; m >>= 1){
        if (m & 1) {
            res = res*cur;
        }
        cur = cur * cur;
    }
    return res;
}
 
unsigned int f3(int n) {
	if (n < 1)
        return 0;
	if (n == 1 || n == 2)
		return 1;
	Matrix A(1, 1, 1, 0);
	Matrix r = MatrixPow(A, n - 2);
	return f3(2)*r.a11 + f3(1)*r.a12;
}

static int s1(int n) {
    if (n < 1) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return n;
    }
    return s1(n -1) + s1(n - 2);
}

static int s2(int n) {
    if (n < 1) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return n;
    }
    int res = 2;
    int pre = 1;
    int tmp = 0;
    for (int i = 3; i <= n; i++) {
        tmp = res;
        res = res + pre;
        pre = tmp;
    }
    return res;
}

static int s3(int n) {
    if (n < 1) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return n;
    }
    Matrix A(1, 1, 1, 0);
    Matrix r = MatrixPow(A, n - 2);
    return s3(2)*r.a11 + s3(1)*r.a12;
}

static int c1(int n) {
    if (n < 1) {
        return 0;
    }
    if ( n == 1 || n == 2 || n == 3) {
        return n;
    }
    return c1(n-1) + c1(n - 3);
}

static int c2(int n) {
    if (n < 1) {
        return 0;
    }
    if ( n == 1 || n == 2 || n == 3) {
        return n;
    }
    int res = 3;
    int pre = 2;
    int prepre = 1;
    int tmp1 = 0;
    int tmp2 = 0;
    for (int i = 4; i <= n; i++) {
        tmp1 = res;
        tmp2 = pre;
        res = res + prepre;
        pre = tmp1;
        prepre = tmp2;
    }
    return res;
}

int main(int argc, char* argv[]){
    int N = 11;
    for(int i = 1 ; i <= N; i++) {
        cout<<c2(i);
        if(i!=N)
            cout<<", ";
    }
    cout<<endl;
    //cout<<f(0)<<endl;
    return 0;
}
