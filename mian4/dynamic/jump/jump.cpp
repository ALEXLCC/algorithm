
#include <iostream>
using namespace std;


int n = 7;
int board[100][100] = 
{
	{2 , 5 , 1 , 6 , 1 , 4 , 1},
	{6 , 1 , 1 , 2 , 2 , 9 , 3},
	{7 , 2 , 3 , 2 , 1 , 3 , 1},
	{1 , 1 , 3 , 1 , 7 , 1 , 2},
	{4 , 1 , 2 , 3 , 4 , 1 , 2},
	{3 , 3 , 1 , 2 , 3 , 4 , 1},
	{1 , 5 , 2 , 9 , 4 , 7 , 0}
};

bool jump(int x , int y)
{
	if(y >= n || x >= n)
	{
		return false;
	}
	if(y == n - 1 && x == n - 1)
	{
		return true;
	}
	int jumpSize = board[y][x];
	return jump(y + jumpSize , x) || jump(y , x + jumpSize);
}

int main()
{
	cout << (jump(0 , 0) == 1 ? "true" : "false") << endl;
	return 0;
}