#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TITLE_LENGTH 100
#define MAX_TASKS 100

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    bool isCompleted;    
} Task;

void addTask(Task tasks[], int *task_count, const char *title) {
    if (*task_count >= MAX_TASKS){
        printf("Task list is full.\n");
        return;
    }
    tasks[*task_count].id = *task_count + 1;
    strncpy(tasks[*task_count].title, title, MAX_TITLE_LENGTH);
    tasks[*task_count].title[MAX_TITLE_LENGTH - 1] = '\0';
    tasks[*task_count].isCompleted = false;
    (*task_count)++;
    printf("Task added: %s\n", title);
}

void displayTasks(const Task tasks[], int task_count) {
    for (int i = 0; i < task_count; i++){
        printf("%d. %s [%s]\n", tasks[i].id, tasks[i].title, tasks[i].isCompleted ? "Done" : "Pending");
    }
}

void markTaskAsCompleted(Task tasks[], int task_count, int id){
    for (int i = 0; i < task_count; i++){
        if (tasks[i].id == id){
            tasks[i].isCompleted = true;
            printf("Task %d marked as completed", id);
        } else {
            printf("Task with ID %d not found", id);
            break;
        }
    }
}

int main(){
    Task tasks[MAX_TASKS];
    int task_count = 0;
    int choice, id;
    char title[MAX_TITLE_LENGTH];
    
    while(true) {
        printf("\nToDo List Menu:\n");
        printf("1. Tambahkan TodoList\n");
        printf("2. Tampilkan TodoList\n");
        printf("3. Tandai TodoList yang sudah selesai\n");
        printf("4. Bersihkan Layar\n");
        printf("5. Keluar\n");
        printf("Masukkan pilihan anda: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("Masukkan nama tugas: ");
            fgets(title, MAX_TITLE_LENGTH, stdin);
            title[strcspn(title, "\n")] = '\0';
            addTask(tasks, &task_count, title);
            break;
        case 2:
            displayTasks(tasks, task_count);
            break;
        case 3:
            printf("Masukkan id tugas yang sudah diselesaikan: \n");
            displayTasks(tasks, task_count);
            scanf("%d", &id);
            markTaskAsCompleted(tasks, task_count, id);
            break;
        case 4:
            printf("\e[1;1H\e[2J");
            break;
        case 5:
            printf("Bye...\n");
            exit(0);
        default:
            printf("Pilihan salah. Mohon coba kembali. \n");
            break;
        }
    }
}