#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

struct Patient {
    int id;
    char name[50];
    int age;
};

struct Patient queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) {
        printf("Queue Full!\n");
        return;
    }

    struct Patient p;
    printf("Enter ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    scanf("%s", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);

    if (front == -1) front = 0;
    queue[++rear] = p;

    printf("Patient Added!\n");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Empty!\n");
        return;
    }

    printf("Patient Treated: %s\n", queue[front].name);
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("No Patients!\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d %s %d\n", queue[i].id, queue[i].name, queue[i].age);
    }
}

void peek() {
    if (front != -1)
        printf("Next Patient: %s\n", queue[front].name);
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Add 2.Treat 3.Display 4.Peek 5.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: exit(0);
        }
    }
}
