#include "boom.h"

void initBoard(char board[ROWS][COLS],int row,int col,char set) {
	int x = 0;
	int y = 0;

	for(x = 0; x < row; x++) {
		for(y = 0; y < col; y++) {
			board[x][y] = set;
		}
	}
}

void displayBoard(char board[ROWS][COLS],int row,int col){
	int x = 0;
	int y = 0;

	for(x = 0; x <= row; x++) {
		printf("%d ",x);
	}
	printf("\n");

	for(x = 1; x <= row; x++) {
		printf("%d ",x);
		for(y = 1; y <= col; y++) {
			printf("%c ",board[x][y]);
		}
		printf("\n");
	}
}

void arrangeBoomPos(char board[ROWS][COLS],int row,int col) {
	int x = 0;
	int y = 0;
	
	int boom_count = 0;

	boom_count = EASY_MODE_NUM;

	while(boom_count) {
		x = rand() % row + 1;
		y = rand() % col + 1;

		//printf("%d %d \n",x,y);
		if(board[x][y] == '0') {
			board[x][y] = '1';
			boom_count--;
		}
	}

}

int boomNumAroundCurrentPos(char mine[ROWS][COLS], int row, int col) {
	int boom_num = 0;

	boom_num = mine[row - 1][col] +
			   mine[row + 1][col] +
			   mine[row - 1][col - 1] +
			   mine[row + 1][col + 1] +
			   mine[row][col - 1] +
			   mine[row][col + 1] +
			   mine[row - 1][col + 1] +
			   mine[row + 1][col - 1] - 
			   8 * '0';

	return boom_num;
}

void findBoom(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;

	int total_blank = 0;
	int boom_num_around_current_pos = 0;


	total_blank = row*col - EASY_MODE_NUM;
	while(total_blank) {
		printf("Please input the pos:>\n");
		scanf("%d%d",&x,&y);
		if((x >= 1 && x <= row) && (y >= 1 && y <= col)) {
			if(mine[x][y] == '1') {
				printf("Sorry,A boom Die!\n");
				break;
			} else {
				boom_num_around_current_pos = boomNumAroundCurrentPos(mine,x,y) + '0';
				printf("BOOMC_DBU:%c\n",boom_num_around_current_pos);
				show[x][y] = boom_num_around_current_pos;
				displayBoard(show,COL,ROW);
				total_blank --;
			}
		} else {
			printf("Pos out of the board range,Enter again!\n");
		}
	}
}
