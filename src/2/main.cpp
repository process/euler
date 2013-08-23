#include <iostream>
using namespace std;

int main() {
	int temp = 1;
	int curr = 1;
	int prev = 0;

	int total = 0;

	for(curr = 1; curr < 4000000; ) {
		if (curr % 2 == 0) {
			total += curr;
		}

		// cout << curr << endl;
		temp = curr;
		curr += prev;
		prev = temp;
	}

	cout << "The total is: " << total << endl;

	return 0;
}
