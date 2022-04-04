#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

int main() {
	auto start = clock();
	vector<int> v(10000000, 0);
	for (int i = 0; i < v.size(); i++) {
		
	}

	auto end = clock();
	double dualtime = ((double)end - start) / CLOCKS_PER_SEC;

	cout << "dualtime is " << dualtime * 1000 << " ms " << endl;

	system("pause");
	return 0;
}
