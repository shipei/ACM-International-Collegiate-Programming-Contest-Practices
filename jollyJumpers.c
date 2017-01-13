#include <stdio.h>
#include <stdlib.h>

typedef int boolean;
enum { false, true };

int size;
int list[10000];
int differences[10000];

void sort()
{
  int i, j, temp;
  for (i = 0; i < size - 2; ++i)
    {
      for (j = 0; j < size - 2 - i; ++j)
	{
	  if (differences[j] > differences[j+1])
	    {
	      temp = differences[j+1];
	      differences[j+1] = differences[j];
	      differences[j] = temp;
	    }
	}
    }
}

boolean jolly_jumper()
{
  if(size == 1)
    return true;

  int i = 0;
  for(i = 0; i < size-1; i++)
    {
      int dif = (abs(list[i] - list[i+1]));
      differences[i] = dif;
    }
  sort();

  int val = 1;
  int m = 0;
  for(m = 0; m < size-1; m++)
    {
      if(differences[m] != val)
	{
	  return false;
	  break;
	}
      else
	{
	  val++;
	}
    }
    return true;
 }

int main()
{
  while(scanf("%d", &size) != EOF)
     {
       int diff[size-1];
       int b = 0;
       for(b = 0; b < size; b++)
	 {
	   scanf("%d", &list[b]);
	 }
       boolean result = jolly_jumper();
       if(result == true)
	 {
	   printf("Jolly\n");
	 }
       else
	 {
	   printf("Not jolly\n");
	 }
     }
  return 0;
}
