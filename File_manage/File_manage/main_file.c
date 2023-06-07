#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct {
    char fileName[50];
    char fileContent[100];
} File;

void addFile(File* files, int* fileCount) {
    File newFile;
    printf("파일 이름을 입력하세요: ");
    scanf("%s", newFile.fileName);
    printf("파일 내용을 입력하세요: ");
    scanf("%s", newFile.fileContent);

    files[*fileCount] = newFile;
    (*fileCount)++;

    printf("파일이 추가되었습니다.\n");
}

void deleteFile(File* files, int* fileCount) {
    int i, fileIndex;
    printf("삭제할 파일의 번호를 입력하세요: ");
    scanf("%d", &fileIndex);

    if (fileIndex >= 1 && fileIndex <= *fileCount) {
        printf("파일 '%s'을(를) 삭제합니다.\n", files[fileIndex - 1].fileName);

        for (i = fileIndex - 1; i < *fileCount - 1; i++) {
            files[i] = files[i + 1];
        }

        (*fileCount)--;
    }
    else {
        printf("잘못된 파일 번호입니다.\n");
    }
}

void modifyFile(File* files, int fileCount) {
    int fileIndex;
    printf("수정할 파일의 번호를 입력하세요: ");
    scanf("%d", &fileIndex);

    if (fileIndex >= 1 && fileIndex <= fileCount) {
        printf("파일 '%s'의 내용을 수정합니다.\n", files[fileIndex - 1].fileName);
        printf("새로운 파일 내용을 입력하세요: ");
        scanf("%s", files[fileIndex - 1].fileContent);
        printf("파일이 수정되었습니다.\n");
    }
    else {
        printf("잘못된 파일 번호입니다.\n");
    }
}

void searchFile(File* files, int fileCount) {
    char keyword[50];
    int i, found = 0;

    printf("검색할 키워드를 입력하세요: ");
    scanf("%s", keyword);

    printf("검색 결과:\n");

    for (i = 0; i < fileCount; i++) {
        if (strstr(files[i].fileName, keyword) != NULL || strstr(files[i].fileContent, keyword) != NULL) {
            printf("파일 이름: %s\n", files[i].fileName);
            printf("파일 내용: %s\n", files[i].fileContent);
            found = 1;
        }
    }

    if (!found) {
        printf("검색 결과가 없습니다.\n");
    }
}

void setPassword(int* password) {
    int newPassword;

    printf("새로운 비밀번호를 입력하세요: ");
    scanf("%d", &newPassword);

    *password = newPassword;

    printf("비밀번호가 성공적으로 설정되었습니다.\n");
}

void printFileList(File* files, int fileCount) {
    int i;

    printf("==== 파일 목록 ====\n");

    for (i = 0; i < fileCount; i++) {
        printf("%d. %s\n", i + 1, files[i].fileName);
    }
}

void viewFileContent(File* files, int fileCount) {
    int fileIndex;

    printf("내용을 확인할 파일의 번호를 입력하세요: ");
    scanf("%d", &fileIndex);

    if (fileIndex >= 1 && fileIndex <= fileCount) {
        printf("파일 이름: %s\n", files[fileIndex - 1].fileName);
        printf("파일 내용: %s\n", files[fileIndex - 1].fileContent);
    }
    else {
        printf("잘못된 파일 번호입니다.\n");
    }
}

int main() {
    File files[100];
    int fileCount = 0;
    int password = 1234;
    int loggedIn = 0;
    int choice;

    while (1) {
        printf("===== 파일 관리 프로그램 =====\n");
        printf("1. 파일 추가\n");
        printf("2. 파일 삭제\n");
        printf("3. 파일 수정\n");
        printf("4. 파일 검색\n");
        printf("5. 비밀번호 설정\n");
        printf("6. 파일 목록 출력\n");
        printf("7. 파일 내용 확인\n");
        printf("8. 로그인\n");
        printf("9. 로그아웃\n");
        printf("10. 종료\n");
        printf("=============================\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (loggedIn) {
                addFile(files, &fileCount);
            }
            else {
                printf("로그인이 필요합니다.\n");
            }
            break;
        case 2:
            if (loggedIn) {
                deleteFile(files, &fileCount);
            }
            else {
                printf("로그인이 필요합니다.\n");
            }
            break;
        case 3:
            if (loggedIn) {
                modifyFile(files, fileCount);
            }
            else {
                printf("로그인이 필요합니다.\n");
            }
            break;
        case 4:
            if (loggedIn) {
                searchFile(files, fileCount);
            }
            else {
                printf("로그인이 필요합니다.\n");
            }
            break;
        case 5:
            if (loggedIn) {
                setPassword(&password);
            }
            else {
                printf("로그인이 필요합니다.\n");
            }
            break;
        case 6:
            if (loggedIn) {
                printFileList(files, fileCount);
            }
            else {
                printf("로그인이 필요합니다.\n");
            }
            break;
        case 7:
            if (loggedIn) {
                viewFileContent(files, fileCount);
            }
            else {
                printf("로그인이 필요합니다.\n");
            }
            break;
        case 8:
            if (loggedIn) {
                printf("이미 로그인되어 있습니다.\n");
            }
            else {
                int inputPassword;
                printf("비밀번호를 입력하세요: ");
                scanf("%d", &inputPassword);
                if (inputPassword == password) {
                    loggedIn = 1;
                    printf("로그인되었습니다.\n");
                }
                else {
                    printf("비밀번호가 일치하지 않습니다.\n");
                }
            }
            break;
        case 9:
            if (loggedIn) {
                loggedIn = 0;
                printf("로그아웃되었습니다.\n");
            }
            else {
                printf("이미 로그아웃되어 있습니다.\n");
            }
            break;
        case 10:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 메뉴 번호입니다.\n");
        }
    }

    return 0;
}
