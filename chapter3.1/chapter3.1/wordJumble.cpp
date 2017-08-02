#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;
typedef unsigned int uInt;

int main() {
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall" , "do you feel your head banging against something?"},
		{"glasses" , "these might help you see the answer."},
		{ "labored" , "going slowly, isnt it?"},
		{"persistent", "keep at it."},
		{"jumble", "its what the game is all about."}
	};

	srand(static_cast<uInt> (time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];
	string theHint = WORDS[choice][HINT];

	string jumble = theWord;
	int length = jumble.size();

	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	cout << "\t\t\t Welcome to word jumble! \n\n";
	cout << "Unscramble the word. \n";
	cout << "Enter 'hint' for a hint. \n";
	cout << "Enter 'quit' to quit the game. \n\n";
	cout << "the jumble is: " << jumble;

	string guess;
	cout << " \n\n your guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit")){
		if (guess == "hint") {
			cout << theHint;
		}
		else {
			cout << "sorry, thats not it.";
		}
		cout << "\n\n your guess: ";
		cin >> guess;
}
	if (guess == theWord) {
		cout << "\n you guessed right! \n";
	}
	cout << "thanks for playing! \n";
	system("PAUSE");
	return 0;

}