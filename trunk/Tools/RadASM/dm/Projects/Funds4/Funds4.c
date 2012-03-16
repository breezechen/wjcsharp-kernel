#include <stdio.h>
#include <string.h>
#include "Funds4.h"

#define MAXLEN	20

struct namect
{
	char fname[MAXLEN];
	char lname[MAXLEN];
	int letters;	
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);

int main (void)
{
	struct namect person;
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	return 0;
}

void getinfo (struct namect * pst)
{

	printf("Please enter your first name.\n");
	
	gets(pst->fname);
	
	printf("Please enter your last name.\n");
	
	gets(pst->lname);	
}

void makeinfo (struct namect * pst)
{

	pst->letters =	strlen (pst->fname) +
					strlen (pst->lname);
					
}

void showinfo (const struct namect * pst)
{

	printf("%s %s, your name contaisns %d letters.\n",
			pst->fname, pst->lname, pst->letters);	
}