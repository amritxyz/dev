#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Define an array of critters to sort. */
struct critter {
	const char *name;
	const char *species;
};

/* Randon data from gnu website */
struct critter muppets[] =
{
	{"Kermit", "frog"},
	{"Piggy", "pig"},
	{"Gonzo", "whatever"},
	{"Fozzie", "bear"},
	{"Sam", "eagle"},
	{"Robin", "frog"},
	{"Animal", "animal"},
	{"Camilla", "chicken"},
	{"Sweetums", "monster"},
	{"Dr. Strangepork", "pig"},
	{"Link Hogthrob", "pig"},
	{"Zoot", "human"},
	{"Dr. Bunsen Honeydew", "human"},
	{"Beaker", "human"},
	{"Swedish Chef", "human"}
};

int count = sizeof (muppets) / sizeof (struct critter);

/* This is the comparison function used for sorting and searching. */

int
critter_cmp (const void *v1, const void *v2)
{
	const struct critter *c1 = v1;
	const struct critter *c2 = v2;

	return strcmp (c1->name, c2->name);
}


/* Print information about a critter. */

void
print_critter (const struct critter *c)
{
	printf ("%s, the %s\n", c->name, c->species);
}


/* Do the lookup into the sorted array. */

void
find_critter (const char *name)
{
	struct critter target, *result;
	target.name = name;
	result = bsearch (&target, muppets, count, sizeof (struct critter),
			critter_cmp);
	if (result)
		print_critter (result);
	else
		printf ("Couldn't find %s.\n", name);
}


/* Main program. */

int
main (void)
{
	int i;

	for (i = 0; i < count; i++)
		print_critter (&muppets[i]);
	printf ("\n");

	qsort (muppets, count, sizeof (struct critter), critter_cmp);

	for (i = 0; i < count; i++)
		print_critter (&muppets[i]);
	printf ("\n");

	find_critter ("Kermit");
	find_critter ("Gonzo");
	find_critter ("Janice");

	return 0;
}
