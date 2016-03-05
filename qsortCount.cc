#include <iostream>
#include <ctime>
#include <cstdlib>

int * x;
int comps;

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

float c(int n) {
	if (n <= 1) return 0;
	float sum = 0.0;
	for (int m=1; m <= n; m++)
		sum += n-1 + c(m-1) + c(n-m);
	return sum / n;
}

int qc (int n){
	if(n<=1) return comps;
	int pi = randint(0,n-1);
	comps +=n-1;
	qc(n-pi-1);
	qc(pi);
	return comps;
}

void quicksort(int a, int b) {
	if (a >= b) return;
	int p = randint(a,b); // pivot
	swap(x[a], x[p]);
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
		comps++;
		if (x[i] < x[a])
			swap(x[++m], x[i]);
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

#define NN 1000

int main(int argc, char *argv[]) {
	srand(time(0));
	int sum=0;
	// change the following code
	x = new int[NN];
	for(int j=0;j<100;j++) {
		for (int i = 0; i < NN; ++i) {
			x[i] = rand() % NN;
		}
		quicksort(0, NN - 1);
		sum+=comps;
		comps=0;
//	for (int i=0; i<NN; ++i) {
//		std::cout << x[i] << " ";
//	}
	}
	std::cout << sum/100;
	std::cout << std::endl;

	delete[] x;
	return 0;
}

