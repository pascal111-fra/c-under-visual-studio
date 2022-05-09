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


void do_in_nums(const char*);
void enter_num(const char*, float*);

float firstnum,
secondnum, result;
char arr01[4][14 + 1] = { "Addition",
"Subtraction", "Multiplication", "Division" };
int oper_choice;
int secondtry;


int main(void)
{

	int i, x;

again:

	firstnum = 0;
	secondnum = 0;
	secondtry = 0;

	system("cls");

	printf("Choose arithmetic operation\n");
	printf("you like to do:\n\n");

	x = wherex();

	for (i = 1; i <= 4; ++i) {

		gotoxy(x, wherey());
		printf("%d) %s", i, arr01[i - 1]);
		x = wherex() + 5;
	}


oper_again:

	printf("\n? ");

	scanf("%d", &oper_choice);
	fflush2();
	if (oper_choice < 1 || oper_choice>4) {
		printf("Your choice is out of the supposed range!\n");
		goto oper_again;
	}


	enter_num("first number", &firstnum);
	enter_num("second number", &secondnum);

	do_in_nums(arr01[oper_choice - 1]);

	printf("Do you like to do more (y/n)? ");
	if (tolower(getchar()) == 'y') {
		fflush2();
		goto again;
	}


	fflush2();
	return 0;
}


void enter_num(const char* sh, float* num)
{

	char is_zero;

num_again:

	printf("\nEnter %s for %s : ", sh, arr01[oper_choice - 1]);
	scanf("%f", num);
	fflush2();
	if (*num == 0) {
		printf("Is your input a zero (y/n)? ");
		is_zero = getchar();
		fflush2();
		if (tolower(is_zero) == 'n')
			goto num_again;
	}

	if (secondtry &&
		oper_choice == 4 && *num == 0) {
		printf("You can't divide by zero!\n");
		goto num_again;
	}

	secondtry = 1;

}


void do_in_nums(const char* sh)
{

	if (strcmp(sh, arr01[0]) == 0)
		result = firstnum + secondnum;
	else {
		if (strcmp(sh, arr01[1]) == 0)
			result = firstnum - secondnum;
		else {
			if (strcmp(sh, arr01[2]) == 0)
				result = firstnum * secondnum;
			else {
				if (strcmp(sh, arr01[3]) == 0)
					result = firstnum / secondnum;
			}
		}
	}


	printf("\nNumbers total is: %g\n\n", result);


}



