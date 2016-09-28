/*
 *	author lijinya by 2014/6/29
 *	gcc compile
 *	ladders and chutes game
 * */
#include<stdio.h>
#define N 100	
int roll[N];
int roll_count;
/*
 *	ladders and chutes struct
 *	member start , end square
 * */
typedef struct _ladder_chute{
	int start;
	int end;
}ladder_chutes,*p_ladder_chutes;
ladder_chutes  ladderchute[N];
/*
 *  operator[] immediately roll 1
 *  or miss a roll -1
 * */
int operator[N];
typedef struct _player{
	int again;
	int miss;
	int num;
}player,p_player;
player players[N];
void init(){
	int i=0;
	while(scanf("%d",roll+i),roll[i]){
		++i;
	}
	roll_count=i;
}
void run(player players[],int player_count){
	int cur_pos=1,cur_player=0;
	int i=0,j=0,k=0;
//	player cur_player;
	for(;;){
//		i=i%player_count;
//		cur_player=players[i];
/*		if(players[cur_player].miss){
			cur_player=(cur_player+1)%player_count;
			continue;
		}
		while(1==players[cur_player].again){
			players[cur_player].again=0;
			cur_pos+=roll[i];
			i=(i+1)%roll_count;
		    if(1==operator[cur_pos-1]){
				players[cur_player].again=1;
			}
		}
		cur_pos+=roll[i];
		if(-1==operator[cur_pos-1]){
			players[cur_player].miss=1;
		}else if(1==operator[cur_pos-1]){
			players[cur_player].again=1;
		}
	*/
		cur_pos+=roll[i];
		i=(i+1)%roll_count;
		if(ladderchute[cur_pos-1].start!=0){
			cur_pos=ladderchute[cur_pos-1].end;
		}
		if((95==cur_pos&&(roll[i]+95>100))||(96==cur_pos&&(96+roll[i]>100))||(97==cur_pos&&(97+cur_pos>100))|| \
		(cur_pos==98&&(98+cur_pos>100))||(99==cur_pos&&(cur_pos+99>100))){
			cur_player=(cur_player+1)%player_count;
			i=(i+1)%roll_count;
			continue;
		}
		if(100==cur_pos){
			printf("%d\n",players[cur_player].num);
			break;
		}
		cur_player=(cur_player+1)%player_count;
	}
}
int main(void){
	int player_count,i,start,end;
	init();
	while(scanf("%d",&player_count),player_count){
		if(0==player_count){
			break;
		}
	for(i=0;i<player_count;++i){
			players[i].num=i+1;
			players[i].again=0;
			players[i].miss=0;
		}
		//	input the ladders and chutes
		while(1){
			scanf("%d%d",&start,&end);
			if(0==start||0==end){
				break;
			}
			ladderchute[start-1].start=start;
			ladderchute[start-1].end=end;
		}
		i=0;
		// input the miss immediately roll control
		while(1){
			int pos;
			scanf("%d",&pos);
			if(0==pos){
				break;
			}
			if(pos<0){
				pos=-pos;
				operator[pos-1]=-1;
			}else if(pos>0){
				operator[pos-1]=1;
			}
		}
		//operate
		run(players,player_count);
//		printf("%d\n",current_player);
	}
	return 0;
}
