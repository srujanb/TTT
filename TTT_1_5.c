/*
Code: Tic tac toe
0
0
Author: SRUJ
*/
#include<stdio.h>
#include<conio.h>
void print();
void user_turn();
int check();
void system_turn();
int primary();
char v[10]={'0','1','2','3','4','5','6','7','8','9'};
void main()
{
	int wl=0;
	int ctr9=0;
	clrscr();
	do
	{
		ctr9++;
		print();
		user_turn();
		wl=check();
		if (wl==1)
		{
			printf("\n YOU WIN");
			goto end;
		}
		if (ctr9==5)
		{
			printf("MATCH DRAW");
			goto end;
		}
		system_turn();
		wl=check();
		if(wl==1)
		{
			printf("\nYOU LOSE");
			goto end;
		}
	}while(1>0);
	end:
	getch();
}
void print()
{
	printf("\n%c | %c | %c",v[7],v[8],v[9]);
	printf("\n==|===|==");
	printf("\n%c | %c | %c",v[4],v[5],v[6]);
	printf("\n==|===|==");
	printf("\n%c | %c | %c",v[1],v[2],v[3]);
}
void user_turn()
{
	int get_pos;
	int ctr;
	do
	{
		ctr=0;
		printf("\n\nPlease enter a valid position: ");
		scanf("%d",&get_pos);
		if (((get_pos+9)/10)!=1)
		{
			printf("\n0<number>10");
			ctr++;
		}
		if(v[get_pos]=='O'||v[get_pos]=='X')
		{
			printf("\nSorry, Position already occupied");
			ctr++;
		}
	}while(ctr!=0);
	v[get_pos]='X';
}
int check()
{
	if ((v[1]==v[2]&&v[2]==v[3])||(v[4]==v[5]&&v[5]==v[6])||(v[7]==v[8]&&v[8]==v[9])||(v[1]==v[4]&&v[4]==v[7])||(v[2]==v[5]&&v[5]==v[8])||(v[3]==v[6]&&v[6]==v[9])||(v[1]==v[5]&&v[5]==v[9])||(v[7]==v[5]&&v[5]==v[3]))
	{
		//printf("\nCheck function returned 1\n");
		return(1);
	}
	else
	{
		//printf("\ncheck function returned 0\n");
		return(0);
	}
}
void system_turn()
{
	int ret_pos;
	ret_pos=primary();
	if (ret_pos!=0)
		goto found;
	ret_pos=secondary();
	if (ret_pos!=0)
		goto found;
	/*ret_pos=attack();
	if (ret_pos!=0)
		goto found;
	ret_pos=strategy();
	if (ret_pos!=0)
		goto found;*/
	ret_pos=random_position();
	found:
	v[ret_pos]='O';
}
int primary()
{
	int ctr;
	int found;
	for(ctr=1;ctr<11;ctr++)
	{
		if (v[ctr]!='O'&&v[ctr]!='X')
		{
			v[ctr]='X';
			found=check();
			if(found==1)
				return(ctr);
			else
				v[ctr]=ctr+48;
		}
	} 
	return(0);
}	
int random_position()
{
	int ctr;
	for(ctr=1;;ctr++)
	{
		if(v[ctr]!='O'&&v[ctr]!='X')
			return(ctr);
	}
}
int secondary()
{
	int i,ii;
	int wl;
	int ctr_wl;
	for(i=1;i<10;i++)
	{
		if(v[i]!='O'&&v[i]!='X')
		{
			v[i]='X';
			for(ii=1;ii<10;ii++)
			{
				if(v[ii]!='O'&&v[ii]!='X')
				{
					v[ii]='X';
					wl=0;
					wl=check();
					if(wl==1)
						ctr_wl++;
					if(ctr_wl==2)
					{
						v[ii]=(ii+48);
						v[i]=(i+48);
						return(i);
					}
					v[ii]=(ii+48);
				}
			}
			v[i]=(i+48);
		}
		ctr_wl=0;
	}
	return(0);
}