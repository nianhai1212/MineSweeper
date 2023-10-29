#include "boom.h"

void manu() {
	printf("*******************\n");
	printf("*****1.play********\n");
	printf("*****0.exit********\n");
	printf("*******************\n");
}

void game() {

	printf("Gaming\n");

	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};

	srand((unsigned char)time(NULL));

	//init board
	initBoard(mine,ROWS,COLS,'0');
	initBoard(show,ROWS,COLS,'*');

	//display to check 
	//displayBoard(mine,ROW,COL);
	displayBoard(show,ROW,COL);

	//arrange the boom pos
	arrangeBoomPos(mine,ROW,COL);
	displayBoard(mine,ROW,COL);

	//findBoom
	findBoom(mine,show,ROW,COL);
	displayBoard(show,ROW,COL);
}

void test() {
	int input = 0;

	do {
		manu();
		printf("Pleae input choice:>\n");
		scanf("%d",&input);

		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("Quit Game!\n");
				break;
			default:
				printf("Error Choice please chose again!\n");
				break;
		}
	}while(input);
}

int main()
{
	test();
	//printf("Hello World!\n");
}
