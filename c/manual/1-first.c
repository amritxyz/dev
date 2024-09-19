#include <stdio.h>

void foo (int i)
{
  printf ("foo %d!\n", i);
}

void bar (int i)
{
  printf ("%d bar!\n", i);
}

void message (void (*func)(int), int times)
{
  int j;
  for (j=0; j<times; ++j)
    func (j);  /* (*func) (j); would be equivalent. */
}

void example (int want_foo)
{
  void (*pf)(int) = &bar; /* The & is optional. */
  if (want_foo)
    pf = foo;
  message (pf, 5);
}

int main()
{
  printf("Calling example with want_foo = 0:\n");
  example(0);
  printf("Calling example with want_foo = 1:\n");
  example(1);
  return 0;
}

