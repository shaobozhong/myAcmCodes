#include<iostream>
#include<string.h>
using namespace std;

typedef struct Node
{
 char letter;
 //bool la;
    struct Node *child;
 struct Node *brother;
 int count;
}Elem;

void creat(Elem *head,char *word)
{
 Elem *p,*q,*r;
 int i;
 bool suc;
 p=head;
 for(i=0;i<(int)strlen(word);i++)
 {
  suc=false;
  q=p->child;
  r=q;
  while(q)
  {
   r=q;
   if (q->letter==word[i]) {suc=true;p=q;p->count++;break;}
   q=q->brother;
  }
  if (suc) continue;
  q=new Elem;
  q->letter=word[i];
  q->count=1;
  q->brother=NULL;
  q->child=NULL;
  //q->la=false;
  if (!p->child) p->child=q;
  if (r) r->brother=q;
  p=q;
 }
}

int find_1(Elem head,char *word)
{
 Elem *p,*q;
 int i;
 p=&head;
 for(i=0;i<(int)strlen(word);i++)
 {
  q=p->child;
  while(q)
  {
   if (q->letter==word[i]) {break;}
   q=q->brother;
  }
  if (!q) return 0;
  p=q;
 }
 return p->count;
}

int main()
{
 char word[10];
 Elem head;
 head.letter=0;
 head.child=NULL;
 head.brother=NULL;
 //head.la=true;
 head.count=0;
 while(gets(word),strcmp(word,"")!=0)
 {
  creat(&head,word);
 }

 while(scanf("%s",word)!=EOF)
 {
  printf("%d\n",find_1(head,word));
 }
  return 0;
}
