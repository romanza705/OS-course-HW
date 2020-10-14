//
// Created by roman on 13.10.2020.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Pager{
    int pageNum;
    int* pages;
    char* access;

    int hits;
    int misses;
} Pager;

Pager* create_pager(int num){
    Pager* p = (Pager*)malloc(sizeof(Pager));
    p->pageNum = num;
    p->pages = (int*)malloc(sizeof(int) * num);
    p->access = (char*)malloc(sizeof(char) * num);
    p->hits = p->misses = 0;

    return p;
}

int paccess(Pager* p, int pid){
    int idx = 0;
    char* byte = p->pages[0];
    for(int i=0; i < p->pageNum; ++i){
        if(p->pages[i] == pid){
            p->hits++;
            p->access[i] = p->access[i] | 0b10000000;
            return 0;
        }
        if(p->access[i] < byte){
            idx = i;
            byte = p->access[i];
        }
    }

    p->pages[idx] = pid;
    p->access[idx] = 0b10000000;
    p->misses++;

    return 1;
}

int main(){
    Pager* pager = create_pager(10);   //For changing number of pages(frames) change the argument

    FILE* fin = fopen("input.txt", "r");

    int tmp = 0;
    while(fscanf(fin, "%d", &tmp) != EOF){
        for(int i=0; i<pager->pageNum; ++i)
            pager->access[i] = pager->access[i] >> 1;
        paccess(pager, tmp);
    }

    printf("Hit: %d\n", pager->hits);
    printf("Miss: %d\n", pager->misses);
    printf("Hit/Miss ratio: %f\n", (double)pager->hits/(double)pager->misses);


    fclose(fin);

    return 0;
}

//10
//Hit: 8
//Miss: 992
//Hit/Miss ratio: 0.008065
//
//100
//Hit: 93
//Miss: 907
//Hit/Miss ratio: 0.102536
//50
//Hit: 50
//Miss: 950
//Hit/Miss ratio: 0.052632
