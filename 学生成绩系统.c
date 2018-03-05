#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAMELEN 10
#define COURSES 4

typedef struct stu_info stu_info;
struct stu_info
{   char stu_name[NAMELEN];//名字
    int id;
    int score[COURSES];//分数
    float avgScore;
    struct stu_info *next;
};
stu_info *first = NULL;
stu_info *current = NULL;
stu_info *previous = NULL;
stu_info *delete = NULL;
void Menu();
void Start_Five();
void all_over(stu_info *);

int main(int argc, char const *argv[])
{
    Start_Five();
    int menu;//功能键
    char test;//function2判断
    int m;//function3学生ID
    int number;//function4课程编号
    char name[10];//function5名字
    int n;//函数返回值

    while (1)
    {
        Menu();
        printf("Please input menu:");
        n = scanf("%d",&menu);
        if (n == 0){
            printf("\nillegal input！！\n");
            break;
        }
        switch (menu)
        {
            case 1:
                printf("\n\n*******************Mani Menu*******************\n");
                printf("ID    Name      CO1   CO2   CO3   CO4     Avg\n");
                all_over(first);
                printf("***********************************************\n\n");
                break;
            case 2:
                for ( ; ; )
                {

                    printf("Do you want to enter a%s student information(Y or N)?  :",(first != NULL)?"nother": "");
                    scanf("%s",&test);
                    if (tolower(test) == 'n')
                    {
                        break;
                    }
                    current = (stu_info *)malloc(sizeof(stu_info));
                    if (first == NULL)
                    {
                        first = current;
                    }
                    if (previous != NULL)
                    {
                        previous -> next = current;
                    }

                    printf("ID of the new student:");
                    n = scanf("%d",&current -> id);
                    if (n == 0){
                        printf("\nillegal input！！\n");
                        continue;
                    }

                    printf("Name of the new student:");
                    n = scanf("%s",current -> stu_name);
                    if (n == 0){
                        printf("\nillegal input！！\n");
                        continue;
                    }

                    printf("Please input  the score of CO1:");
                    n = scanf("%d",&current -> score[0]);
                    if (n == 0){
                        printf("\nillegal input！！\n");
                        continue;
                    }

                    printf("Please input  the score of CO2:");
                    n = scanf("%d",&current -> score[1]);
                    if (n == 0){
                        printf("\nillegal input！！\n");
                        continue;
                    }

                    printf("Please input  the score of CO3:");
                    n = scanf("%d",&current -> score[2]);
                    if (n == 0){
                        printf("\nillegal input！！\n");
                        continue;
                    }

                    printf("Please input  the score of CO4:");
                    n = scanf("%d",&current -> score[3]);
                    if (n == 0){
                        printf("\nillegal input！！\n");
                        continue;
                    }
                    current ->avgScore = ((float)current -> score[0]+(float)current -> score[1]+(float)current -> score[2]+(float)current -> score[3])/4;

                    current -> next = NULL;
                    previous = current;
                }
                break;
            case 3:
                printf("Please enter the id of the student to delete:");
                n = scanf("%d",&m);
                if (n == 0){
                    printf("\nillegal input！！\n");
                    break;
                }
                current = first;
                while(current != NULL)
                {
                    if ((current ->id) == m-1)
                    {
                        delete = current ->next;
                        current -> next = delete -> next;
                        free(delete);
                        delete = NULL;
                        break;
                    }
                    current = current -> next;
                }
                break;
            case 4:
                printf("Please enter the name of the student to search:\nName = ");
                n = scanf("%s",name);
                if (n == 0){
                    printf("\nillegal input！！\n");
                    continue;
                }
                current = first;
                while(current != NULL)
                {
                    n = strcmp(name,current->stu_name);
                    if (n == 0)
                    {
                        printf("ID    Name      CO1   CO2   CO3   CO4     Avg\n");
                        printf("%-2d    %-10s %d    %d    %d    %d     %.2f\n",current->id,current->stu_name,current->score[0],current->score[1],current->score[2],current->score[3],current->avgScore);
                        current = current -> next;
                        break;
                    }
                    current = current -> next;
                }
                break;
            case 5:
                printf("Please input the course id you want to analyze:\nCO:");
                n = scanf("%d",&number);
                if (n == 0){
                    printf("\nillegal input！！\n");
                    continue;
                }
                printf("course info of CO%d\n6",number);
                current = first;
                while(current != NULL)
                {
                    printf("%s =  %d\n",current->stu_name,current->score[number-1]);
                    current = current -> next;
                }
                break;
            case 6:
                //全部释放
                current = first;
                while(current != NULL)
                {
                    previous = current;
                    current = current -> next;
                    free(previous);
                    previous = NULL;
                }
                first = NULL;
                return 0;
            default:
                //结束！
                printf("Error input!\n");
                break;
        }
    }
    first = NULL;
}
void Start_Five() {
    current = (stu_info *)malloc(sizeof(stu_info));
    first = current;
    strcpy(current->stu_name, "tom");
    current->id = 1;
    current->score[0] = 85;
    current->score[1] = 90;
    current->score[2] = 95;
    current->score[3] = 80;
    current->avgScore = (85 + 90 + 95 + 80) / 4;
    current->next = NULL;
    previous = current;
}
void Menu(){
    printf("\n\n*******************Mani Menu*******************\n");
    printf("\t\t\t1. Show Current List\n");//显示当前列表
    printf("\t\t\t2. Insert Student\n");//插入学生
    printf("\t\t\t3. Delete Student\n");//删除学生
    printf("\t\t\t4. Search Student\n");//搜索学生
    printf("\t\t\t5. Analyze Course\n");//分析过程
    printf("\t\t\t6. Exit the program\n");//退出程序
    printf("***********************************************\n\n");
}
void all_over(stu_info * current){
    current = first;
    while(current != NULL)
    {
        printf("%-2d    %-10s %d    %d    %d    %d     %.2f\n",current->id,current->stu_name,current->score[0],current->score[1],current->score[2],current->score[3],current->avgScore);
        current = current -> next;
    }

}