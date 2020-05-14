#include<iostream>
using namespace std;

long long fibonacciImproved(int n){
	if(n <= 0) {
		return -1;
	}
		
	long long A[n];
	A[0] = 0;
	A[1] = 1;
	for(long long i = 2 ; i <= n; i++){
		A[i] = A[i-1] + A[i-2];
	}
	return A[n];
}

int main(){
	int n;
	cout << "\nEnter n : ";
	cin >> n;
	cout << "\nResult is : " << fibonacciImproved(n);
	return 0;
}
