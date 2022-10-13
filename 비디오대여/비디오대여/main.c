#include<stdio.h> //printf, scanf, getchar
#include<stdlib.h> //malloc
#include"my_struct.h" //사용할 자료형
#define _CRT_SECURE_NO_WARINGS //scanf 보안 경고로 인한 컴파일 에러 방지
/*
* printf는 문자열을 출력하는 함수
* return 0은 함수를 종료한다.
* break는 반복문을 탈출시킨다 또한 switch문을 탈출시킨다.
*/
int main(void) {

	//변수와 포인터변수 선언 및 초기화
	int select = 0; 
	int func = 0;
	user* u_head = NULL; user* u_tail = NULL;
	video* v_head = NULL; video* v_tail = NULL;
	rent* r_head = NULL; rent* r_tail = NULL;
	rent* return_head = NULL; rent* return_tail = NULL;
	rent* pointer_val;

	//head, tail 메모리할당
	u_head = (user*)malloc(sizeof(user)); u_tail = (user*)malloc(sizeof(user));
	v_head = (video*)malloc(sizeof(video)); v_tail = (video*)malloc(sizeof(video));
	r_head = (rent*)malloc(sizeof(rent)); r_tail = (rent*)malloc(sizeof(rent));
	return_head = (rent*)malloc(sizeof(rent)); return_tail = (rent*)malloc(sizeof(rent));

	//head 초기화
	u_head->next = NULL; u_head->prev = NULL; u_head->user_id = NULL; u_head->user_name = NULL;
	v_head->next = NULL; v_head->prev = NULL; v_head->video_title = NULL;
	r_head->next = NULL; r_head->prev = NULL; r_head->video_title = NULL; r_head->user_id = NULL; r_head->rent_date = NULL; r_head->return_date = NULL;
	return_head->next = NULL; return_head->prev = NULL; return_head->video_title = NULL; return_head->user_id = NULL; return_head->rent_date = NULL; return_head->return_date = NULL;

	//tail 초기화
	u_tail->next = NULL; u_tail->prev = NULL; u_tail->user_id = NULL; u_tail->user_name = NULL;
	v_tail->next = NULL; v_tail->prev = NULL; v_tail->video_title = NULL;
	r_tail->next = NULL; r_tail->prev = NULL; r_tail->video_title = NULL; r_tail->user_id = NULL; r_tail->rent_date = NULL; r_tail->return_date = NULL;
	return_tail->next = NULL; return_tail->prev = NULL; return_tail->video_title = NULL; return_tail->user_id = NULL; return_tail->rent_date = NULL; return_tail->return_date = NULL;

	//head, tail 연결
	u_head->next = u_tail; u_head->prev = NULL; u_tail->next = NULL; u_tail->prev = u_head;
	v_head->next = v_tail; v_head->prev = NULL; v_tail->next = NULL; v_tail->prev = v_head;
	r_head->next = r_tail; r_head->prev = NULL; r_tail->next = NULL; r_tail->prev = r_head;
	return_head->next = return_tail; return_head->prev = NULL; return_tail->next = NULL; return_tail->prev = return_head;

	//파일 불러오기
	user_open(u_tail); //user_open 함수를 호출하고 인자들을 전달한다.
	video_open(v_tail); //video_open 함수를 호출하고 인자들을 전달한다.
	rent_open(r_tail); //rent_open 함수를 호출하고 인자들을 전달한다.
	return_open(return_tail); //return_open 함수를 호출하고 인자들을 전달한다.

	//모드 선택 및 기능 선택
	while (1) {
		printf("사용하고싶은 모드를 선택해주세요.\n");
		printf("사용자 모드: 1, 관리자 모드: 2 :");
		int select = 0;
		scanf("%d", &select);
		while (getchar() != '\n');
		if (select == 1) {
			printf("사용자 모드를 실행합니다.\n");
			printf("기능 -> 0: 뒤로가기. 1: 비디오를 대여합니다. 2: 대여 가능한 비디오를 보여줍니다. 3: 비디오를 반납합니다. 4: 비디오를 검색합니다.\n");
			while (1) {
				printf("수행할 기능을 입력해주세요: ");
				scanf("%d", &func);
				while (getchar() != '\n');
				if (func == 0) {
					break;
				}
				switch (func) {
				case 1:
					rent_insert(r_tail, v_head, u_head, r_head); //rent_insert 함수를 호출하고 인자들을 전달한다.
					break;
				case 2:
					user_video_show(v_head); //video_show 함수를 호출하고 인자들을 전달한다.
					break;
				case 3:
					pointer_val = return_complete(r_head, v_head, u_head); //return_complete 함수를 호출하고 인자들을 전달한다.
					printf("p의 주소값 : %s\n", pointer_val->user_id);
					return_insert(return_tail, return_head, pointer_val);
					break;
				case 4:
					video_find(v_head); //video_find 함수를 호출하고 인자들을 전달한다.
					break;
				default:
					printf("잘못 입력했습니다. 기능을 다시입력하세요.\n");
				}
			}
		}
		else if (select == 2) {
			printf("관리자 모드를 실행합니다.\n");
			printf("기능 -> 0: 뒤로가기. 1: 가입자를 추가합니다. 2: 비디오를 추가합니다. 3: 가입자를 보여줍니다. 4: 모든 비디오를 보여줍니다. 5: 대여한 가입자의 정보를 보여줍니다. 6: 비디오의 반납날짜가 지난 가입자의 정보를 보여줍니다. 7: 가입자를 삭제합니다. 8: 비디오를 삭제합니다. 9: 가입자를 검색합니다. 10: 비디오를 검색합니다. 11: 대여한 가입자의 정보를 보여줍니다. 12: 가입자의 id를 업데이트 합니다. 13: 비디오의 재고를 업데이트 합니다. 14: 반납날짜를 업데이트합니다. 15: 가입자의 모든 정보를 초기화합니다. 16: 비디오의 모든 정보를 초기화합니다. 17: 대여한 가입자의 정보를 초기화합니다.\n");
			while (1) {
				printf("수행할 기능을 입력해주세요: ");
				scanf("%d", &func);
				while (getchar() != '\n');
				if (func == 0) {
					break;
				}
				switch (func) {
				case 1:
					user_insert(u_tail, u_head); //user_insert 함수를 호출하고 인자들을 전달한다.
					break;
				case 2:
					video_insert(v_tail, v_head); //video_insert 함수를 호출하고 인자들을 전달한다.
					break;
				case 3:
					user_show(u_head); //user_show 함수를 호출하고 인자들을 전달한다.
					break;
				case 4:
					all_video_show(v_head); //video_show 함수를 호출하고 인자들을 전달한다.
					break;
				case 5:
					rent_show(r_head); //rent_show 함수를 호출하고 인자들을 전달한다.
					break;
				case 6:
					delayed_date(r_head); //delayed_date 함수를 호출하고 인자들을 전달한다.
					break;
				case 7:
					user_del(u_head, r_head); //user_del 함수를 호출하고 인자들을 전달한다.
					break;
				case 8:
					video_del(v_head, r_head); //video_del 함수를 호출하고 인자들을 전달한다.
					break;
				case 9:
					user_find(u_head); //user_find 함수를 호출하고 인자들을 전달한다.
					break;
				case 10:
					video_find(v_head); //video_find 함수를 호출하고 인자들을 전달한다.
					break;
				case 11:
					rent_user_find(r_head); //rent_user_find 함수를 호출하고 인자들을 전달한다.
					break;
				case 12:
					id_update(u_head, r_head); //id_update 함수를 호출하고 인자들을 전달한다.
					break;
				case 13:
					stock_update(v_head); //stock_update 함수를 호출하고 인자들을 전달한다.
					break;
				case 14:
					return_update(r_head); //return_update 함수를 호출하고 인자들을 전달한다.
					break;
				case 15:
					user_all_del(u_head); //user_all_del 함수를 호출하고 인자들을 전달한다.
					break;
				case 16:
					video_all_del(v_head); //video_all_del 함수를 호출하고 인자들을 전달한다.
					break;
				case 17:
					rent_all_del(r_head); //rent_all_del 함수를 호출하고 인자들을 전달한다.
					break;
				default :
					printf("잘못 입력했습니다. 기능을 다시입력하세요.\n");
				}
			}
		}
		else {
			printf("잘못 입력했습니다. 모드를 다시 선택해주세요.\n");
		}
	}
}