#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <sys/timeb.h>
#include   <dos.h>
#include   <string.h>
using namespace std;


struct DbList{
DbList* next;
int wert;
DbList* prev;
};
DbList* Eingabe(DbList *start);
void AusgabeVorwaerts(DbList *start);
void AusgabeRueckwaerts(DbList *start);
void ListeFreigeben(DbList *&start);
void ListeFreigebenRek(DbList *&start,DbList *&startOriginal);
DbList* SchneideBlockAus(DbList *start,DbList *Block);
int main()
{
 DbList* start;
 start = NULL;
 cout << "Geben sie die Elemente der Liste ein:"<<endl << "Geben sie \"0\" zum abschliessen der Liste ein"<<endl;
 start =Eingabe(start);
 AusgabeVorwaerts(start);
 AusgabeRueckwaerts(start);
 cout << "Schneide 2ten Block aus! \n";
 start=SchneideBlockAus(start,(start->next));
 AusgabeVorwaerts(start);
 cout << "Loesche Liste! \n";
  //ListeFreigeben(start);
 ListeFreigebenRek(start,start);
 AusgabeVorwaerts(start);
}

DbList* Eingabe(DbList *start){
//eingabe in umgekehrter reihenfolge
DbList * work = NULL;
int input;
while ((cin >> input)){
    if(input==0) break;
    work = (DbList *)malloc(sizeof(DbList));
    work->next = work;
    work->prev = work;
    work->wert = input;
    if (start==NULL){
        start=work;
    }
    else
    {
        work->next = start;
        (start->prev)->next = work;//5
        work->prev = (start->prev);
        (start->prev) = work;
        start= work;
    }
    }
    return start;
}
void AusgabeVorwaerts(DbList *start){
 if (start==NULL){
 cout << "Liste ist Leer"<<endl;
 }else{
   DbList *work;
   work = start;
   cout << "Liste Vorwaerts \n ";
   do {
    cout << work->wert << " \n ";
    work= work->next;
   }while (work!=start);
 }
}
void AusgabeRueckwaerts(DbList *start){
 if (start==NULL){
 cout << "Liste ist Leer"<<endl;
 }else{
   DbList *work;
   work = start->prev;
   cout << "Liste Rueckwaerts \n ";
   do {
    cout << work->wert << " \n ";
    work= work->prev;
   }while (work!=start->prev);
 }
}

void ListeFreigeben(DbList *&start){
 DbList *work;
 if (start!=NULL){
 (start->prev)->next = NULL;
 while (start!=NULL){
    work = start->next;
    free(start);
    start=work;
 }
 }
}

void ListeFreigebenRek(DbList *&start,DbList startOriginal){
    if(start==NULL){
    }else
    if(start==startOriginal){
        (start->prev)->next=NULL;
    }
     else{
        ListeFreigebenRek(start->next,startOriginal);
        free(start);
        start = NULL;
    }

}


DbList* SchneideBlockAus(DbList *start,DbList *Block){
if (start->next==start){
    return NULL;
}
if (start==Block){
    start=Block->next;
}
    (Block->prev)->next=Block->next;
    (Block->next)->prev=Block->prev;
    free(Block);
return start;
}


