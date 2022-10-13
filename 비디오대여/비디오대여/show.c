#include<stdio.h> //printf, scanf
#include"my_struct.h" //����� �ڷ���
#define _CRT_SECURE_NO_WARINGS //scanf ���� ���� ���� ������ ���� ����

//�Լ� user_video_show�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void user_video_show(video* v_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	video* p = NULL; 
	p = v_head->next;

	printf("�뿩������ ������ �����ݴϴ�.\n");
	if (p->next == NULL) {
		printf("�뿩������ ������ �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
		return 0;
	}
	printf("*** �뿩������ ���� ����Դϴ�. ***\n");

	//�뿩 ������ ����(��)�� �����ִ� ����
	while (p->next != NULL) {
		if (p->stock != 0) {
			printf("���� ����: %s, ���� ���: %d\n", p->video_title, p->stock);
		}
		p = p->next;
	}
}

//�Լ� all_video_show�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void all_video_show(video* v_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	video* p = NULL; 
	p = v_head->next;
	printf("��� ������ �����ݴϴ�.\n");
	if (p->next == NULL) {
		printf("������ �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
		return 0;
	}
	printf("*** ��� ���� ����Դϴ�. ***\n");

	//��� ����(��)�� �����ִ� ����
	while (p->next != NULL) {
		printf("���� ����: %s, ���� ���: %d\n", p->video_title, p->stock);
		p = p->next;
	}
}

//�Լ� user_show�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void user_show(user* u_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	user* p = NULL; 
	p = u_head->next;
	printf("�����ڸ� �����ݴϴ�.\n");
	if (p->next == NULL) {
		printf("�����ڰ� �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
		return 0;
	}
	printf("*** ������ ����Դϴ�. ***\n");

	//������(��)�� �����ִ� ����
	while (p->next != NULL) {
		printf("������ �̸�: %s, ������ id: %s\n", p->user_name, p->user_id);
		p = p->next;
	}
}

//�Լ� rent_show�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void rent_show(rent* r_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	rent* p = NULL;
	p = r_head->next;

	printf("������ �뿩�� �������� ������ �����ݴϴ�.\n");
	if (p->next == NULL) {
		printf("������ �뿩�� �����ڰ� �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
		return 0;
	}
	printf("*** ������ �뿩�� ������ id�� ���� ����Դϴ�. ***\n");

	//������ �뿩�� ������(��)�� �����ִ� ����
	while (p->next != NULL) {
		printf("������ id: %s, ���� ����: %s, �뿩��¥: %s, �ݳ���¥: %s\n"
			, p->user_id, p->video_title, p->rent_date, p->return_date);
		p = p->next;
	}
}

//�Լ� delayed_date�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void delayed_date(rent* r_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	rent* p = NULL; 
	p = r_head->next;

	//���� ����
	char date[10];
	int cnt = 0;

	printf("�ݳ���¥�� ���� �������� ������ �����ݴϴ�.\n");
	if (p->next == NULL) {
		printf("������ �뿩�� �����ڰ� �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
		return 0;
	}
	printf("*** �ݳ���¥�� ���� ������ id�� ���� ����Դϴ� ***.\n");
	printf("���� ��¥�� �Է����ּ���: "); scanf("%s", date);

	//�Է��� date���� ����(�ݳ���¥������) ������(��)�� �����ִ� ����
	while (p->next != NULL) {
		if (strcmp(p->return_date, date) < 0) {
			cnt++;
			printf("������ id: %s, ���� ����: %s, �뿩��¥: %s, �ݳ���¥: %s\n"
				, p->user_id, p->video_title, p->rent_date, p->return_date);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("�ݳ���¥�� ���� �����ڰ� �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
		return 0;
	}
}

//�Լ� return_show�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void return_show(rent* return_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	rent* p = NULL; 
	p = return_head->next;

	printf("������ �ݳ��� �Ϸ��� �������� ������ �����ݴϴ�.\n");
	if (p->next == NULL) {
		printf("������ �ݳ��� �����ڰ� �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
		return 0;
	}
	printf("*** ������ �ݳ��� ������ id�� ���� ����Դϴ�. ***\n");

	//������ �ݳ��� ������(��)�� �����ִ� ����
	while (p->next != NULL) {
		printf("������ id: %s, ���� ����: %s, �뿩��¥: %s, �ݳ���¥: %s\n"
			, p->user_id, p->video_title, p->rent_date, p->return_date);
		p = p->next;
	}
}