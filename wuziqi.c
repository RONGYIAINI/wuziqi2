#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_ROW 18
#define MAX_COL 18
#define ROW 10
#define COL 10
//�˵�
int Meau() {
	printf("-----------\n");
	printf("1.��ʼ��Ϸ\n");
	printf("2.������Ϸ\n");
	printf("-----------\n");
	printf("��ѡ��\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
char arr[MAX_ROW][MAX_COL];
//��ʼ������

void Init() {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			arr[row][col] = ' ';
		}
	}

}
//��ӡ����
void Print() {
	for (int row = 0; row < ROW; row++) {
		printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n",
			arr[row][0], arr[row][1], arr[row][2], arr[row][3], arr[row][4],
		arr[row][5], arr[row][6], arr[row][7], arr[row][8], arr[row][9]);
		if (row != 9) {
			printf("|---|---|---|---|---|---|---|---|---|---|\n");
		}

	}
}
//���������X��ʾ
void PlayerMove() {
	int row = 0, col = 0;
	while (1) {
		printf("������һ������(row col):\n");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col<0 || col>+COL) {
			printf("�������벻�Ϸ�,����������\n");
			continue;
		}
		else if (arr[row][col] != ' ') {
			printf("��λ���ѱ�ռ��,����������\n");
			continue;
		}
		else {
			arr[row][col] = 'X';
			break;
		}
	}
	arr[row][col] = 'X';

}

//����������O��ʾ
void ComputerMove() {
	while (1) {
		int row = rand() % ROW;
		int col = rand() % COL;
		if (arr[row][col] != ' ') {
			continue;
		}
		arr[row][col] = 'O';
		break;
	}

}
//�ж��Ƿ����
int Isfull() {
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			if (arr[row][col] == ' ') {
				return 1;
			}
		}
	}
	return 0;
}
//�����Ϸ�Ƿ����
int CheckGameOver( ) {
	//�ж�ÿһ��
	for (int row = 0; row < ROW; row++) {
		
		if (arr[row][0] == arr[row][1] && arr[row][0] == arr[row][2] && arr[row][0] == arr[row][3] && arr[row][0] == arr[row][4]
			  && arr[row][0] != ' ') {
			return arr[row][0];
			break;
		}
		if (arr[row][1] == arr[row][2] && arr[row][1] == arr[row][3] && arr[row][1] == arr[row][4] && arr[row][1] == arr[row][5]
			&& arr[row][1] != ' ') {
			return arr[row][1];
			break;
		}
		if (arr[row][2] == arr[row][3] && arr[row][2] == arr[row][4] && arr[row][2] == arr[row][5] && arr[row][2] == arr[row][6]
			&& arr[row][2] != ' ') {
			return arr[row][2];
			break;
		}
		if (arr[row][3] == arr[row][4] && arr[row][3] == arr[row][5] && arr[row][3] == arr[row][6] && arr[row][3] == arr[row][7]
			&& arr[row][3] != ' ') {
			return arr[row][3];
			break;
		}
		if (arr[row][4] == arr[row][5] && arr[row][4] == arr[row][6] && arr[row][4] == arr[row][7] && arr[row][4] == arr[row][8]
			&& arr[row][4] != ' ') {
			return arr[row][4];
			break;
		}
		if (arr[row][5] == arr[row][6] && arr[row][5] == arr[row][7] && arr[row][5] == arr[row][8] && arr[row][5] == arr[row][9]
			&& arr[row][5] != ' ') {
			return arr[row][0];
			break;
		}
		
	}
	//�ж�ÿһ��
	for (int col = 0; col < COL; col++) {
		if (arr[0][col] == arr[1][col] && arr[0][col] == arr[2][col] && arr[0][col] == arr[3][col] && arr[0][col] == arr[4][col]
			&& arr[0][col]!=' ') {
			return arr[0][col];
			break;
		}
		if (arr[1][col] == arr[2][col] && arr[1][col] == arr[3][col] && arr[1][col] == arr[4][col] && arr[1][col] == arr[5][col]
			&& arr[1][col] != ' ') {
			return arr[1][col];
			break;
		}
		if (arr[2][col] == arr[3][col] && arr[2][col] == arr[4][col] && arr[2][col] == arr[5][col] && arr[2][col] == arr[6][col]
			&& arr[2][col] != ' ') {
			return arr[2][col];
			break;
		}	
		if (arr[3][col] == arr[4][col] && arr[3][col] == arr[5][col] && arr[3][col] == arr[6][col] && arr[3][col] == arr[7][col]
			&& arr[3][col] != ' ') {
			return arr[3][col];
			break;
		}
		if (arr[4][col] == arr[5][col] && arr[4][col] == arr[6][col] && arr[4][col] == arr[7][col] && arr[4][col] == arr[8][col]
			&& arr[4][col] != ' ') {
			return arr[4][col];
			break;
		}
		if (arr[5][col] == arr[6][col] && arr[5][col] == arr[7][col] && arr[5][col] == arr[8][col] && arr[5][col] == arr[9][col]
			&& arr[5][col] != ' ') {
			return arr[5][col];
			break;
		}
	}
	
	
	
	//�ж�б��
	for (int i = 0; i < ROW; i++) {
		if (arr[i][i] == arr[i+1][i+1] && arr[i][i] == arr[i+2][i+2] && arr[i][i] == arr[i+3][i+3] && arr[i][i] == arr[i+4][i+4]
			&& arr[i][i]!=' ') {
			return arr[i][i];
		}
		if (arr[i][i + 1] == arr[i + 1][i + 2] && arr[i][i + 1] == arr[i + 2][i + 3] && arr[i][i + 1] == arr[i + 3][i + 4]
			&& arr[i][i + 1] == arr[i + 4][i + 5] && arr[i][i+1] !=' ') {
			return arr[i][i + 1];
		}
		if (arr[i][i + 2] == arr[i + 1][i + 3] && arr[i][i + 2] == arr[i + 2][i + 4] && arr[i][i + 2] == arr[i + 3][i + 5]
			&& arr[i][i + 2] == arr[i + 4][i + 6] && arr[i][i + 2] != ' ') {
			return arr[i][i + 2];
		}
		if (arr[i][i + 3] == arr[i + 1][i + 4] && arr[i][i + 3] == arr[i + 2][i + 5] && arr[i][i + 3] == arr[i + 3][i + 6]
			&& arr[i][i + 3] == arr[i + 4][i + 7] && arr[i][i + 3] != ' ') {
			return arr[i][i + 3];
		}
		if (arr[i][i + 4] == arr[i + 1][i + 5] && arr[i][i + 4] == arr[i + 2][i + 6] && arr[i][i + 4] == arr[i + 3][i + 7]
			&& arr[i][i + 4] == arr[i + 4][i + 8] && arr[i][i + 4] != ' ') {
			return arr[i][i + 4];
		}
		if (arr[i][i + 5] == arr[i + 1][i + 6] && arr[i][i + 5] == arr[i + 2][i + 7] && arr[i][i + 5] == arr[i + 3][i + 8]
			&& arr[i][i + 5] == arr[i + 4][i + 9] && arr[i][i + 5] != ' ') {
			return arr[i][i + 5];
		}
		if (arr[i][i - 1] == arr[i + 1][i] && arr[i][i - 1] == arr[i + 2][i + 1] && arr[i][i - 1] == arr[i + 3][i + 2]
			&& arr[i][i - 1] == arr[i + 4][i + 3] && arr[i][i - 1] != ' ') {
			return arr[i][i - 1];
		}
		if (arr[i][i - 2] == arr[i + 1][i - 1] && arr[i][i - 2] == arr[i + 2][i] && arr[i][i - 2] == arr[i + 3][i + 1]
			&& arr[i][i - 2] == arr[i + 4][i + 2] && arr[i][i - 2] != ' ') {
			return arr[i][i - 2];
		}
		if (arr[i][i - 3] == arr[i + 1][i - 2] && arr[i][i - 3] == arr[i + 2][i - 1] && arr[i][i + 3] == arr[i + 3][i]
			&& arr[i][i - 3] == arr[i + 4][i + 1] && arr[i][i - 3] != ' ') {
			return arr[i][i - 3];
		}
		if (arr[i][i - 4] == arr[i + 1][i - 3] && arr[i][i - 4] == arr[i + 2][i - 2] && arr[i][i - 4] == arr[i + 3][i - 1]
			&& arr[i][i - 4] == arr[i + 4][i] && arr[i][i - 4] != ' ') {
			return arr[i][i - 4];
		}
		if (arr[i][i - 5] == arr[i + 1][i - 4] && arr[i][i - 5] == arr[i + 2][i - 3] && arr[i][i - 5] == arr[i + 3][i - 2]
			&& arr[i][i - 5] == arr[i + 4][i - 1] && arr[i][i - 5] != ' ') {
			return arr[i][i - 5];
		}
		if (arr[i][9 - i] == arr[i + 1][8 - i] && arr[i][9 - i] == arr[i + 2][7 - i] && arr[i][9 - i] == arr[i + 3][6 - i] &&
			arr[i][9 - i] == arr[i + 4][5 - i] && arr[i][9 - i] != ' ') {
			return arr[i][9 - i];
		}
		if (arr[i][8 - i] == arr[i + 1][7 - i] && arr[i][8 - i] == arr[i + 2][6 - i] && arr[i][8 - i] == arr[i + 3][5 - i] &&
			arr[i][8 - i] == arr[i + 4][4 - i]&& arr[i][8 - i] != ' ') {
			return arr[i][8 - i];
		}
		if (arr[i][7 - i] == arr[i + 1][6 - i] && arr[i][7 - i] == arr[i + 2][5 - i] && arr[i][7 - i] == arr[i + 3][4 - i] &&
			arr[i][7 - i] == arr[i + 4][3 - i] && arr[i][7 - i] != ' ') {
			return arr[i][7 - i];
		}
		if (arr[i][6 - i] == arr[i + 1][5 - i] && arr[i][6 - i] == arr[i + 2][4 - i] && arr[i][6 - i] == arr[i + 3][3 - i] &&
			arr[i][6 - i] == arr[i + 4][2 - i] && arr[i][6 - i] != ' ') {
			return arr[i][6 - i];
		}
		if (arr[i][5 - i] == arr[i + 1][4 - i] && arr[i][5 - i] == arr[i + 2][3 - i] && arr[i][5 - i] == arr[i + 3][2 - i] &&
			arr[i][5 - i] == arr[i + 4][1 - i] && arr[i][5 - i] != ' ') {
			return arr[i][5 - i];
		}
		if (arr[i][4 - i] == arr[i + 1][3 - i] && arr[i][4 - i] == arr[i + 2][2 - i] && arr[i][4 - i] == arr[i + 3][1 - i] &&
			arr[i][4 - i] == arr[i + 4][i] && arr[i][4 - i] != ' ') {
			return arr[i][4 - i];
		}
		if (arr[i + 1][9 - i] == arr[i + 2][8 - i] && arr[i + 1][9 - i] == arr[i + 3][7 - i] && arr[i + 1][9 - i] == arr[i + 4][6 - i] &&
			arr[i + 1][9 - i] == arr[i + 5][5 - i] && arr[i + 1][9 - i] != ' ') {
			return arr[i + 1][9 - i];
		}
		if (arr[i + 2][9 - i] == arr[i + 3][8 - i] && arr[i + 2][9 - i] == arr[i + 4][7 - i] && arr[i + 2][9 - i] == arr[i + 5][6 - i] &&
			arr[i + 2][9 - i] == arr[i + 6][5 - i] && arr[i + 2][9 - i] != ' ') {
			return arr[i + 2][9 - i];
		}
		if (arr[i + 3][9 - i] == arr[i + 4][8 - i] && arr[i + 3][9 - i] == arr[i + 5][7 - i] && arr[i + 3][9 - i] == arr[i + 6][6 - i] &&
			arr[i + 3][9 - i] == arr[i + 7][5 - i] && arr[i + 3][9 - i] != ' ') {
			return arr[i + 3][9 - i];
		}
		if (arr[i + 4][9 - i] == arr[i + 5][8 - i] && arr[i + 4][9 - i] == arr[i + 6][7 - i] && arr[i + 4][9 - i] == arr[i + 7][6 - i] &&
			arr[i + 4][9 - i] == arr[i + 8][5 - i] && arr[i + 4][9 - i] != ' ') {
			return arr[i + 4][9 - i];
		}
		if (arr[i + 5][9 - i] == arr[i + 6][8 - i] && arr[i + 5][9 - i] == arr[i + 7][7 - i] && arr[i + 5][9 - i] == arr[i + 8][6 - i] &&
			arr[i + 5][9 - i] == arr[i + 9][5 - i] && arr[i + 5][9 - i] != ' ') {
			return arr[i + 5][9 - i];
		}
	}
	int n = Isfull();
	if (n == 0) {
		return 'Q';
	}
	return ' ';
}
void Game() {
	//��������ʼ��һ������
	Init();
	char winner = ' ';
	while (1) {

		//��ӡ����
		Print();
		//�������
		PlayerMove();
		//�����Ϸ����

		winner = CheckGameOver();
		if (winner != ' ') {
			break;
		}

		//��������
		ComputerMove();
		//�����Ϸ����

		winner = CheckGameOver();
		if (winner != ' ') {
			break;
		}

	}
	if (winner == 'X') {
		printf("���ʤ!\n");
	}
	else if (winner == 'O') {
		printf("����ʤ!\n");
	}
	else if (winner == 'Q') {
		printf("����!\n");
	}
	else {
		printf("���������!\n");
	}


}

int main() {
	while (1) {
		int choice = Meau();
		if (choice == 1) {
			Game();
		}
		else if (choice == 2) {
			printf("goodbye!\n");
			break;
		}
		else {
			printf("��������,����������\n");
			continue;
		}
	}

	system("pause");
	return 0;
}
