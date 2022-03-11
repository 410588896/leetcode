#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &arr, int l, int r) {
    if (l > r) return;
	int tmp = arr[l];
	int i = l, j = r;
	while (i != j) {
        while (arr[j] >= tmp && j > i) {
            j --;
		}
		while (arr[i] <= tmp && i < j) {
			i ++;
		}
		swap(arr[i], arr[j]);
	}
	arr[l] = arr[i];
    arr[i] = tmp;
	quickSort(arr, l, i - 1);
	quickSort(arr, i + 1, r);
}

int main() {
    vector<int> arrs{4,2,6,7,1,8,3,5,9};
    quickSort(arrs, 0, arrs.size() - 1);
	for (auto & arr : arrs) {
	    cout << arr << endl;
	}
	return 0;
}
