/*
	File tencent_40g.c
	Date:2015/3/30
	Function :
	1-40
	1 3 9 27
	1 2 4 5 13 14 40  41 121
	1  3    9    27		81
	正负号表示砝码所在的托盘,两者正好相反。0表示不用该砝码。
*/

#include<stdio.h>
int naFlag[5] = {0 , };/* 1 3 9 27 81   0 unused*/
int naWeight[5] = {1 , 3 , 9 , 27 , 81};	//砝码重量数组
int naLow[5] = {0 , 2 , 5 , 14 , 41};		//对应最低重量
int count = 5;	//砝码个数
void solve(int n)
{
	int i , k;
	if(n > 0)
	{
		for(i = count - 1; i >= 0; --i)
		{
			if(n >= naLow[i])
			{
				break;
			}
		}
		k = naWeight[i];
		naFlag[i] = 1;
		solve(n - k);
	}
	else if(0 == n)
	{
		
	}
	else 
	{
		n = -n;
		for(i = count - 1; i >= 0; --i)
		{
			if(n >= naLow[i])
			{
				break;
			}
		}
		k = naWeight[i];
		naFlag[i] = 1;
		solve(n - k);
		for(k = i; k >= 0; --k)
		{
			naFlag[k] *= -1;
		}
	}
}
int main()
{
	int nWeight , i ;
//	while(scanf("%d" , &nWeight) , nWeight)
	for(nWeight = 1; nWeight < 122; ++nWeight)
	{
		for(i = count - 1; i >= 0; --i)
		{
			if(nWeight >= naLow[i] && nWeight < (naWeight[i] + naLow[i]))
			{
				naFlag[i] = 1;
				solve(nWeight - naWeight[i]);
				break;
			}			
		}
		if(1 == nWeight)
		{
			naFlag[0] = 1;
			solve(0);
		}
		/*
			print result
		*/
		printf("nWeight = %d   " , nWeight);
		for(i = count - 1; i >= 0; --i)
		{
			if(1 == naFlag[i])
			{
				printf("%d " , naWeight[i--]);
				break;
			}
		}
		for(i ; i >= 0; --i)
		{
			if(1 == naFlag[i])
			{
				printf("+ %d " , naWeight[i]);
			}
			else if(-1 == naFlag[i])
			{
				printf("- %d " , naWeight[i]);
			}
			naFlag[i] = 0;
		}
		printf("\n");
	}
	return 0;
}