/*
This progrem is fixing a text taken from the user, in according to given laws - Upper case after a point, no number, capital in quates.
*/

#include <stdio.h>
#include <ctype.h>

enum status {SEN_BEGIN, IN_SEN, QUATE};

int main()
{
	int c;
	enum status state = SEN_BEGIN;	
	printf("Hello there! Please enter your text\n");

	while ((c = getchar()) != EOF)
	{
		switch (state){
			case SEN_BEGIN:
				state = IN_SEN; /*It is entering a sentence, with two exeptions*/
				if (islower(c))
					putchar(toupper(c));
				else if (c == '\"'){
					state = QUATE;
					putchar(c);
				}	
				else if (isdigit(c))
					putchar('\0');
				else if (c == '.'){
					state = SEN_BEGIN;
					putchar(c);
				}
				else if (c == ' ' || c == '\n' || c == '\t'){ /*Handling the capital in the beginnig of a sentence*/
					state = SEN_BEGIN;
					putchar(c);
				}
				else
					putchar(c);						
				break;
			
			case IN_SEN:
				if (c == '.'){
					state = SEN_BEGIN;
					putchar(c);
				}
				else if (c == '\"'){
					state = QUATE;
					putchar(c);
				}
				else if (isupper(c))
					putchar(tolower(c));
				else if (isdigit(c))
					putchar('\0');
				else
					putchar(c);
		
				break;

			case QUATE:
				if (c != '\"'){ /*handling the exit from a quate*/
					if (islower(c))
						putchar(toupper(c));
					else if (isdigit(c))
						putchar('\0');
					else
						putchar(c);
				}
				else{
					state = IN_SEN;
					putchar(c);
				}	
				break;
		}
	}
	return 0;
}


