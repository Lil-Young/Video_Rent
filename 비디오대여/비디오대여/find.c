#include<stdio.h> //printf, scanf
#include"my_struct.h" //����� �ڷ���
#define _CRT_SECURE_NO_WARINGS //scanf ���� ���� ���� ������ ���� ����

//�Լ� user_find�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void user_find(user* u_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	user* p = NULL; 
	p = u_head->next;

	//���� ����
	int cnt = 0; 
	char name[10];

	printf("�����ڸ� �˻��մϴ�.\n");
	printf("�˻��ϰ���� ������ �̸��� �Է����ּ���: "); scanf("%s", name);

	//�Է��� name�� �������� �����ִ� ����
	while (p->next != NULL) {
		if (strcmp(p->user_name, name) == 0) {
			cnt++;
			printf("������ �̸�: %s, ������ id: %s\n", p->user_name, p->user_id);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("�����ڰ� �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
	}
}

//�Լ� video_find�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void video_find(video* v_head) {

	char title[30]; //���� ����

	//�����ͺ��� ���� �� �ʱ�ȭ
	video* p = NULL; 
	p = v_head->next;

	printf("������ �˻��մϴ�.\n");
	printf("�˻��ϰ���� ���� ������ �Է����ּ���: "); scanf("%s", title);

	//�Է��� title�� �������� �����ִ� ����
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("���� ����: %s, ���� ���: %d\n", p->video_title, p->stock);
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("������ �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
	}
}

//�Լ� rent_user_find�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void rent_user_find(rent* r_head) {

	//���� ����
	char id[10]; 
	int cnt = 0;

	//�����ͺ��� ���� �� �ʱ�ȭ
	rent* p = NULL; 
	p = r_head->next;

	printf("�뿩�� �����ڸ� �˻��մϴ�.\n");
	printf("�뿩�� �������� id�� �Է����ּ���: "); scanf("%s", id);

	//�Է��� id�� �������� �����ִ� ����
	while (p->next != NULL) {
		if (strcmp(p->user_id, id) == 0) {
			cnt++;
			printf("������ id: %s, ���� ����: %s, �뿩��¥: %s, �ݳ���¥: %s\n"
				, p->user_id, p->video_title, p->rent_date, p->return_date);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("�뿩�� �������� id�� �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
	}
}
