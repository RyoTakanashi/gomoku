#include<stdio.h>
#include<string.h>
void draw_board(char *pBoard)
{
	int x,y;
	char RowIndex[15]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};
	printf("  a b c d e f g h i j k l m n o\n");
		for(x=0; x<15; x++){
			printf("%c ",RowIndex[x]);
				for(y=0; y<15; y++){
						printf("%c ", *(pBoard+15*x+y));
				}
			printf("\n");
		}
}
int input_stone(int Turn, int *pRow, int *pColumn)
{
	char x[4];
	if(Turn==0){
		printf("sente (@) > ");
	}
	else{
		 printf("gote(0) > ");
	}
				fgets(x,4, stdin);
	*pRow=x[0]-65;
	*pColumn=x[1]-97;
	if(*pRow == 25 && *pColumn == 25){
		return(-1);
 	}
	if(*pRow>14 || *pColumn>14 || *pRow<0 || *pColumn<0){
		return(0);
	}
	return(1);
}
int place_stone(int Turn, int Row, int Column, char *pBoard)
{	
	if(*(pBoard+15*Row+Column)=='+')
	{
		if(Turn==0){
			*(pBoard+15*Row+Column)='@';
		}
		else{
			*(pBoard+15*Row+Column)='0';	
		}
	return(0);
	}
	else{
		return(-1);
	}
}
int decision_row(int Row, int Column, char *pBoard)
{
	int i, LineLen=0;
	i=0;
	while(1)
	{
		i++;
		if((Row-i)<0)
			break;
		if(*(pBoard+15*(Row-i)+Column)==*(pBoard+15*Row+Column)) LineLen++;
			else break;
	}
	i=0;
	while(1)
	{
		i++;
		if((Row+i)>14)
			break;
		if(*(pBoard+15*(Row+i)+Column)==*(pBoard+15*Row+Column)) LineLen++;
		else
		break;
	}
	if(LineLen>=4)
	return(1);
	else return(0);
}
int decision_column(int Row, int Column, char *pBoard)
{
	int i, LineLen=0;
	i=0;
	while(1)
	{
		i++;
		if((Column-i)<0)
			break;
		if(*(pBoard+15*Row+(Column-i))==*(pBoard+15*Row+Column)) LineLen++;
			else break;
	}
	i=0;
	while(1)
	{
		i++;
		if((Column+i)>14)
			break;
		if(*(pBoard+15*Row+(Column+i))==*(pBoard+15*Row+Column)) LineLen++;
		else
		break;
	}
	if(LineLen>=4)
	return(1);
	else return(0);
}
int decision_diagonal1(int Row, int Column, char *pBoard)
{
	int i, LineLen=0;
	i=0;
	while(1)
	{
		i++;
		if((Column-i)>14 || (Row-i)<0)
			break;
		if(*(pBoard+15*(Row-i)+(Column-i))==*(pBoard+15*Row+Column)) LineLen++;
			else break;
	}
	i=0;
	while(1)
	{
		i++;
		if((Column-i)<0 || (Row+i)>14)
			break;
		if(*(pBoard+15*Row+(Column+i))==*(pBoard+15*Row+Column)) LineLen++;
		else
		break;
	}
	if(LineLen>=4)
	return(1);
	else return(0);
}
int decision_diagonal2(int Row, int Column, char *pBoard)
{
	int i, LineLen=0;
	i=0;
	while(1)
	{
		i++;
		if((Column-i)>14 || (Row-i)<0)
			break;
		if(*(pBoard+15*Row+(Column-i))==*(pBoard+15*Row+Column)) LineLen++;
			else break;
	}

	i=0;
	while(1)
	{
		i++;
		if((Column-i)<0 || (Row+i)>14)
			break;
		if(*(pBoard+15*Row+(Column+i))==*(pBoard+15*Row+Column)) LineLen++;
		else
		break;
	}
	if(LineLen>=4)
	return(1);
	else return(0);
}

int main()
{
	int stone, Turn=0, Row, Column;
	int x,y,z;
	char Board[15][15];

	for(x=0; x<15; x++){
		for(y=0; y<15; y++){
			Board[x][y]='+';
		}
	}

	draw_board(Board[0]);

	while(1)
	{
		switch(input_stone(Turn, &Row, &Column))
		{
			case 0:
				break;
			case 1:
				if(place_stone(Turn,Row,Column,Board[0])==0){
					draw_board(Board[0]);
					if((decision_row(Row,Column,Board[0]))== 1)
					{
						if(Turn==0)
							printf(">winner:@\n");
							else printf(">winner:0\n");
							return(0);
					}
					else if((decision_column(Row,Column,Board[0]))==1)
					{
						if(Turn==0)
							printf(">winner:@\n");
							else printf(">winner:0\n");
							return(0);
					}
					else if((decision_diagonal1(Row,Column,Board[0]))==1)
					{
						if(Turn==0)
							printf(">winner:@\n");
							else printf(">winner:0\n");
							return(0);
					}
					else if((decision_diagonal2(Row,Column,Board[0]))==1)
					{
						if(Turn==0)
							printf(">winner:@\n");
							else printf(">winner:0\n");
							return(0);
					}
					if(Turn==0)
						Turn=1;
					else Turn=0;
						break;

				}else{
					printf("again\n");	
						break;		
					}	
			default:
			return(0);
		}
	}
}
