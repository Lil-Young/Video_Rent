// printf
#include<stdio.h>
// malloc
#include<stdlib.h>
// strcpy, strlen
#include<string.h>
// ����� �ڷ���
#include"my_struct.h"

void user_insert(user* u_tail, user* u_head) {
	char id[10]; char name[10];
	printf("name:"); scanf("%s", name); printf("id: "); scanf("%s", id);

	user* p = NULL;
	user* newNode = NULL;
	p = u_head->next;
	while (p->next != NULL) {
		if (strcmp(p->user_id, id) == 0) {
			printf("�Է��Ͻ� id�� �̹� �����մϴ�. �ٽ� �õ����ּ���\n");
			return 0;
		}
		p = p->next;
	}
	newNode = (user*)malloc(sizeof(user));
	newNode->user_id = (char*)malloc(sizeof(char) * strlen(id) + 1);
	newNode->user_name = (char*)malloc(sizeof(char) * strlen(name) + 1);

	strcpy(newNode->user_id, id);
	strcpy(newNode->user_name, name);

	p = NULL;
	p = u_tail->prev; newNode->next = p->next; newNode->prev = p; p->next = newNode; u_tail->prev = newNode;
	user_store(u_head);
}

void video_insert(video* v_tail, video* v_head) {
	char title[30]; int stock;
	printf("title: "); scanf("%s", title); printf("stock: "); scanf("%d", &stock);

	video* p = NULL;
	video* newNode = NULL;
	p = v_head->next;
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("�Է��Ͻ� ������ �̹� �����մϴ�. �ٽ� �õ����ּ���\n");
			return 0;
		}
		p = p->next;
	}

	newNode = (video*)malloc(sizeof(video));
	newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);

	strcpy(newNode->video_title, title);
	newNode->stock = stock;

	p = v_tail->prev; newNode->next = p->next; newNode->prev = p; p->next = newNode; v_tail->prev = newNode;
	video_store(v_head);
}


void rent_insert(rent* r_tail, video* v_head, user* u_head, rent* r_head) {
	char rent_d[10]; char return_d[10];

	rent* p = NULL;
	rent* newNode = NULL;

	// �������� ������� id�� �ִ��� Ȯ���ϴ� ����
	user* id_p = NULL;
	id_p = u_head->next;
	char id[10]; printf("������ id�� �Է����ּ���: "); scanf("%s", id);
	while (id_p->next != NULL) {
		if (strcmp(id_p->user_id, id) == 0) {
			printf("id�� Ȯ�εǾ����ϴ�.\n");
			break;
		}
		id_p = id_p->next;
	}
	if (id_p->next == NULL) {
		printf("�Է��Ͻ� id�� �������� �ʽ��ϴ�.\n");
		return 0;
	}

	// ��������� video title�� �ִ��� Ȯ���ϴ� ����
	video* title_p = NULL;
	title_p = v_head->next;
	char title[30]; printf("�뿩�ϰ���� ���� ������ �Է����ּ���: "); scanf("%s", title);
	while (title_p->next != NULL) {
		if (strcmp(title_p->video_title, title) == 0) {
			(title_p->stock)--;
			break;
		}
		title_p = title_p->next;
	}
	if (title_p->next == NULL) {
		printf("�뿩�ϰ���� ���� ������ �����ϴ�.\n");
		return 0;
	}

	printf("rent_date: "); scanf("%s", rent_d); printf("return_date: "); scanf("%s", return_d);

	newNode = (rent*)malloc(sizeof(rent));
	newNode->video_title = (char*)malloc(sizeof(char) * strlen(title) + 1);
	newNode->user_id = (char*)malloc(sizeof(char) * strlen(id) + 1);
	newNode->rent_date = (char*)malloc(sizeof(char) * strlen(rent_d) + 1);
	newNode->return_date = (char*)malloc(sizeof(char) * strlen(return_d) + 1);

	strcpy(newNode->video_title, title);
	strcpy(newNode->user_id, id);
	strcpy(newNode->rent_date, rent_d);
	strcpy(newNode->return_date, return_d);

	p = r_tail->prev; newNode->next = p->next; newNode->prev = p; p->next = newNode; r_tail->prev = newNode;
	rent_store(r_head);
}