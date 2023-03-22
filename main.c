/*
Assignment 1 - C
Word matching game
Author: @Moises Munaldi
ID: R00225292
Last update: 22/03/2023

disclaimer: the hard mode is not implemented, but there is a "Instruction option :)"

*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

// #define NUMBER_OF_WORDS_IN_LIST 5757;
// #define NUMBER_OF_CHARS_IN_ONE_WORD 6;

int numberOfWords = 5757;
int wordList = 6;

/*
Steps:
1 - method which reads the user's guess (input)
  1.2 - Put in lower case format
  1.3 - Loop for each caracter
  1.4 - Check the user's guess is in correct format
  1.5 - Length of the input value
  1.6 - Print the users guess

2 - method which compare the users guess and the correct answer
  2.2 - Array to hold correctly guesse
  2.3 - For loop to intarete
  2.4 - For loop compares each char
  2.5 - Print letter, check if the letter is already in the array and add the caracter.
  2.6 - Print messages

3 - Initate the game
  * make one method/function for each menu item
  3.2 - Make a menu
  3.3 - Give option to play again
  3.4 - implement the game

*/

// 1
void getUserGuess(char *usersGuess)
{
  int nm = 0;
  printf("\nEnter a Guess: ");
  scanf("%s", usersGuess);
  for (int nm = 0; usersGuess[nm] != '\0'; nm++)
  {
    usersGuess[nm] = tolower(usersGuess[nm]);
  }
  for (nm = 0; usersGuess[nm] != '\0'; ++nm)
    ;
  while (isdigit(usersGuess[nm]) || nm != 5)
  {
    printf("\nformat is not valid, please enter a word with five caracters: ");
    scanf("%s", usersGuess);
    for (nm = 0; usersGuess[nm] != '\0'; ++nm)
      ;
  }
  printf("\nYour guess: %s\n", usersGuess);
  fflush(stdin);
}

bool isUserGuessCorrect(char usersGuess, char *correctGuess)
{
  return usersGuess == correctGuess[0] || usersGuess == correctGuess[1] || usersGuess == correctGuess[2] ||
         usersGuess == correctGuess[3] || usersGuess == correctGuess[4];
}
// 2
void compareGuesses(char *usersGuess, char *correctGuess)
{
  char characterPos[5];
  int j = 0;
  for (int i = 5; i > 0; i--)
  {
    printf("\nYou have %d guesses remaining", i);
    getUserGuess(usersGuess);
    for (int i = 0; usersGuess[i] != '\0'; i++)
    {
      if (usersGuess[i] == correctGuess[i])
      {
        printf("%c", usersGuess[i]);
        if (usersGuess[i] != characterPos[0] && usersGuess[i] != characterPos[1] && usersGuess[i] != characterPos[2] && usersGuess[i] != characterPos[3] && usersGuess[i] != characterPos[4])
        {
          characterPos[j] = usersGuess[i];
          j++;
        }
      }
      else
      {
        printf("-");
      }
      if (isUserGuessCorrect(usersGuess[i], correctGuess))
      {
        if (usersGuess[i] != characterPos[0] && usersGuess[i] != characterPos[1] && usersGuess[i] != characterPos[2] && usersGuess[i] != characterPos[3] && usersGuess[i] != characterPos[4])
        {
          characterPos[j] = usersGuess[i];
          j++;
        }
      }
    }
    printf("\nCorrectly guessed letters: \n");
    for (int i = 0; i < 5; i++)
    {
      printf("%c ", characterPos[i]);
    }
    if (usersGuess[1] == correctGuess[1] && usersGuess[2] == correctGuess[2] && usersGuess[3] == correctGuess[3] && usersGuess[4] == correctGuess[4] && usersGuess[0] == correctGuess[0])
    {
      printf("\nCongratulation! You won the game.");
      break;
    }
  }
}

void printMenu()
{

  printf("    ********************** Welcome! ********************* \n");
  printf("    *                 Word Matching Game                 *\n");
  printf("    * 1.Start a new game                                 *\n");
  printf("    * 2.Hard mode                                        *\n");
  printf("    * 3.Instructions                                     *\n");
  printf("    * 4.Quit                                             *\n");
  printf("    **************************************************** \n");
  printf("Please choose an option [1 - 4]:\n");
}

// char *generateCorrectGuess()
// {
//   // 3.4
//   char word[numberOfWords][wordList];
//   time_t tm;
//   // change random value
//   srand((unsigned)time(&tm));
//   // random int
//   int random = rand() % numberOfWords;
//   char *correctGuess;
//   // access the .txt
//   load_word_list(word);
//   char *usersGuess = malloc(10);
//   return word[random + 1];
// }

void startGame()
{
  printf("Start a new game:\n");
  int playAgain;
  do
  {
    // generateCorrectGuess();
    //  3.4
    char word[numberOfWords][wordList];
    time_t tm;
    // change random value
    srand((unsigned)time(&tm));
    // random int
    int random = rand() % numberOfWords;
    char *correctGuess;
    // access the .txt
    load_word_list(word);
    char *usersGuess = malloc(10);
    // assigned random word
    correctGuess = word[random + 1];
    // compare functions
    compareGuesses(usersGuess, correctGuess);
    printf("\nCorrect word: %s\n", correctGuess);
    printf("Do you want to play again? [1 - YES] : \n");
    scanf("%d", &playAgain);
  } while (playAgain == 1);
  printf("    **************************************************** \n");
  printf("    *           Thanks for playing :) BYE BYE           *\n");
  printf("    **************************************************** \n");
  exit(0);
}

void instructions()
{
  int subOption = 1;
  printf("Instructions:\n");
  printf("    ***************************************************** \n");
  printf("    *                 Word Matching Game                 *\n");
  printf("    * You have 5 chance to guess the right word          *\n");
  printf("    * Every right letter guessed will be displayed       *\n");
  printf("    * The game only accpets 5 letter word                *\n");
  printf("    * Good luck :)                                       *\n");
  printf("    ***************************************************** \n");
  printf("Press 1 to return:\n");
  scanf("%d", &subOption);
}

int main()
{
  int option = 1;
  while (option != 0)
  {
    printMenu();
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      startGame();
      break;
    case 2:

      break;
    case 3:

      instructions();

      break;
    case 4:
      printf("    **************************************************** \n");
      printf("    *           Thanks for playing :) BYE BYE           *\n");
      printf("    **************************************************** \n");
      exit(0);
      option = 0;
      break;
    }
  }
  return 0;
}