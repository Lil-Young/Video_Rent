// printf, scanf
#include<stdio.h>
// ����� �ڷ���
#include"my_struct.h"
// scanf ���� ���� ���� ������ ���� ����
#define _CRT_SECURE_NO_WARINGS

void user_find(user* u_head) {
	char name[10];
	printf("�˻��ϰ���� ������ �̸��� �Է����ּ���: "); scanf("%s", name);
	user* p = NULL;
	p = u_head->next;
	int cnt = 0;
	while (p->next != NULL) {
		if (strcmp(p->user_name, name) == 0) {
			cnt++;
			printf("������ �̸�: %s, ������ id: %s\n", p->user_name, p->user_id);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("�����ڰ� �������� �ʽ��ϴ�. �ٽ� �õ����ּ���\n");
	}
}

void video_find(video* v_head) {
	char title[30];
	printf("�˻��ϰ���� ���� ������ �Է����ּ���: "); scanf("%s", title);
	video* p = NULL;
	p = v_head->next;
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("���� ����: %s, ���� ���: %d\n", p->video_title, p->stock);
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("������ �������� �ʽ��ϴ�. �ٽ� �õ����ּ���\n");
	}
}

void rent_find(rent* r_head) {
	char id[10];
	printf("�뿩�� �������� id�� �Է����ּ���: "); scanf("%s", id);
	rent* p = NULL;
	p = r_head->next;
	int cnt = 0;
	while (p->next != NULL) {
		if (strcmp(p->user_id, id) == 0) {
			cnt++;
			printf("������ id: %s, ���� ����: %s, �뿩��¥: %s, �ݳ���¥: %s\n"
				, p->user_id, p->video_title, p->rent_date, p->return_date);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("�뿩�� �������� id�� �������� �ʽ��ϴ�. �ٽ� �õ����ּ���\n");
	}
}
