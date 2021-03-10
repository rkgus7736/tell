#include <stdio.h>
#include <string.h>

struct tellNumber{
	char name[50];		
	char tell[50];
};

struct tellNumber arr[10];
int tIndex = 0;

//연락처 추가
void AddTellNumber(){
	 
	if(tIndex == 10){ 
		printf("더이상 저장할수없습니다\n");
		return; 

 	}
	printf("연락처 등록을 시작합니다");
	printf("이름 입력 :"); scanf("%s", arr[tIndex].name);
	printf("번호 입력 :"); scanf("%s", arr[tIndex].tell);
	tIndex++;
	 
}
//연락처 수정
void UpdateTellNumber(){
	char name[50];
	int i;
	printf(" 수정할 연락처의 이름을 입력하세요"); scanf("%s",name);
	for(i=0;i<tIndex;i++){
		if(strcmp(arr[i].name, name) == 0){
			printf("이름 : %s, 연락처 : %s\n", arr[i].name, arr[i].tell);
			return;
		}
	}
	printf("수정할 연락처가 없습니다\n");
}

//연락처 검색
void SearchTellNumber(){
	char name[50];
	printf("연락처에 저장된 이름 입력:\n");
	for(int i=0;i<tIndex;i++){
		if(strcmp(arr[i].name, name) == 0){
			printf("이름 : %s, 연락처 : %s\n",arr[i].name, arr[i].tell);
			return;
		}
	}
	printf("검색 결과가 없습니다.\n");
}

//연락처 삭제
void DeleteTellNumber(){
	
	char tell[50];
	printf("삭제할 연락처를 입력하세요. : ");
	scanf("%s", tell);
	int i;
	for(i=0;i<tIndex;i++){
		if(strcmp(arr[i].tell, tell) == 0){
			int j;
			for(j=i;j<tIndex-1;j++)
				arr[j] = arr[j+1];
			tIndex--;
			printf("입력한 연락처를 정상적으로 삭제했습니다");
			return;
		}
	}
	printf("삭제할 연락처가 없습니다\n");
}
//메뉴 번호 선택
enum{ INSERT, UPDATE, SEARCH, DELETE, OFF };

int main(void){

	const int num = 10;
	const int n1;

	printf("%d %d %d %d %d\n", INSERT, UPDATE, SEARCH, DELETE, OFF);
	int menu;
	printf("0. Insert\n");
	printf("1. Update\n");
	printf("2. Search\n");
	printf("3. Delete\n");
	printf("4. OFF\n");
	printf("메뉴번호를 입력해주세요. : "); scanf("%d",&menu);
	switch(menu){
	case INSERT :
		printf("연락처 추가\n");
		break;
	case UPDATE :
                printf("연락처 수정\n");
                break;
	case SEARCH :
                printf("연락처 검색\n");
                break;
	case DELETE :
                printf("연락처 삭제\n");
                break;
	case OFF :
		printf("프로그램 종료\n");
		break;	
	}
	return 0;
}
