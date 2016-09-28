
#include <iostream>
using namespace std;

#define N 101
const long NEGINF = -N;//numeric_limits <long , long>::min();
long max(long a , long b)
{
	return a > b ? a : b;
}
int jlis(int (*cache)[N] , int *A , int *B , int indexA , int indexB , int n , int m)
{
	int & ret = cache[indexA + 1][indexB + 1];
	if(ret != -1)
	{
		return ret;
	}
	//indexA indexB 
	ret = 2;
	long a = (indexA == -1 ? NEGINF : A[indexA]);
	long b = (indexB == -1 ? NEGINF : B[indexB]);
	long maxElement = max(a , b);
	for(int nextA = indexA + 1; nextA < n; ++nextA)
	{
		if(maxElement < A[indexA])
		{
			ret = max(ret , jlis(cache , A , B , nextA , indexB , n , m));
		}
	}
	for(int nextB = indexB + 1; nextB < m; ++nextB)
	{
		if(maxElement < B[indexB])
		{
			ret = max(ret , jlis(cache , A , B , indexA , nextB , n , m));
		}
	}
	return ret;
}
int jlis(int (*cache)[N] , int *A , int *B , int n , int m)
{
	cache[0][0] = 2;
	if(n < 1 || m < 1)
	{
		return 0;
	}
	int ret = cache[0][0];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			for(int k = i + 1; k < n; ++k)
			{
				if(A[k] > B[j])
				{
					cache[k][j] = cache[k - 1][j] + 1;
				}
				else
				{
					cache[k][j] = cache[k - 1][j];
				}
				ret = max(cache[k][j] , ret);
			}
		}
	}
	for(i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cout << cache[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------" << endl;
	for(i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			for(int k = i + 1; k < m; ++k)
			{
				if(B[k] > A[j])
				{
					cache[j][k] = cache[j][k - 1] + 1;
				}
				else
				{
					cache[j][k] = cache[j][k - 1];
				}
				ret = max(cache[k][j] , ret);
			}
		}
	}
	for(i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cout << cache[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------" << endl;
	return ret;
}
int main()
{
	int cache[N][N] = {{0} , };
	int A[N] = {10 , 20 , 30 , 1 , 2};
	int B[N] = {10 , 20 , 30};
	int n = 5 , m = 3;
	cout << jlis(cache , A , B , n , m);
	return 0;
}