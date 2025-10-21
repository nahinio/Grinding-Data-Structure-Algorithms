/*
 Recursive sort of a stack using only the call stack (no extra data structures).
 This program implements two functions:
 - insertSorted: inserts an element into a sorted stack so that the stack remains sorted
 - sortStack: recursively sorts the stack

 Example usage in main prints the stack from top to bottom after sorting.
*/

#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int> &st, int value) {
	if (st.empty() || st.top() <= value) {
		st.push(value);
		return;
	}

	int topVal = st.top();
	st.pop();
	insertSorted(st, value);
	st.push(topVal);
}

void sortStack(stack<int> &st) {
	if (st.empty()) return;

	int topVal = st.top();
	st.pop();
	sortStack(st);
	insertSorted(st, topVal);
}

int main() {
	stack<int> s;
	s.push(34);
	s.push(3);
	s.push(31);
	s.push(98);
	s.push(92);
	s.push(23);

	sortStack(s);

	cout << "Sorted stack (Top to Bottom): ";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << '\n';
	return 0;
}
