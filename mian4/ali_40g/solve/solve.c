/*
	File tencent_40g.c
	Date:2015/3/30
	Function :
	1-40
	1 3 9 27
	1 2 4 5 13 14 40
	1  3    9    27
*/

#include<stdio.h>
int naFlag[4] = {0 , };/* 1 3 9 27    0 unused*/
int naWeight[4] = {1 , 3 , 9 , 27};
int naLow[4] = {0 , 2 , 5 , 14};
void solve(int n)
{
	int i , k;
	if(n > 0)
	{
		for(i = 3; i >= 0; --i)
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
		for(i = 3; i >= 0; --i)
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
	for(nWeight = 1; nWeight < 41; ++nWeight)
	{
		if(nWeight <= 40 && nWeight >= 14)
		{
			naFlag[3] = 1;
			solve(nWeight - 27);
		}
		else if(nWeight <= 13 && nWeight >= 5)
		{
			naFlag[2] = 1;
			solve(nWeight - 9);
		}
		else if(nWeight <= 4 && nWeight >= 2)
		{
			naFlag[1] = 1;
			solve(nWeight - 3);
		}
		else 
		{
			naFlag[0] = 1;
			solve(0);
		}
		/*
			print result
		*/
/*		for(nWeight = 3; nWeight >= 0; --nWeight)
		{
			if(1 == naFlag[nWeight])
			{
				printf("+ %d " , naWeight[nWeight]);
			}
			else if(-1 == naFlag[nWeight])
			{
				printf("- %d " , naWeight[nWeight]);
			}
			naFlag[nWeight] = 0;
		}
		printf("\n");	*/
		printf("nWeight = %d   " , nWeight);
		for(i = 3; i >= 0; --i)
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