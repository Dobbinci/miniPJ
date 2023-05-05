#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alumni {
	char name[30];
	char email[30];
    char jobName[30];
	char career[30];
	char academicBackground[30];
	char residence[30];
    int jobFeature;
	int majorFeature;
} Alumni;


void displayByJob(Alumni *s[], int num);
void displayByMajor(Alumni *s[], int num);
int createData(Alumni *s[], int num);
void readData(Alumni *s[], int num);
int updateData(Alumni *s[], int num);
int deleteData(Alumni *s[], int num);
void printAllData(Alumni *s[], int index);
int saveData(Alumni *s[], int num);
int loadData(Alumni *s[]);
//list: feature of job
void jobFeatureList() {
    printf("========직종별 카테고리=========\n");
    printf("1.경영  2.마케팅  3.IT  4.디자인  5.서비스  6.연구직  7.교육  8.미디어  9.예술\n");
}
//list: feature of mojor
void majorFeatureList() {
    printf("========전공별 카테고리=========\n");
    printf("1.경영  2.마케팅  3.IT  4.디자인  5.서비스  6.연구직  7.교육  8.미디어  9.예술\n");
}
//showing menu
int selectMenu(){
    int menu;
    printf("\n--동문 아카이브--\n");
    printf("1. 직종별 조회\n");
    printf("2. 전공별 조회\n");
    printf("3. 모든 동문 조회\n");
    printf("4. 프로필 생성\n");
    printf("5. 프로필 수정\n");
    printf("6. 프로필 삭제\n");
    printf("7. 저장\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴를 선택하세요: ");
    scanf("%d", &menu);
    return menu;
}

int main() {
    Alumni *alumniDB[20];
    for(int i=0; i<20; i++){
        alumniDB[i] = (Alumni *)malloc(sizeof(Alumni));
    }
    int num = -1; //number of data-1
    int result;
    int menu;
    int userEnterData = 0;
    num = loadData(alumniDB);
    while (1){
        result = 0;
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1 && (userEnterData == 1 || num >= 0)){
            displayByJob(alumniDB, num);
        }
        if (menu == 2 && (userEnterData == 1 || num >= 0)){
            displayByMajor(alumniDB, num);
        }
        if (menu == 3 && (userEnterData == 1 || num >= 0)){
            printAllData(alumniDB, num);
        }
        if (menu == 4){
            if(userEnterData == 0){
                num++;
                result = createData(alumniDB, num);
                if (result==1){
                    printf("=> 입력이 완료 되었습니다!\n");
                }
                userEnterData++;       
            }
            else {
                printf("이미 프로필을 생성하셨습니다\n");
            }    
        }
        if (menu == 5 && (userEnterData == 1 || num >= 0)){
            result = updateData(alumniDB, num);
            if (result==1) printf("=> 데이터가 수정 되었습니다!\n");
        }
        if (menu == 6 && (userEnterData == 1 || num >= 0)){
            result = deleteData(alumniDB, num);
            if (result==1){
                userEnterData = 0;
                num--;
                printf("=> 데이터가 삭제 되었습니다!\n");
            } 
        }
        if (menu == 7){
            result = saveData(alumniDB, num);
            if (result==1) printf("데이터가 저장되었습니다!\n");
        }
    }
    printf("종료됨!\n");
    return 0;
}

//display data by feature of job
void displayByJob(Alumni *s[], int num) {
    jobFeatureList();
    int jobFeature;
    printf("원하는 카테고리를 입력하세요: ");
    scanf("%d", &jobFeature);
    for (int i=0; i<=num; i++) {
        if (s[i]->jobFeature == jobFeature) {
            readData(s, i);
        }
    }
}
//display data by feature of major
void displayByMajor(Alumni *s[], int num) {
    majorFeatureList();
    int majorFeature;
    printf("원하는 카테고리를 입력하세요: ");
    scanf("%d", &majorFeature);
    for (int i=0; i<=num; i++) {
        if (s[i]->majorFeature == majorFeature) {
            printf("debug\n");
            readData(s, i);
        }
    }
}
//Create
int createData(Alumni *s[], int num){
    printf("이름을 입력해주세요: ");
    scanf("%s", s[num]->name);
    printf("이메일을 입력해주세요: ");
    scanf("%s", s[num]->email);
    printf("현재 직업을 입력해주세요: ");
    scanf("%s", s[num]->jobName);
    printf("%s님의 어필하고 싶은 커리어 이력 하나를 적어주세요:",s[num]->name);
    getchar();
    scanf("%s", s[num]->career);
    printf("%s님의 최종 학력을 적어주세요:",s[num]->name);
    scanf("%s", s[num]->academicBackground);
    printf("현재 어느 도시에 거주하고 계신가요? ");
    scanf("%s", s[num]->residence);
    jobFeatureList();
    printf("자신의 전문 분야를 선택해주세요: ");
    scanf("%d", &s[num]->jobFeature);
    majorFeatureList();
    printf("마지막으로, 자신의 전공 분야를 선택해주세요: ");
    getchar();
    scanf("%d", &s[num]->majorFeature);
    return 1;
}

//print every data
void printAllData(Alumni *s[], int num){
    for(int i=0; i<=num; i++){
        printf("No  이름        이메일         직업\n");
        printf("------------------------------------\n");
        printf("%d  %s   %s    %s\n", i+1, s[i]->name, s[i]->email, s[i]->jobName);
        printf("    --------------------------------\n");
        printf("    경력: %s\n", s[i]->career);
        printf("    학력: %s\n", s[i]->academicBackground);
        printf("jobFeature: %d majorFeature: %d\n", s[i]->jobFeature, s[i]->majorFeature);
        printf("====================================\n");
    }
}   

//read a given data
void readData(Alumni *s[], int index){
    printf("No  이름        이메일         직업\n");
    printf("------------------------------------\n");
    printf("%d  %s   %s    %s\n", index+1, s[index]->name, s[index]->email, s[index]->jobName);
    printf("    --------------------------------\n");
    printf("    경력: %s\n", s[index]->career);
    printf("    학력: %s\n", s[index]->academicBackground);
    printf("====================================\n");
} 

//Update
int updateData(Alumni *s[], int num){
    char updateName[30];
    int updateNum;
    printf("성함을 입력해주세요: ");
    scanf("%s", updateName);
    for (int i=0; i<=num; i++){
        if (strstr(s[i]->name, updateName)){
            updateNum = i;
            break;
        }
    }
    createData(s, updateNum);
    return 1;
}

//Delete
int deleteData(Alumni *s[], int num){
    char deleteName[30];
    int deleteNum;
    int choice;

    printf("성함을 입력해주세요: ");
    scanf("%s", deleteName);
    printf("정말로 삭제하시겠어요?(삭제: 1, 취소: 아무 숫자)");
    scanf("%d", &choice);
    if (choice == 1){
        for (int i=0; i<=num; i++){
            if (strstr(s[i]->name, deleteName)){
                deleteNum = i;
                break;
            }
        }
        for (int i=deleteNum; i<num; i++){ //move data from back to front in order to remove one data
                s[i] = s[i+1];
        }
        return 1;
    }
    else return 0; 
}

//Save
int saveData(Alumni *s[], int num){
    FILE *fp;
    char filename[] = "AlumniDB.txt";
    fp = fopen(filename, "w");
    for (int i=0; i<=num; i++){
        if(i == num) fprintf(fp, "%s  %s   %s   %s   %s  %s  %d %d", s[i]->name, s[i]->email, s[i]->jobName, s[i]->career, s[i]->academicBackground, s[i]->residence, s[i]->jobFeature, s[i]->majorFeature); //last data do not have to contain \n
        else fprintf(fp, "%s  %s   %s   %s   %s  %s %d %d\n", s[i]->name, s[i]->email, s[i]->jobName, s[i]->career, s[i]->academicBackground, s[i]->residence, s[i]->jobFeature, s[i]->majorFeature);
    }
    fclose(fp);
    return 1;
}
//load file
int loadData(Alumni *s[]){
    int num = -1; //number of data
    FILE *fp;
    fp = fopen("AlumniDB.txt", "r");
    if(fp == NULL){
        printf("파일 없음");
        return -1;
    }
    else {
        for(int i=0; i<20; i++){
            if(feof(fp)) break;   //count number of data
            fscanf(fp, "%s  %s   %s   %s   %s  %s %d %d", s[i]->name, s[i]->email, s[i]->jobName, s[i]->career, s[i]->academicBackground, s[i]->residence, &s[i]->jobFeature, &s[i]->majorFeature);
            num++;  
        }
        fclose(fp);
        printf("로딩성공");
        return num;
    }
}