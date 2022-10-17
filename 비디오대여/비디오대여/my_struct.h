#pragma once
//����� ����ü
typedef struct User {
	char* user_id;
	char* user_name;
	struct User* next;
	struct User* prev;
}user;

typedef struct Video {
	char* video_title;
	int stock;
	struct Video* next;
	struct Video* prev;
}video;

typedef struct Rent {
	char* video_title;
	char* user_id;
	char* rent_date;
	char* return_date;
	struct Rent* next;
	struct Rent* prev;
}rent;
//����(�߰�) ���
void user_insert(user* u_tail, user* u_head); //ȸ���� �߰��Ѵ�.
void video_insert(video* v_tail, video* v_head); //������ �߰��Ѵ�.
void rent_insert(rent* r_tail, video* v_head, user* u_head, rent* r_head);//�뿩������ �߰��Ѵ�.

//���� ���
void user_del(user* u_head, rent* r_head); //ȸ���� �����Ѵ�.
void video_del(video* v_head, rent* r_head); //������ �����Ѵ�.
void return_complete(rent* r_head, video* v_head, user* u_head, rent* return_tail, rent* return_head); //�ݳ�(�뿩������������)�� �ϰ� �ݳ������� �߰��Ѵ�.
void user_all_del(user* u_head); //��� ȸ���� �����Ѵ�.
void video_all_del(video* v_head); //��� ������ �����Ѵ�.
void rent_return_all_del(rent* r_head, rent* return_head); //��� �뿩������ �ݳ������� �����Ѵ�.

//�б� ���
void user_video_show(video* v_head); //�뿩������ ������ �����ش�.
void all_video_show(video* v_head); //��� ������ �����ش�.
void user_show(user* u_head); //��� ȸ���� �����ش�.
void rent_show(rent* r_head); //��� �뿩������ �����ش�.
void delayed_date(rent* r_head); //�ݳ���¥�� ���� �뿩�������� �����ش�.
void return_show(rent* return_head); //�ݳ������� �����ش�.

//�˻� ���
void user_find(user* u_head); //ȸ���� �˻��Ѵ�.
void video_find(video* v_head); //������ �˻��Ѵ�.
void rent_user_find(rent* r_head); //�뿩������ �˻��Ѵ�.

//���� ���
void id_update(user* u_head, rent* r_head); //ȸ���� id�� �����Ѵ�.
void stock_update(video* v_head); //���� ��� �����Ѵ�.
void return_update(rent* r_head); //�뿩������ �ִ� �ݳ���¥�� �����Ѵ�.

//���� ���
void user_store(user* u_head); //ȸ�������� �����Ѵ�.
void video_store(video* v_head); //���������� �����Ѵ�.
void rent_store(rent* r_head); //�뿩������ �����Ѵ�.
void return_store(rent* return_head); //�ݳ������� �����Ѵ�.

//�ҷ����� ���
void user_open(user* u_tail); //ȸ�������� �ҷ��´�.
void video_open(video* v_tail); //���������� �ҷ��´�.
void rent_open(rent* r_tail); //�뿩������ �ҷ��´�.
void return_open(rent* return_tail); //�ݳ������� �ҷ��´�.
