/*
//	These iterations show the slow learning process of my poor brain.
//  The goal was to implement and learn a string copy 'while (*s++ = *t++)'
*/
#include <stdio.h>
#include <stdlib.h>


/*
  //won't work b/c of error: lvalue required as increment operand 
int main()
{
	char * word = "Sorrell";
	char newWord[sizeof(word)];
	while (*newWord++ = *word++ ) {};
	printf("word:%s and newWord:%s\n", word, newWord);
	return 0;
}
*/


/*
  //works, but not that elegant
int main()
{
	char * word = "Sorrell";
	char newWord[sizeof(word)];
	int i = 0;
	while (newWord[i] = *word++ ) {i++;};
	word = &word[-sizeof(word)];
	printf("word:%s and newWord:%s\n", word, newWord);
}
*/

/*
  // works ... and how!  but maybe even LESS elegant
int main()
{
	char * word = "Sorrell";
	char * newWord = (char*) malloc (sizeof(word));
	char *p = &newWord[0];
	char *q = &word[0];
	while (*p++ = *q++) {};
	printf("%s\n", word);
	printf("%s\n", newWord);
}
*/


/*
  // finally, the desired outcome
int main()
{
	char * word = "Sorrell";
	char * newWord = (char*) malloc (sizeof(word));
	while (*newWord++ = *word++) {};
	word = &word[-sizeof(word)];		//reset the pointer back to the beginning mem location
	newWord = &newWord[-sizeof(newWord)];	// same as above
	printf("word:%s and newWord:%s\n", word, newWord);
}
*/