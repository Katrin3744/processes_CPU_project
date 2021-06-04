#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum_v(vector <vector<int>> j, int m, int k) {
	int sum_wj = INT_MAX;
	int idx = 0;

	for (int q = k; q < m; q++) {
		int sum_j = 0;
		for (int i = 0; i < j[q].size(); i++) {
			sum_j = j[q][i] + sum_j;
		}
		if (sum_wj > sum_j)
		{
			sum_wj = sum_j;
			idx = q;
		}
	}
	return idx;
}

void time_for_work(vector <int> &t, int m) {
	vector <vector<int>> j(m);
	sort(t.begin(), t.end(), greater<int>());
	
	int idx = -1;
	while ( t.size()!=0) {
		if (idx != -1) {

			cout << idx << endl;
			for (int i = idx; i < m && t.size()!=0; i++) {
				j[i].push_back(t[0]);
				int h = sum_v(j, m, idx);
				if (t.size() != 0 ) {
					t.erase(t.begin());
				}
				else
					break;
				if (h != idx)
					break;

			}
		}
		else {
			for (int i = 0; i < m && t.size() != 0; i++) {
				j[i].push_back(t[0]);
				if (t.size() != 0) {
					t.erase(t.begin());
				}
				else
					break;

			}
		}
		idx = sum_v(j, m,0);
		for (int i = idx; i < m &&t.size()!=0; i++) {
			j[i].push_back(t[0]);
			int h = sum_v(j, m, idx);
			if (t.size() != 0 ) {
				t.erase(t.begin());
			}
			else
				break;
			if (h != idx)
				break;
		}
		idx = sum_v(j, m,0);
		
	}
	for (int q = 0; q < m; q++) {
		for (int i = 0; i < j[q].size(); i++) {
			cout << j[q][i] << "  ";
		}
		cout << endl;

	}

}

int main() {
	int n,m;
	cout << "The number of processes" << endl;
	cin >> n;
	cout << "The number of CPU" << endl;
	cin >> m;

	vector <int> t;
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		cin >> a;
		t.push_back(a);
	}
	time_for_work(t, m);


	return 0;
}