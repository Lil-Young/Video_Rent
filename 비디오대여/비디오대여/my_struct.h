#pragma once
//사용할 구조체
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
//삽입(추가) 기능
void user_insert(user* u_tail, user* u_head); //회원을 추가한다.
void video_insert(video* v_tail, video* v_head); //비디오를 추가한다.
void rent_insert(rent* r_tail, video* v_head, user* u_head, rent* r_head);//대여정보를 추가한다.

//삭제 기능
void user_del(user* u_head, rent* r_head); //회원을 삭제한다.
void video_del(video* v_head, rent* r_head); //비디오를 삭제한다.
void return_complete(rent* r_head, video* v_head, user* u_head, rent* return_tail, rent* return_head); //반납(대여정보에서삭제)을 하고 반납정보에 추가한다.
void user_all_del(user* u_head); //모든 회원을 삭제한다.
void video_all_del(video* v_head); //모든 비디오를 삭제한다.
void rent_return_all_del(rent* r_head, rent* return_head); //모든 대여정보와 반납정보를 삭제한다.

//읽기 기능
void user_video_show(video* v_head); //대여가능한 비디오를 보여준다.
void all_video_show(video* v_head); //모든 비디오를 보여준다.
void user_show(user* u_head); //모든 회원을 보여준다.
void rent_show(rent* r_head); //모든 대여정보를 보여준다.
void delayed_date(rent* r_head); //반납날짜각 지난 대여정보들을 보여준다.
void return_show(rent* return_head); //반납정보를 보여준다.

//검색 기능
void user_find(user* u_head); //회원을 검색한다.
void video_find(video* v_head); //비디오를 검색한다.
void rent_user_find(rent* r_head); //대여정보를 검색한다.

//수정 기능
void id_update(user* u_head, rent* r_head); //회원의 id를 수정한다.
void stock_update(video* v_head); //비디오 재고를 수정한다.
void return_update(rent* r_head); //대여정보에 있는 반납날짜를 수정한다.

//저장 기능
void user_store(user* u_head); //회원정보를 저장한다.
void video_store(video* v_head); //비디오정보를 저장한다.
void rent_store(rent* r_head); //대여정보를 저장한다.
void return_store(rent* return_head); //반납정보를 저장한다.

//불러오기 기능
void user_open(user* u_tail); //회원정보를 불러온다.
void video_open(video* v_tail); //비디오정보를 불러온다.
void rent_open(rent* r_tail); //대여정보를 불러온다.
void return_open(rent* return_tail); //반납정보를 불러온다.
