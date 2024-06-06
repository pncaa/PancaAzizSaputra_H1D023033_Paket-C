#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 4

typedef struct{
    int count;
    int front;
    int rear;
    int item[MAXQUEUE];
} QUEUE;

QUEUE antrean;
void inisialisasi(QUEUE*Q){
    Q->count=0;
    Q->front=0;
    Q->rear=-1;

}

int isEmpty(QUEUE*Q){
    int hasil=0;
    if(Q->count ==0){
        hasil=1;
    }
    return hasil;
}

int isFull(QUEUE*Q){
    int hasil=0;
    if(Q->count==MAXQUEUE){
        hasil=1;
    }
    return hasil;
}

void insert(QUEUE* Q, int value){
    if(isFull(Q)){
        printf("Queue penuh!\n");
        return;
    }
    Q->rear = (Q->rear + 1) % MAXQUEUE;
    Q->item[Q->rear] = value;
    Q->count++;
    printf("masukan %d\n", value);
}

void hapus(QUEUE* Q){
    if(isEmpty(Q)){
        printf("Queue kosong!\n");
        return;
    }
    int value = Q->item[Q->front];
    Q->front = (Q->front + 1) % MAXQUEUE;
    Q->count--;
    printf("Menghapus %d dari antrean\n", value);
}

void printQueue(QUEUE* Q){
    if(isEmpty(Q)){
        printf("Queue kosong!\n");
        return;
    }
    printf("Isi antrean: ");
    for(int i = 0; i < Q->count; i++){
        int index = (Q->front + i) % MAXQUEUE;
        printf("%d ", Q->item[index]);
    }
    printf("\n");
}

int main(){
    inisialisasi(&antrean);

    insert(&antrean, 17);
    printQueue(&antrean);

    insert(&antrean, 45);
    printQueue(&antrean);

    insert(&antrean, 77);
    printQueue(&antrean);

    hapus(&antrean);
    printQueue(&antrean);

    insert(&antrean, 15);
    printQueue(&antrean);

    return 0;
}
