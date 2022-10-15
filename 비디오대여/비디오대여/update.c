#include<stdio.h> //printf, scanf
#include<stdlib.h> //free, malloc
#include<string.h> //strcpy, strlen
#include"my_struct.h" //����� �ڷ���
#define _CRT_SECURE_NO_WARINGS //scanf ���� ���� ���� ������ ���� ����

//�Լ� id_update�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void id_update(user* u_head, rent* r_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	user* u_p = NULL; 
	user* uf_p = NULL; 
	rent* r_p = NULL; 
	u_p = u_head->next; 
	uf_p = u_head->next; 
	r_p = r_head->next;

	//���� ����
	char id[1000];
	char update_id[1000];

	printf("ȸ���� id�� ������Ʈ�մϴ�.\n");
	printf("������ id�� �Է����ּ���: "); 
	scanf("%s", id);

	//�Է��� id�� �ִ��� Ȯ���ϴ� ����
	while (u_p->next != NULL) {
		if (strcmp(u_p->user_id, id) == 0) {
			printf("id�� Ȯ�εǾ����ϴ�.\n");
			break;
		}
		u_p = u_p->next;
	}
	if (u_p->next == NULL) {
		printf("�Է��Ͻ� id�� �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
		return 0;
	}

	printf("�����ϰ���� id�� �Է����ּ���: "); 
	scanf("%s", update_id);

	//�Է��� id�� �ߺ��Ǵ��� Ȯ���ϴ� ����
	while (uf_p->next != NULL) {
		if (strcmp(uf_p->user_id, update_id) == 0) {
			printf("�Է��� id�� �̹� �����մϴ�. �ٽ� �õ����ּ���.\n");
			return 0;
		}
		uf_p = uf_p->next;
	}
	free(u_p->user_id); //u_p->user_id �޸� ����
	u_p->user_id = (char*)malloc(sizeof(char) * strlen(update_id) + 1); //u_p->user_id �޸� �Ҵ�
	strcpy(u_p->user_id, update_id); //strcpy�� update_id�� �ִ� ���ڿ��� u_p->user_id�� ����

	//user�� user_id�� ������Ʈ�����Ƿ� rent�� user_id�� ������Ʈ
	while (r_p->next != NULL) {
		if (strcmp(r_p->user_id, id) == 0) {
			free(r_p->user_id); //r_p->user_id �޸� ����
			r_p->user_id = (char*)malloc(sizeof(char) * strlen(update_id) + 1); //r_p->user_id �޸� �Ҵ�
			strcpy(r_p->user_id, update_id); //strcpy�� update_id�� �ִ� ���ڿ��� r_p->user_id�� ����
		}
		r_p = r_p->next;
	}

	printf("id�� ����Ǿ����ϴ�.\n");
	user_store(u_head); //user_store �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
	rent_store(r_head); //rent_store �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
}

//�Լ� stock_update�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void stock_update(video* v_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	video* p = NULL; 
	p = v_head->next;

	//���� ����
	char title[1000];
	int update_stock; 
	int temp;

	printf("������ ��� ������Ʈ�մϴ�.\n");
	printf("�����ϰ���� ����� ���� ������ �Է��ϼ���: "); scanf("%s", title);

	//�Է��� title�� �ִ��� Ȯ���ϴ� ����
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("������ Ȯ�εǾ����ϴ�.\n");
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("�Է��Ͻ� ������ �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
		return 0;
	}

	printf("��� �߰� �Ǵ� ���̷��� ������ �Է����ּ���: "); 
	scanf("%d", &update_stock);
	temp = p->stock;
	p->stock += update_stock; //p->stock = p->stock + update_stock
	if (p->stock < 0) {
		p->stock = temp;
		printf("��� 0 �̸��Դϴ�. �ٽ� �õ����ּ���.\n");
		return 0;
	}

	printf("��� ����Ǿ����ϴ�.\n");
	video_store(v_head); //video_store �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
}

//�Լ� return_update�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void return_update(rent* r_head) {

	//�����ͺ��� ���� �� �ʱ�ȭ
	rent* p = NULL; 
	p = r_head->next;

	//���� ����
	int cnt = 0; 
	char id[1000];
	char title[1000];
	char update_return[1000];

	printf("�ݳ���¥�� ������Ʈ�մϴ�.\n");
	printf("�뿩�� ȸ���� id�� �Է����ּ���: "); 
	scanf("%s", id);

	//�Է��� id�� ���� ���� ����� ������ �������� �����ִ� ����
	while (p->next != NULL) {
		if (strcmp(p->user_id, id) == 0) {
			cnt++;
			printf("ȸ�� id: %s, ���� ����: %s, �뿩��¥: %s, �ݳ���¥: %s\n"
				, p->user_id, p->video_title, p->rent_date, p->return_date);
		}
		p = p->next;
	}
	if (cnt == 0) {
		printf("�뿩�� ȸ���� id�� �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
		return 0;
	}

	p = r_head->next;
	printf("�����ϰ���� �ݳ���¥�� ���� ������ �Է����ּ���: "); 
	scanf("%s", title);

	//�Է��� title�� �ִ��� Ȯ���ϴ� ����
	while (p->next != NULL) {
		if (strcmp(p->video_title, title) == 0) {
			printf("������ Ȯ�εǾ����ϴ�.\n");
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("�Է��Ͻ� ������ �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n");
		return 0;
	}

	printf("�����ϰ���� �ݳ���¥�� �Է����ּ���: "); 
	scanf("%s", update_return);
	free(p->return_date); //p->return_date �޸� ����
	p->return_date = (char*)malloc(sizeof(char) * strlen(update_return) + 1); //p->return_date �޸� �Ҵ�
	strcpy(p->return_date, update_return); //strcpy�� update_return�� �ִ� ���ڿ��� p->return_date�� ����
	printf("�ݳ���¥�� ����Ǿ����ϴ�.\n");
	rent_store(r_head); //rent_store �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
}