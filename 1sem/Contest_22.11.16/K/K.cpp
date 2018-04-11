#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	long long imax = 0;
	long long num = 0;
    long long *a = new long long [n];
	for (int i = 0; i < n; ++i){
        cin >> a[i];
	}
	for (int i = k; i < n; ++i){
		imax = max(imax, a[i - k]);
		num = max(num, a[i] + imax);
	}
	cout << num;
	delete[]a;
	return 0;
}
