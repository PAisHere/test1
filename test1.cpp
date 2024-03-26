#include<iostream>
#include<time.h>
using namespace std;
int main() {
	clock_t start, finish;
	int n = 1000, step = 10;
	int sum[1000] = { 0 };
	int a[1000] = { 0 };
	int **b=new int*[1000];
	for (int i = 0; i < 1000; i++) {
		b[i] = new int[1000];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = 0;
		}
	}
	int cnt = 0;
	float seconds;
	for (int i = 0; i < n; i++) {
		a[i] = i;
		for (int j = 0; j < n; j++) {
			b[i][j] = i;
		}
	}
	for (n = 10; n < 5000; n += step) {
		start = clock();
		cnt = 0;
		while (clock() - start < 10) {
			cnt++;
			for (int i = 0; i < n; i++) {
				sum[i] = 0;
				for (int j = 0; j < n; j++)
					sum[i] += b[j][i] * a[j];
			}
		}
		finish = clock();
		seconds = (finish - start) / float(CLOCKS_PER_SEC);
		cout << n << " " << cnt << " " << seconds << " " << seconds / cnt << endl;
		if (n == 100)step = 100;
		if (n == 1000)step = 500;
	}
	for (int i = 0; i < 1000; i++) {
		delete[]b[i];
	}
	delete[]b;
	return 0;
}