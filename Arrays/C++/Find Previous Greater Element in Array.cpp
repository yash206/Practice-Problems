#include <bits/stdc++.h>
using namespace std;

// Find Previous Greater Element of each element in the given Array.

vector<int> PGE(vector<int> &v) {
	int n = v.size();
    vector<int> pge(n, -1);
	stack<int> st;
	for(int i = v.size() - 1; i >= 0; --i) {
		while(!st.empty() && v[i] > v[st.top()]) {
			pge[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	return pge;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<int> pge = PGE(v);
	for(int i = 0; i < n; ++i) {
		cout << v[i] << " " << pge[i] << endl;
	}
}

/*

Input:
5
3 1 8 0 5

Output:
3 -1
1 0
8 -1
0 2
5 2

*/
