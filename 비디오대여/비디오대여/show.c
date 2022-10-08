// printf, scanf
#include<stdio.h>
// ����� �ڷ���
#include"my_struct.h"
// scanf ���� ���� ���� ������ ���� ����
#define _CRT_SECURE_NO_WARINGS

// �뿩������ ���� ��� ���
void video_show(video* v_head) {
	video* p = NULL;
	p = v_head->next;
	if (p->next == NULL) {
		printf("�뿩������ ������ �������� �ʽ��ϴ�.\n");
		return 0;
	}
	printf("*** �뿩������ ���� ����Դϴ�. ***\n");
	while (p->next != NULL) {
		if (p->stock != 0) {
			printf("���� ����: %s, ���� ���: %d\n", p->video_title, p->stock);
		}
		p = p->next;
	}
}

// �������� �̸��� id ���
void user_show(user* u_head) {
	user* p = NULL;
	p = u_head->next;
	if (p->next == NULL) {
		printf("�����ڰ� �������� �ʽ��ϴ�.\n");
		return 0;
	}
	printf("*** ������ ����Դϴ�. ***\n");
	while (p->next != NULL) {
		printf("������ �̸�: %s, ������ id: %s\n", p->user_name, p->user_id);
		p = p->next;
	}
}

void rent_show(rent* r_head) {
	rent* p = NULL;
	p = r_head->next;
	if (p->next == NULL) {
		printf("������ �뿩�� �����ڰ� �������� �ʽ��ϴ�.\n");
		return 0;
	}
	printf("*** ������ �뿩�� ������ id�� ���� ����Դϴ�. ***\n");
	while (p->next != NULL) {
		printf("������ id: %s, ���� ����: %s, �뿩��¥: %s, �ݳ���¥: %s\n"
			, p->user_id, p->video_title, p->rent_date, p->return_date);
		p = p->next;
	}
}

void delayed_date(rent* r_head) {
	rent* p = NULL;
	p = r_head->next;
	char date[10]; 
	int cnt = 0;

	printf("*** �ݳ���¥�� ���� ������ id�� ���� ����Դϴ� ***.\n");
	printf("���� ��¥�� �Է����ּ���: "); scanf("%s", date);
	while (p->next != NULL) {
		if (strcmp(p->return_date, date) < 0) {
			cnt++;
			printf("������ id: %s, ���� ����: %s, �뿩��¥: %s, �ݳ���¥: %s\n"
				, p->user_id, p->video_title, p->rent_date, p->return_date);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("�ݳ���¥�� ���� �����ڰ� �������� �ʽ��ϴ�.\n");
		return 0;
	}
}