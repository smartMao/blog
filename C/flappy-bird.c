#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int high, width;  // 画面大小
int bird_x, bird_y; // 小鸟坐标
int bar1_y, bar1_xDown, bar1_xTop; // 障碍物
int score; // 得分

void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // 句柄
	COORD pos;

	pos.X = x;
	pos.Y = y;
	
	SetConsoleCursorPosition(handle, pos);
}

void startup()
{
	high = 15;
	width = 20;
	bird_x = 5;
	bird_y = width / 3;
	bar1_y = width / 2;
	bar1_xDown = high / 3;
	bar1_xTop = high / 2;
	score = 0;
}

void show()
{
	gotoxy(0, 0);

	for (int i = 0; i < high; i++) {
		for (int j = 0; j < width; j++) {
			if((i == bird_x) && (j == bird_y)){
				printf("@"); // 小鸟
			}
			else if ((j == bar1_y) && ((i < bar1_xDown) || (i > bar1_xTop))) {
				printf("#"); // 墙壁
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("得分： %d \n", score);
}

// 与用户输入无关的更新
void updateWithoutInput()
{
	bird_x++;
	bar1_y--;
	if (bird_y == bar1_y) {
		if ((bird_x >= bar1_xDown) && (bird_x <= bar1_xTop)) {
			// 在墙壁的中间， 通过了， 
			score++;
		}
		else {
			// 碰到了墙壁
			printf("游戏失败 \n");
			system("pause");
			exit(0);
		}
	}
	
	if (bar1_y <= 0) {
		bar1_y = width;
		int temp = rand() % (int)(high * 0.8);
		bar1_xDown = temp - high / 10;
		bar1_xTop = temp + high / 10;
	}

	Sleep(150);
}

// 与用户输入有关的更新
void updateWithInput()
{
	char input;
	if (kbhit()) {
		input = getch();
		if (input == ' ') {
			// 按下了空格， 小鸟往上跳
			bird_x = bird_x - 2;
		}
	}
}

int main()
{
	startup(); 
	while (1) {
		show();
		updateWithoutInput();
		updateWithInput();
	}
}
