#include <iostream>
using namespace std;


struct list
{
  int field;
  struct list *ptr; 
};


struct list * init(int a) 
{
  struct list *lst;
  lst = (struct list*)malloc(sizeof(struct list));
  lst->field = a;
  lst->ptr = NULL; 
  return(lst);
}


struct list * addelem(list *lst, int value)
{
  struct list *temp, *p;
  temp = (struct list*)malloc(sizeof(list));
  p = lst->ptr; 
  lst->ptr = temp; 
  temp->field = value; 
  temp->ptr = p;
  return(temp);
}


struct list * deletelem(list *lst, list *root)
{
  struct list *temp;
  temp = root;
  while (temp->ptr != lst)
    temp = temp->ptr;
  temp->ptr = lst->ptr;
  free(lst);
  return(temp);
}


struct list * deletehead(list *root)
{
  struct list *temp;
  temp = root->ptr;
  free(root);
  return(temp);
}


void listprint(list *lst)
{
  struct list *p;
  p = lst;
  do {
    printf("%d ", p->field);
    p = p->ptr;
  } while (p != NULL);
  printf("\n");
}

int main()
{
  int n, value, x_n;
  struct list * head_s1;
  struct list * head_s2;
  struct list * s1;
  struct list * s2;

  cout << "Введите n: ";
  cin >> n;

  cout << "Введите значение 1 узла: ";
  cin >> value;

  head_s1 = init(value);
  s1 = head_s1;
  
  for (int i = 2; i <= n; i++)
  {
    cout << "Введите значение " << i << " узла: ";
    cin >> value;
    s1 = addelem(s1, value);
    if (i == n)
      x_n = value;
  }


  s1 = head_s1;
  head_s2 = init(s1->field - x_n);
  s2 = head_s2;
  s1 = s1->ptr;

  do {
    s2 = addelem(s2, s1->field - x_n);
    s1 = s1->ptr;
  } while (s1 != NULL);

  s2 = deletelem(s2, head_s2);
  s2 = head_s2; 

  listprint(s2);
  return 0;
}