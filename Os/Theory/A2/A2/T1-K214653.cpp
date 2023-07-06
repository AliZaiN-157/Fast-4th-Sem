#include <iostream>
#include <thread>
#include <vector>

using namespace std;

# define N 8 // 21k4653 5+3 = 8

// Matrix A
int A[N][N] = { {1, 1, 1, 1, 1, 1, 1, 1},
				{2, 2, 2, 2, 2, 2, 2, 2},
				{3, 3, 3, 3, 3, 3, 3, 3},
				{4, 4, 4, 4, 4, 4, 4, 4},
				{5, 5, 5, 5, 5, 5, 5, 5},
				{6, 6, 6, 6, 6, 6, 6, 6},
				{7, 7, 7, 7, 7, 7, 7, 7},
				{8, 8, 8, 8, 8, 8, 8, 8} };

	


// Matrix B
int B[N][N] = { {1, 1, 1, 1, 1, 1, 1, 1},
				{2, 2, 2, 2, 2, 2, 2, 2},
				{3, 3, 3, 3, 3, 3, 3, 3},
				{4, 4, 4, 4, 4, 4, 4, 4},
				{5, 5, 5, 5, 5, 5, 5, 5},
				{6, 6, 6, 6, 6, 6, 6, 6},
				{7, 7, 7, 7, 7, 7, 7, 7},
				{8, 8, 8, 8, 8, 8, 8, 8} };

// Matrix C
int C[N][N];

void multiply(int row)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
				C[i][row] += A[j][row] * B[i][j];
}

int main()
{	
	vector<thread> threads;

	for (int i = 0; i < N; i++)
		threads.push_back(thread(multiply, i));

	for (int i = 0; i < N; i++)
		threads[i].join();

	cout << "Result matrix is " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << C[i][j] << " ";
		cout << endl;
	}

	return 0;
}