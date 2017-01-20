#include <stdio.h>
#include <conio.h>


void shift(char* word, int key)
{
	int i = 0;
	char character = word[i];
	while (character != '\0')
	{
		if (character >= 65 && character <= 90)
		{
			word[i] = (word[i] + key);
			if (word[i] > 90) word[i] = (word[i] % 90) + 65;
		}
	
	if (character >= 97 && character <= 122)
	{
		word[i] = (word[i] + key);
		if (word[i] > 122) word[i] = (word[i] % 122) + 97;
	}
	i++;
	character = word[i];
	}
}

int main()
{
	char word[50] = "Ceasers Cipher Shift Cipher";
	
	shift(word, 3);
	printf("Encrypted Message: %s\n", word);
	shift(word, -3);
	printf("Decrypted Message: %s\n", word);
	

	return 0;
}