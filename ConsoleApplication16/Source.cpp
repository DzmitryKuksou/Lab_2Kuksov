#include <iostream>
using namespace std;
double** AllocMemory(int);
double Sin(double, double);
double Formula1(int, int, double, double);
double Formula2(int, int);
double MaxDifference(double**, double**, int);
int EnterDimention(int);
void CreatMatrix1(double**, int, double);
void CreatMatrix2(double**, int);
int main()
{
	int n = 900;
	double eps;
	cout << "Enter the size of matrix:\n";
	n = EnterDimention(n);
	cout << "Enter Epsilon:\n";
	cin >> eps;
	double** matrix1 = AllocMemory(n);
	CreatMatrix1(matrix1, n, eps);
	double** matrix2 = AllocMemory(n);
	CreatMatrix2(matrix2, n);
	cout << "MaxDifference:\n";
	cout << MaxDifference(matrix1, matrix2, n);
	system("pause");
	return 0;
}
int EnterDimention(int n)
{
	int k;
	while (true)
	{
		cin >> k;
		if (k > 0 && k <= n)
			return k;
		cout << "0<k<900" << endl;
	}
}
double MaxDifference(double** matrix1, double** matrix2, int n)
{
	double max = fabs(matrix1[0][0] - matrix2[0][0]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (max < fabs(matrix1[i][j] - matrix2[i][j]))
			{
				max = fabs(matrix1[i][j] - matrix2[i][j]);
			}
		}
	return max;
}
double Formula2(int i, int j)
{
	double a;
	if (i == j)a = 1;
	else
	{
		a = (sin(i + j) - sin(i - j)) / ((i + j + 1)*(i + j + 1));
	}
	return a;
}

double Formula1(int i, int j, double eps)
{
	double a;
	if (i == j)a = 1;
	else
	{
		a = (Sin(i + j, eps) - Sin(i - j, eps)) / pow((i + j + 1), 2);
	}
	return a;
}
double Sin(double x, double eps)
{
	double sum = 0;
	int k = 1;
	int l = 1;
	double s = 1;
	for (int n = 1; eps < s;)
	{
		sum += k*x / l;
		s = x / l;
		n += 2;
		l *= n*(n - 1);
		k = -k;
	}


	return sum;
}
void CreatMatrix1(double** matrix, int n, double eps)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = Formula1(i + 1, j + 1, eps);
}
void CreatMatrix2(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = Formula2(i + 1, j + 1);
}
double** AllocMemory(int n)
{
	double** matrix = new double*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[n];
	return matrix;
}


