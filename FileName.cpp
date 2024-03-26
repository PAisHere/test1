#include<iostream>
#include<time.h>
#include<cstring>
#include<math.h>
using namespace std;
void func1(int n, int* a) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
}

void func2(int n, int* a) {
	int sum1 = 0, sum2 = 0, sum = 0;
	for (int i = 0; i < n; i += 2) {
		sum1 += a[i];
		sum2 += a[i + 1];
	}
	sum = sum1 + sum2;
}
void func3(int n, int* a) {
	if (n == 1) return;
	else {
		for (int i = 0; i < n / 2; i++)
			a[i] += a[n - i - 1];
		n = n / 2;
		func3(n,a);
	}
}
void func4(int n, int* a) {
	for (int m = n; m > 1; m /= 2)
		for (int i = 0; i < m / 2; i++)
			a[i] = a[i * 2] + a[i * 2 + 1];
}

int main() {
	clock_t start, finish;
	int n = pow(2,28);
	int* a = new int[n+1];
	memset(a, 0, sizeof(a));
	int cnt = 0;
	float seconds;
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	for (int b = pow(2, 20); b <= n; b *= 2) {
		start = clock();
		cnt = 0;
		while (clock() - start < 10) {
			cnt++;
			func1(b, a);
		}
		finish = clock();
		seconds = (finish - start) / float(CLOCKS_PER_SEC);
		cout << b << " " << cnt << " " << seconds << " " << seconds / cnt << endl;
	}
	cout << endl;
	for (int b = pow(2, 13); b <= n; b *= 2) {
		start = clock();
		cnt = 0;
		while (clock() - start < 10) {
			cnt++;
			func2(b, a);
		}
		finish = clock();
		seconds = (finish - start) / float(CLOCKS_PER_SEC);
		cout << b << " " << cnt << " " << seconds << " " << seconds / cnt << endl;
	}
	cout << endl;
	for (int b = pow(2, 13); b <= n; b *= 2) {
		start = clock();
		cnt = 0;
		while (clock() - start < 10) {
			cnt++;
			func3(b,a);
		}
		finish = clock();
		seconds = (finish - start) / float(CLOCKS_PER_SEC);
		cout << b << " " << cnt << " " << seconds << " " << seconds / cnt << endl;
	}
	cout << endl;
	for (int b = pow(2, 13); b <= n; b *= 2) {
		start = clock();
		cnt = 0;
		while (clock() - start < 10) {
			cnt++;
			func4(b,a);
		}
		finish = clock();
		seconds = (finish - start) / float(CLOCKS_PER_SEC);
		cout << b << " " << cnt << " " << seconds << " " << seconds / cnt << endl;
	}
	delete[]a;
	return 0;
}

