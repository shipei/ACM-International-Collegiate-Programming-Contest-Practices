#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double expenses[1000];
int students = 1000;

double ave(int num)
{
  double total = 0.0;
  int i;
  for(i = 0; i < num; i++)
    {
      total += expenses[i];
    }
  return total / num;
}

double amount_to_exchange(int num)
{
  double averageCost = ave(num);
  double pos = 0.0;
  double neg = 0.0;

  int i;
  for(i = 0; i < num; i++)
    {
      if(expenses[i] > averageCost) {
	pos += floor((expenses[i] - averageCost) * 100.0) / 100.0;
	     }
      else {
	neg += floor((averageCost - expenses[i]) * 100.0) / 100.0;
      }
    }
  if(neg > pos)
    return neg;
  else
    return pos;
}

int main() {
  int n = 1;
  double results[1000];
  while(scanf("%d", &students) != EOF && students!= 0)
    {
      int i;
      for(i = 0; i < students; i++)
	{
	  scanf("%lf", &expenses[i]);
	}
      results[n-1] = amount_to_exchange(students);
      n++;
    }
  int j;
  for(j = 0; j < n-1; j++)
      printf("$%.2lf\n", results[j]);
  return 0;
}
