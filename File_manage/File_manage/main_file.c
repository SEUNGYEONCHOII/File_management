#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct {
    char fileName[50];
    char fileContent[100];
} File;

void addFile(File* files, int* fileCount) {
    File newFile;
    printf("���� �̸��� �Է��ϼ���: ");
    scanf("%s", newFile.fileName);
    printf("���� ������ �Է��ϼ���: ");
    scanf("%s", newFile.fileContent);

    files[*fileCount] = newFile;
    (*fileCount)++;

    printf("������ �߰��Ǿ����ϴ�.\n");
}

void deleteFile(File* files, int* fileCount) {
    int i, fileIndex;
    printf("������ ������ ��ȣ�� �Է��ϼ���: ");
    scanf("%d", &fileIndex);

    if (fileIndex >= 1 && fileIndex <= *fileCount) {
        printf("���� '%s'��(��) �����մϴ�.\n", files[fileIndex - 1].fileName);

        for (i = fileIndex - 1; i < *fileCount - 1; i++) {
            files[i] = files[i + 1];
        }

        (*fileCount)--;
    }
    else {
        printf("�߸��� ���� ��ȣ�Դϴ�.\n");
    }
}

void modifyFile(File* files, int fileCount) {
    int fileIndex;
    printf("������ ������ ��ȣ�� �Է��ϼ���: ");
    scanf("%d", &fileIndex);

    if (fileIndex >= 1 && fileIndex <= fileCount) {
        printf("���� '%s'�� ������ �����մϴ�.\n", files[fileIndex - 1].fileName);
        printf("���ο� ���� ������ �Է��ϼ���: ");
        scanf("%s", files[fileIndex - 1].fileContent);
        printf("������ �����Ǿ����ϴ�.\n");
    }
    else {
        printf("�߸��� ���� ��ȣ�Դϴ�.\n");
    }
}

void searchFile(File* files, int fileCount) {
    char keyword[50];
    int i, found = 0;

    printf("�˻��� Ű���带 �Է��ϼ���: ");
    scanf("%s", keyword);

    printf("�˻� ���:\n");

    for (i = 0; i < fileCount; i++) {
        if (strstr(files[i].fileName, keyword) != NULL || strstr(files[i].fileContent, keyword) != NULL) {
            printf("���� �̸�: %s\n", files[i].fileName);
            printf("���� ����: %s\n", files[i].fileContent);
            found = 1;
        }
    }

    if (!found) {
        printf("�˻� ����� �����ϴ�.\n");
    }
}

void setPassword(int* password) {
    int newPassword;

    printf("���ο� ��й�ȣ�� �Է��ϼ���: ");
    scanf("%d", &newPassword);

    *password = newPassword;

    printf("��й�ȣ�� ���������� �����Ǿ����ϴ�.\n");
}

void printFileList(File* files, int fileCount) {
    int i;

    printf("==== ���� ��� ====\n");

    for (i = 0; i < fileCount; i++) {
        printf("%d. %s\n", i + 1, files[i].fileName);
    }
}

void viewFileContent(File* files, int fileCount) {
    int fileIndex;

    printf("������ Ȯ���� ������ ��ȣ�� �Է��ϼ���: ");
    scanf("%d", &fileIndex);

    if (fileIndex >= 1 && fileIndex <= fileCount) {
        printf("���� �̸�: %s\n", files[fileIndex - 1].fileName);
        printf("���� ����: %s\n", files[fileIndex - 1].fileContent);
    }
    else {
        printf("�߸��� ���� ��ȣ�Դϴ�.\n");
    }
}

int main() {
    File files[100];
    int fileCount = 0;
    int password = 1234;
    int loggedIn = 0;
    int choice;

    while (1) {
        printf("===== ���� ���� ���α׷� =====\n");
        printf("1. ���� �߰�\n");
        printf("2. ���� ����\n");
        printf("3. ���� ����\n");
        printf("4. ���� �˻�\n");
        printf("5. ��й�ȣ ����\n");
        printf("6. ���� ��� ���\n");
        printf("7. ���� ���� Ȯ��\n");
        printf("8. �α���\n");
        printf("9. �α׾ƿ�\n");
        printf("10. ����\n");
        printf("=============================\n");
        printf("�޴��� �����ϼ���: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (loggedIn) {
                addFile(files, &fileCount);
            }
            else {
                printf("�α����� �ʿ��մϴ�.\n");
            }
            break;
        case 2:
            if (loggedIn) {
                deleteFile(files, &fileCount);
            }
            else {
                printf("�α����� �ʿ��մϴ�.\n");
            }
            break;
        case 3:
            if (loggedIn) {
                modifyFile(files, fileCount);
            }
            else {
                printf("�α����� �ʿ��մϴ�.\n");
            }
            break;
        case 4:
            if (loggedIn) {
                searchFile(files, fileCount);
            }
            else {
                printf("�α����� �ʿ��մϴ�.\n");
            }
            break;
        case 5:
            if (loggedIn) {
                setPassword(&password);
            }
            else {
                printf("�α����� �ʿ��մϴ�.\n");
            }
            break;
        case 6:
            if (loggedIn) {
                printFileList(files, fileCount);
            }
            else {
                printf("�α����� �ʿ��մϴ�.\n");
            }
            break;
        case 7:
            if (loggedIn) {
                viewFileContent(files, fileCount);
            }
            else {
                printf("�α����� �ʿ��մϴ�.\n");
            }
            break;
        case 8:
            if (loggedIn) {
                printf("�̹� �α��εǾ� �ֽ��ϴ�.\n");
            }
            else {
                int inputPassword;
                printf("��й�ȣ�� �Է��ϼ���: ");
                scanf("%d", &inputPassword);
                if (inputPassword == password) {
                    loggedIn = 1;
                    printf("�α��εǾ����ϴ�.\n");
                }
                else {
                    printf("��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n");
                }
            }
            break;
        case 9:
            if (loggedIn) {
                loggedIn = 0;
                printf("�α׾ƿ��Ǿ����ϴ�.\n");
            }
            else {
                printf("�̹� �α׾ƿ��Ǿ� �ֽ��ϴ�.\n");
            }
            break;
        case 10:
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �޴� ��ȣ�Դϴ�.\n");
        }
    }

    return 0;
}
