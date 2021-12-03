#include <stdio.h>
int lengthOfNumber(unsigned int n)
{
  int l = 0;
  while (n > 0)
  {
    n /= 10;
    l++;
  }
  return l;
}
int validStep(unsigned int prev_number, unsigned int current_number)
{
  int validity = 0, diff = lengthOfNumber(prev_number) - lengthOfNumber(current_number), i = 0, j = 0, a = prev_number,
      b = current_number, digits_array_p[12], digits_array_c[12];
  while (a > 0)
  {
    digits_array_p[i] = a % 10;
    a /= 10;
    i++;
  }
  i = 0;
  while (b > 0)
  {
    digits_array_c[i] = b % 10;
    b /= 10;
    i++;
  }
  i = 0;
  if (diff > 0)
  {
    // deletion happened
    if (diff == 1)
    {
      while (i < lengthOfNumber(prev_number))
      {
        if (digits_array_c[j] == digits_array_p[i])
          j++;
        i++;
      }
      if (j == lengthOfNumber(current_number))
        validity = 1;
    }
  }
  else if (diff < 0)
  {
    // insertion happened
    if (diff == -1)
    {
      while (i < lengthOfNumber(current_number))
      {
        if (digits_array_p[j] == digits_array_c[i])
          j++;
        i++;
      }
      if (j == lengthOfNumber(prev_number))
        validity = 1;
    }
  }
  else
  {
    // alteration
    for (i = 0; i < lengthOfNumber(prev_number); i++)
    {
      if (digits_array_c[i] != digits_array_p[i])
        j++;
    }
    if (j == 1)
      validity = 1;
  }
  return validity;
}
unsigned int enterNext()
{
  printf("Enter next number: ");
  unsigned int n;
  scanf("%u", &n);
  return n;
}
int main()
{
  unsigned int start_number, end_number, step_count = 0, error_count = 0, prev_number, current_number;
  printf("Enter start_number : ");
  scanf("%u", &start_number);
  do
  {
    printf("Enter end_number : ");
    scanf("%u", &end_number);
  } while (start_number == end_number);
  printf("Entered \tstart number: %u \t end_number: %u"
         "\n\nLet us Play!\n",
         start_number, end_number);
  prev_number = start_number;
  do
  {
    current_number = enterNext();
    while (prev_number == current_number)
      current_number = enterNext();
    if (validStep(prev_number, current_number))
    {
      step_count++;
      printf("Good step %u: from %u to %u\n", step_count, prev_number, current_number);
      prev_number = current_number;
    }
    else
    {
      printf("Made error!\n");
      error_count++;
    }
  } while (prev_number != end_number);
  printf("\nWe hope you enjoyed!!\t Total steps taken: %u\t Total errors: %u\n", step_count, error_count);
  return 0;
}