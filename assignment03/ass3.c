#include <stdio.h>
//Diana Lin, ID: 260625972
int main(void) {

	//to ensure ample memory
	char plaintext[300];

    printf("Sentence: ");
	fgets(plaintext, 299, stdin);

	int key;

	//encryption key must be between 1 and 25,
	//if otherwise--keep asking until a valid key is given!
	do {
        printf("Key: ");
		scanf("%d", &key);

	} while (key < 1 || key > 25);

	//to ensure ample memory
	char cipher[300];

	//initialize
	char letter = ' ';
	int count = 0;
	char newLetter;
	int newKey;

	//encode the original word
	while(letter != '\0')
	{
		letter = plaintext[count];
		if (letter != ' ') {
			//use right shift to avoid negative numbers,
			//so 26 minus key gives appropriate left shift equivalent
			newKey = 26 - key;
			//for lower case letter
			if(letter >= 97 && letter <= 122) {
				newLetter = letter - 'a';
				newLetter = (newLetter + newKey) % 26;
				newLetter = newLetter + 'a';
				cipher[count] = newLetter;
			}
			//for upper case letters
			if(letter >= 65 && letter <= 90) {
				newLetter = letter - 'A';
				newLetter = (newLetter + newKey) % 26;
				newLetter = newLetter + 'A';
				cipher[count] = newLetter;
			}
			//special characters will not be tested
			//so input must fall in one of the two above categories

		}
        
		else
		{
			//spaces stay spaces
			cipher[count] = letter;
		}
		count++;
	}

	//time to decrypt the encrypted message
	//to ensure ample memory
	char decrypt[300];

	//reset letter so same variable can be used
	letter = ' ';

	//reset count so same variable can be used
	count = 0;
	while (letter != '\0') {
		letter = cipher[count];
        
		if (letter != ' ') {
			//decryption is a right shift, no need to create a new key like with the encryption.

			//for lower case letters
			if(letter >= 97 && letter <= 122) {
				newLetter = letter - 'a';
				newLetter = (newLetter + key) % 26;
				newLetter = newLetter + 'a';
				decrypt[count] = newLetter;
			}

			//for upper case letters
			if(letter >= 65 && letter <= 90) {
				newLetter = letter - 'A';
				newLetter = (newLetter + key) % 26;
				newLetter = newLetter + 'A';
				decrypt[count] = newLetter;
			}
		}
        
		else
		{
			//spaces stay spaces
			decrypt[count] = letter;
		}

		count++;
	}

	//print everything necessary
	printf("Original message: %s", plaintext);
	printf("Encrypted message: %s\n", cipher);
	printf("Decrypted message: %s\n", decrypt);

    return 0;

}
