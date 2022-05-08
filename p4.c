/* Programmed under :
 * Microsoft Visual Studio Community 2022,
 * Uses Intel C++ Compiler Classic,
 * Windows 11 OS,
 * by Mishary (Ahmed Crow)
 * https://www.facebook.com/ahmed.crow.988/
 * https://www.facebook.com/profile.php?id=100009232142912
 * C only pure standard version of C
 */
 


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "conio2.h"

#define wordlen 6

void group_array_check(char[][wordlen+1], const char*);

void ab_cmp(void);

char things[6][wordlen + 1] = { "box", "domino",
"spoon","book", "pen", "flag" };
char group_a[3][wordlen+1];
char group_b[3][wordlen+1];
char ab_both[3][wordlen+1];

int i, x, i2;
char* user_choice = "null";
char is_there;
int ab_haveit;
char answer;

int main(void)
{

	char ch;

again:

	for (i = 0; i <= 2; ++i) {
		strcpy(group_a[i], "000");
		strcpy(group_b[i], "111");
		strcpy(ab_both[i], "000");
	}

	ab_haveit = 0;

	system("cls");
	
	printf("Pick 3 things in every-time for\n");
	printf("both of group A and group B, and I'll\n");
	printf("discover the similarity between both.\n\n");
	printf("Things that you can pick from\n");
	printf("without repeating are:\n\n");

	group_array_check(group_a, "group A");
	printf("\n");
	group_array_check(group_b, "group B");
	printf("\n");
	ab_cmp();

	printf("\nDo you like to do it again(y/n)? ");
	if (tolower(getchar()) == 'y') {
		fflush2();
		goto again;
	}

	fflush2();
	return 0;
}

void group_array_check(char sh[3][wordlen + 1], const char* ch)
{

	x = wherex();

	for (i = 0; i <= 5; ++i) {
		gotoxy(x, wherey());
		printf("%s  ", things[i]);
		x = wherex() + 5;
	}

	printf("\n");
	printf("For %s:\n", ch);


	for (i = 1; i <= 3; ++i) {

	again:

		is_there = 1;

		printf("%d) Pick something: ", i);
		gets(user_choice);
		strcpy(user_choice, strlwr(user_choice));
		for (i2 = 0; i2 <= 5; ++i2) {
			if (strcmp(user_choice, things[i2]) == 0) {
				is_there = 0;
				break;
			}
		}
		if (!is_there) {
			is_there = 1;
			for (i2 = 0; i2 <= 2; ++i2) {
				if (strcmp(user_choice, sh[i2]) == 0) {
					is_there = 0;
					break;
				}
			}
		}
		else {
			printf("You picked something out of things list!\n");
			goto again;
		}


		if (is_there) {
			strcpy(sh[i - 1], user_choice);
		}
		else {
			printf("You picked this thing before in %s!\n", ch);
			goto again;
		}
	}


}


void ab_cmp(void)
{

	for (i = 0; i <= 2; ++i) {
		for (i2 = 0; i2 <= 2; ++i2) {
			if (strcmp(group_a[i], group_b[i2]) == 0) {
				ab_haveit++;
				strcpy(ab_both[ab_haveit - 1], group_a[i]);
			}
		}
	}

	if (ab_haveit) {
		printf("Both groups have same %d elements:\n", ab_haveit);

		x = wherex();

		for (i = 0; i <= (ab_haveit - 1); ++i) {
			gotoxy(x, wherey());
			printf("%s  ", ab_both[i]);
			x = wherex() + 5;
		}
	}

	else
		printf("There's no similarity between A and B.\n");


}