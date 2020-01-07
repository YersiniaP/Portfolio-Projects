#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#pragma warning(disable : 4996)
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')             
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Calculates the levenshtein distance between two strings.
 * Source: https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C
 * @param string (user entered)
 * @param string (dictionary entry)
 * return: levenshtein distance (int) between param strings
 */
int levenshtein(char* s1, char* s2) {
	unsigned int x, y, s1len, s2len;
	s1len = strlen(s1);
	s2len = strlen(s2);
	unsigned int matrix[50][50];
	matrix[0][0] = 0;
	for (x = 1; x <= s2len; x++)
		matrix[x][0] = matrix[x - 1][0] + 1;
	for (y = 1; y <= s1len; y++)
		matrix[0][y] = matrix[0][y - 1] + 1;
	for (x = 1; x <= s2len; x++)
		for (y = 1; y <= s1len; y++)
			matrix[x][y] = MIN3(matrix[x - 1][y] + 1, matrix[x][y - 1] + 1, matrix[x - 1][y - 1] + (s1[y - 1] == s2[x - 1] ? 0 : 1));
	int distance = matrix[s2len][s1len];
	return distance;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
	// FIXME: implement
	map->size = 0;
	char* word = nextWord(file);

	while (word != NULL)
	{		
		hashMapPut(map, word, -1);

		free(word);

		word = nextWord(file);
	}
	free(word);
}

/**
 * Checks the spelling of the word provded by the user. If the word is spelled incorrectly,
 * print the 5 closest words as determined by a metric like the Levenshtein distance.
 * Otherwise, indicate that the provded word is spelled correctly. Use dictionary.txt to
 * create the dictionary.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
	

	printf("Starting main():\n");
    HashMap* map = hashMapNew(1000);

    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);

	

    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);

        // Implement the spell checker code here..


		/* Converts uppercase letters to lowercase. *
		 * Non-letters remain as 'typos'*/

		for (int i = 0; i < (strlen(inputBuffer)); i++) {
			if (inputBuffer[i] <= 90 && inputBuffer[i] >= 65) {
				int notCaps = tolower(inputBuffer[i]);
				inputBuffer[i] = notCaps;
			}
		}

		/* Any cased user entry of 'quit' exits program*/
        if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
			break;
        }

		/*Array to hold 5 closest word suggestions, array element position, and levenshtein distance */
		char* topFive[5] = { 0, 0, 0, 0, 0 };
		int position = 0;
		int threshhold = 0;
	
		for (int i = 0; i < map->capacity; i++)
		{
			struct HashLink* tempLink = map->table[i];

			while (tempLink != 0) {

				int distance = levenshtein(inputBuffer, tempLink->key); 

				//assigns each link's value to the L. distance
				hashMapPut(map, tempLink->key, distance);

				tempLink = tempLink->next; //moves through bucket
			}
		}

		while (topFive[4] == 0) //while array isn't full
		{
			for (int i = 0; i < map->capacity; i++)
			{
				struct HashLink* tempLink = map->table[i];

				while (tempLink != 0 && position < 5) {
					if (threshhold == 0)
					{
						if (tempLink->value == 0)
						{
							printf("The inputted word \'%s\' is spelled correctly.\n", inputBuffer);
							return;
						}
					}
					else if (tempLink->value == threshhold)
					{
						topFive[position] = tempLink->key;
						position++; //advances array element position
					}
					tempLink = tempLink->next;
				}
			}
			threshhold++; //increases L. distance threshhold for closest word suggestions.
		}		
		
		printf("The inputted word \'%s\' is spelled incorrectly. ", inputBuffer);
		printf("Did you mean:\n");
		for (int i = 0; i < 5; i++)
		{
			printf("%s\n", topFive[i]);
		}
    }

    hashMapDelete(map);
    return 0;
}
