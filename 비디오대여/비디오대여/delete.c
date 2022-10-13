#include<stdio.h> //printf, scanf
#include<stdlib.h> //free, malloc
#include<string.h> //strcmp
#include"my_struct.h" //����� �ڷ���
#define _CRT_SECURE_NO_WARINGS //scanf ���� ���� ���� ������ ���� ����

//�Լ� user_del�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void user_del(user* u_head, rent* r_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	user* p = NULL; 
	rent* r_p = NULL; 
	p = u_head->next; 
	r_p = r_head->next;

	char id[10]; //���� ����

	printf("�����ڸ� �����մϴ�.\n");
	printf("�����ϰ���� id�� �Է����ּ���: "); scanf("%s", id);

	//�Է��� id�� �뿩�� ������ �ִ��� ������ Ȯ���ϴ� ����
	while (r_p->next != NULL) {
		if (strcmp(r_p->user_id, id) == 0) {
			printf("�뿩�� ������ �ֽ��ϴ�. �ݳ��� �Ϸ��ϰ� �ٽ� �õ��ϼ���\n");
			return 0;
		}
		r_p = r_p->next;
	}
	//�Է��� id�� �ִ��� Ȯ���ϴ� ����
	while (p->next != NULL) {
		if (strcmp(p->user_id, id) == 0) {
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("�����ϰ���� id�� �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
	}
	else {
		printf("������ �̸�: %s, ������ id: %s�� �����մϴ�.\n", p->user_name, p->user_id);

		//p�� ����Ű�� ��� �翷�� �ִ� ���� ����
		p->prev->next = p->next; 
		p->next->prev = p->prev;

		// p->user_name, p->user_id, p �޸� ����
		free(p->user_name); 
		free(p->user_id); 
		free(p);
	}
	user_store(u_head); //user_store �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
}

//�Լ� video_del�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void video_del(video* v_head, rent* r_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	video* p = NULL;
	rent* r_p = NULL; 
	p = v_head->next; 
	r_p = r_head->next;

	char title[30]; //���� ����

	printf("������ �����մϴ�.\n");
	printf("�����ϰ���� ���� ������ �Է����ּ���: "); scanf("%s", title);

	//�Է��� title�� �뿩�Ȱ� �ִ��� Ȯ���ϴ� ����
	while (r_p->next != NULL) {
		if (strcmp(r_p->video_title, title) == 0) {
			printf("�뿩�� ������ �ֽ��ϴ�. �ݳ��� �Ϸ��ϰ� �ٽ� �õ��ϼ���\n");
			return 0;
		}
		r_p = r_p->next;
	}
	//�Է��� title�� �ִ��� Ȯ���ϴ� ����
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("�����ϰ���� ������ �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
	}
	else {
		printf("���� ����: %s, ���� ���: %d�� �����մϴ�.\n", p->video_title, p->stock);

		//p�� ����Ű�� ��� �翷�� �ִ� ���� ����
		p->prev->next = p->next; 
		p->next->prev = p->prev;

		//p->video_title, p �޸� ����
		free(p->video_title);
		free(p);
	}
	video_store(v_head); //video_store �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
}

//�Լ� return_complete�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void return_complete(rent* r_head, video* v_head, user* u_head, rent* return_tail, rent* return_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	rent* p = NULL; 
	user* id_p = NULL; 
	video* title_p = NULL; 
	p = r_head->next; 
	id_p = u_head->next; 
	title_p = v_head->next;

	//���� ����
	char id[10]; 
	char title[30]; 

	printf("�����ڰ� ������ �ݳ��մϴ�.\n");
	printf("������ id�� �Է����ּ���: "); scanf("%s", id);

	//�Է��� id�� �ִ��� Ȯ���ϴ� ����
	while (id_p->next != NULL) {
		if (strcmp(id_p->user_id, id) == 0) {
			printf("id�� Ȯ�εǾ����ϴ�.\n");
			break;
		}
		id_p = id_p->next;
	}
	if (id_p->next == NULL) {
		printf("�Է��Ͻ� id�� �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
		return 0;
	}

	printf("�ݳ��ϰ���� ���� ������ �Է����ּ���: "); 
	scanf("%s", title);

	//�Է��� title�� �ִ��� Ȯ���ϴ� ����
	while (title_p->next != NULL) {
		if (strcmp(title_p->video_title, title) == 0) {
			(title_p->stock)++;
			break;
		}
		title_p = title_p->next;
	}
	if (title_p->next == NULL) {
		printf("�ݳ��ϰ���� ���� ������ �����ϴ�. �ٽ� �õ����ּ���.\n");
		return 0;
	}

	//�ݳ��ϴ� ����
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			break;
		}
		p = p->next;
	}
	printf("%s�� %s�� �ݳ��մϴ�.\n", p->user_id, p->video_title);

	//p�� ����Ű�� ��� �翷�� �ִ� ���� ����
	p->prev->next = p->next; 
	p->next->prev = p->prev;
	//free(p->video_title); free(p->user_id); free(p->rent_date); free(p->return_date); free(p); //p->video_title, p->user_id, p->rent_date, p->return_date, p �޸� ����
	//rent_store(r_head); //rent_store �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
	return &p;
}

//�Լ� user_all_del�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void user_all_del(user* u_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	user* p = NULL; 
	p = u_head->next;

	//�ʱ�ȭ ����
	while (p->next != NULL) {

		//p�� ����Ű�� ��� �翷�� �ִ� ���� ����
		p->prev->next = p->next; 
		p->next->prev = p->prev;

		//p->user_id, p->user_name, p �޸� ����
		free(p->user_id); 
		free(p->user_name); 
		free(p);

		p = u_head->next; //�����ͺ��� p�� u_head->next�� ����Ų��.
	}
	printf("�������� ������ �ʱ�ȭ�մϴ�.\n");
	user_store(u_head); //user_store �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
}

//�Լ� video_all_del�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void video_all_del(video* v_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	video* p = NULL; 
	p = v_head->next;

	//�ʱ�ȭ ����
	while (p->next != NULL) {

		//p�� ����Ű�� ��� �翷�� �ִ� ���� ����
		p->prev->next = p->next; 
		p->next->prev = p->prev;

		//p->video_title, p �޸� ����
		free(p->video_title); 
		free(p);

		p = v_head->next; //�����ͺ��� p�� v_head->next�� ����Ų��.
	}
	printf("������ ������ �ʱ�ȭ�մϴ�.\n");
	video_store(v_head); //video_store �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
}

//�Լ� rent_all_del�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void rent_all_del(rent* r_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	rent* p = NULL; 
	p = r_head->next;

	//�ʱ�ȭ ����
	while (p->next != NULL) {

		//p�� ����Ű�� ��� �翷�� �ִ� ���� ����
		p->prev->next = p->next; 
		p->next->prev = p->prev;

		//p->user_id, p->video_title, p->rent_date, p->return_date, p �޸� ����
		free(p->user_id); 
		free(p->video_title); 
		free(p->rent_date); 
		free(p->return_date); 
		free(p);

		p = r_head->next; //�����ͺ��� p�� r_head->next�� ����Ų��.
	}
	printf("�뿩�� �������� ������ �ʱ�ȭ�մϴ�.\n");
	rent_store(r_head); //rent_store �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
}