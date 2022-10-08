// fopen, fclose, fscanf, printf
#include<stdio.h>
// free, malloc
#include<stdlib.h>
// strcpy, strcmp
#include<string.h>
// ����� �ڷ���
#include"my_struct.h"

// �Լ� open_F�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void user_open(user* u_tail) {

	// �����ͺ��� ���� �� �ʱ�ȭ
	user* p = NULL;
	user* newNode = NULL;
	FILE* fp = NULL;

	// ���� ����
	char id[10];
	char name[10];

	// ���� ���� �� �ʱ�ȭ
	int is_eof = 0;

	// PHONE_BOOK.txt ������ r(�б�) ���� ����
	fp = fopen("USER_FILE.txt", "r");
	// fp�� NULL�̸� printf �ƴϸ� else�� �̵��ϰ� printf
	if (fp == NULL) {
		printf("USER_FILE�� �������� �ʽ��ϴ�.\n");
		return 0;
	}
	else {
		printf("USER_FILE�� �ҷ��ɴϴ�.\n");
	}

	// ���ѷ���
	while (1) {
		// fscanf(fp, "%s %s", name, number)���� name, number�� ���� ���� �� ������ EOF�� ��ȯ
		is_eof = fscanf(fp, "%s %s", id, name);

		// is_eof�� EOF�� ��ġ�ϸ� ������ ���̹Ƿ� �ݺ����� Ż���ϱ� ���� break�� �Ѵ�.
		if (is_eof == EOF) {
			break;
		}
		// newNode, newNode->name, newNode->phone_num �޸� �Ҵ�
		newNode = (user*)malloc(sizeof(user));
		newNode->user_id = (char*)malloc(sizeof(char) * strlen(id) + 1);
		newNode->user_name = (char*)malloc(sizeof(char) * strlen(name) + 1);

		// strcpy�� name�� �ִ� ���ڿ��� newNode->name���� ����, number�� �ִ� ���ڿ��� newNode->phone_num���� ����
		strcpy(newNode->user_id, id);
		strcpy(newNode->user_name, name);


		// newNode ����
		p = u_tail->prev;
		newNode->next = p->next;
		newNode->prev = p;
		p->next = newNode;
		u_tail->prev = newNode;
	}
	// ���� ������ �ݱ�
	fclose(fp);
}

// �Լ� open_F�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void video_open(video* v_tail) {

	// �����ͺ��� ���� �� �ʱ�ȭ
	video* p = NULL;
	video* newNode = NULL;
	FILE* fp = NULL;

	// ���� ����
	char title[30];
	int stock;

	// ���� ���� �� �ʱ�ȭ
	int is_eof = 0;

	// PHONE_BOOK.txt ������ r(�б�) ���� ����
	fp = fopen("VIDEO_FILE.txt", "r");
	// fp�� NULL�̸� printf �ƴϸ� else�� �̵��ϰ� printf
	if (fp == NULL) {
		printf("VIDEO_FILE�� �������� �ʽ��ϴ�.\n");
		return 0;
	}
	else {
		printf("VIDEO_FILE�� �ҷ��ɴϴ�.\n");
	}

	// ���ѷ���
	while (1) {
		// fscanf(fp, "%s %s", name, number)���� name, number�� ���� ���� �� ������ EOF�� ��ȯ
		is_eof = fscanf(fp, "%s %d", title, &stock);

		// is_eof�� EOF�� ��ġ�ϸ� ������ ���̹Ƿ� �ݺ����� Ż���ϱ� ���� break�� �Ѵ�.
		if (is_eof == EOF) {
			break;
		}
		// newNode, newNode->name, newNode->phone_num �޸� �Ҵ�
		newNode = (user*)malloc(sizeof(user));
		newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);

		// strcpy�� name�� �ִ� ���ڿ��� newNode->name���� ����, number�� �ִ� ���ڿ��� newNode->phone_num���� ����
		strcpy(newNode->video_title, title);
		newNode->stock = stock;


		// newNode ����
		p = v_tail->prev;
		newNode->next = p->next;
		newNode->prev = p;
		p->next = newNode;
		v_tail->prev = newNode;
	}
	// ���� ������ �ݱ�
	fclose(fp);
}

void rent_open(rent* r_tail) {

	// �����ͺ��� ���� �� �ʱ�ȭ
	rent* p = NULL;
	rent* newNode = NULL;
	FILE* fp = NULL;

	// ���� ����
	char title[30];
	char id[10];
	char rent_d[10];
	char return_d[10];

	// ���� ���� �� �ʱ�ȭ
	int is_eof = 0;

	// PHONE_BOOK.txt ������ r(�б�) ���� ����
	fp = fopen("RENT_FILE.txt", "r");
	// fp�� NULL�̸� printf �ƴϸ� else�� �̵��ϰ� printf
	if (fp == NULL) {
		printf("RENT_FILE�� �������� �ʽ��ϴ�.\n");
		return 0;
	}
	else {
		printf("RENT_FILE�� �ҷ��ɴϴ�.\n");
	}

	// ���ѷ���
	while (1) {
		// fscanf(fp, "%s %s", name, number)���� name, number�� ���� ���� �� ������ EOF�� ��ȯ
		is_eof = fscanf(fp, "%s %s %s %s", title, id, rent_d, return_d);

		// is_eof�� EOF�� ��ġ�ϸ� ������ ���̹Ƿ� �ݺ����� Ż���ϱ� ���� break�� �Ѵ�.
		if (is_eof == EOF) {
			break;
		}
		// newNode, newNode->name, newNode->phone_num �޸� �Ҵ�
		newNode = (rent*)malloc(sizeof(rent));
		newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);
		newNode->user_id = (char*)malloc(sizeof(char) * strlen(id) + 1);
		newNode->rent_date = (char*)malloc(sizeof(char) * strlen(rent_d) + 1);
		newNode->return_date = (char*)malloc(sizeof(char) * strlen(return_d) + 1);

		// strcpy�� name�� �ִ� ���ڿ��� newNode->name���� ����, number�� �ִ� ���ڿ��� newNode->phone_num���� ����
		strcpy(newNode->video_title, title);
		strcpy(newNode->user_id, id);
		strcpy(newNode->rent_date, rent_d);
		strcpy(newNode->return_date, return_d);

		// newNode ����
		p = r_tail->prev;
		newNode->next = p->next;
		newNode->prev = p;
		p->next = newNode;
		r_tail->prev = newNode;
	}
	// ���� ������ �ݱ�
	fclose(fp);
}