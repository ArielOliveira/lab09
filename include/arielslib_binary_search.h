#ifndef ARIELSLIB_BINARY_SEARCH_H
#define ARIELSLIB_BINARY_SEARCH_H

template <typename T>
bool binarySearch(T *v, int n, T x) {
	if (n == 0) return false;
	int k = n/2;
	if (v[k] == x) return true;
	if (v[k] > x) return binarySearch(v, k, x);
	else return binarySearch(v+k+1, n-k-1, x);
}

#endif