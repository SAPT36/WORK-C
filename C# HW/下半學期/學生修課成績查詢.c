#include<stdio.h> 
#include<conio.h> 

typedef enum { M, F, N, B }sex;
const char* departname[] = { "Chemical Engineering","Communication Engineering","Computer Science","Electrophysics","Electrical Engineering" ,"Medical Science" };
const char* coursetitle[] = { "English writing","Introcduction of JAVA","Six-way paragraphs","Computer Science","Basic Caculate" };
const char* sextype[] = { "Male","Female","Neutral","Bisexual" };
const char* maintitle[] = { "顯示全部","顯示一筆紀錄","新增一筆紀錄","刪除一筆紀錄","更改一筆紀錄","結束" };

struct member
{
    int serialno;
    char stuno[10];
    char name[11];
    sex gender;
    const char* department;
    const char* course[5];
    int grade[5];
};

void showoption(const char* optionname[], unsigned int);
int choice(int);
void onerecord(struct member*);
void showrecord(struct member);

int main(void)
{
    struct member student[20];
    int stucount = 0, mainchoice;
    do {
        showoption(maintitle, 6);
        mainchoice = choice(6);
        switch (mainchoice)
        {
        case 1:
            printf("\n總共有%d筆紀錄\n", stucount);
            if (stucount != 0)
                for (sex i = M; i <= stucount - 1; i++)
                    showrecord(student[i]);
            break;
        case 2:
            printf("\n總共有%d筆紀錄\n", stucount);
            if (stucount != 0) {
                printf("請輸入要顯示的紀錄編號: ");
                showrecord(student[choice(stucount) - 1]);
            }
            break;

        case 3:
            printf("\n總共有%d筆紀錄\n", stucount);
            onerecord(&student[stucount++]);
            break;
        case 4:
            printf("\n總共有%d筆紀錄\n", stucount);
            if (stucount != 0) {
                printf("請輸入要刪除的紀錄編號: ");
                for (sex i = choice(stucount) - 1; i <= stucount - 2; i++)
                    student[i] = student[i + 1];
                stucount--;
            }
            break;
        case 5:
            printf("\n總共有%d筆紀錄\n", stucount);
            if (stucount != 0) {
                printf("請輸入要更改的紀錄編號: ");
                for (sex i = choice(stucount) - 1; i <= stucount - 2; i++)
                    student[i] = student[i + 1];
                stucount--;
                onerecord(&student[stucount++]);
            }

            break;
        }

    } while (mainchoice != 6);
}

void showoption(const char* optiontype[], unsigned int typecount)
{
    printf("\n");
    for (size_t i = 0; i <= typecount - 1; i++)
        printf("(%d)%s\n", i + 1, optiontype[i]);
}

int choice(int count)
{
    int choose;
    int temp;
    do {
        printf("\n1-%1d: ", count);
        choose = _getch() - 48;
        printf("%d\n", choose);
        temp = _getch();
    } while (choose < 1 || choose > count);
    return choose;
}


void onerecord(struct member* onestu)
{
    printf("\n");
    printf("請輸入編號: ");
    scanf("%d", &onestu->serialno);
    printf("請輸入學號: ");
    scanf("%9s", onestu->stuno);
    printf("請輸入姓名: ");
    scanf("%10s", onestu->name);
    showoption(sextype, 4);
    printf("請輸入性別: ");
    onestu->gender = choice(4) - 1;
    showoption(departname, 6);
    printf("請輸入系別: ");
    onestu->department = departname[choice(6) - 1];
    for (sex i = M; i < B; i++)
    {
        printf("\n請輸入第%d門修習課程: \n", i + 1);
        showoption(coursetitle, 5);
        onestu->course[i] = coursetitle[choice(5) - 1];
        printf("\n請輸入第%d門修習課程成績: ", i + 1);
        scanf("%d", &onestu->grade[i]);
    }
}

void showrecord(struct member onestu)
{
    printf("\n");
    printf("編號: %d\n", onestu.serialno);
    printf("學號: %s\n", onestu.stuno);
    printf("姓名: %s\n", onestu.name);
    printf("性別: %s\n", sextype[onestu.gender]);
    printf("系別: %s\n", onestu.department);
    for (sex i = M; i < B; i++)
    {
        printf("修課%d: %s\n", i + 1, onestu.course[i]);
        printf("成績: %d\n", onestu.grade[i]);
    }
}