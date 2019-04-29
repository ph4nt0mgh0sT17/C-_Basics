#include <iostream>
#include <string>

using namespace std;


void BruteForce(string sample, string sentence)
{
	int sentenceLength = sentence.length();
	int sampleLength = sample.length();

	int counter = 0;


	for (int i = 0; i <= sentenceLength - sampleLength; i++)
	{
		int j;

		for (j = 0; j < sampleLength; j++)
		{
			if (sentence[i + j] != sample[j])
			{
				counter++;
				break;
			}		

			else
			{
				counter++;
			}
		}

		if (j == sampleLength)
		{
			cout << "Seached word was found. Number of comparings: " << counter;
		}
	}
}

void BruteForceXD(string sample, string sentence)
{
	int sentenceLength = sentence.length();
	int sampleLength = sample.length();

	int counter = 0;


	for (int i = 0; i <= sentenceLength - sampleLength; i++)
	{
		int j;

		for (j = 0; j < sampleLength; j++)
		{
			if (sentence[i + j] != sample[j])
			{
				counter++;
				i = i + j;
				break;
			}

			else
			{
				counter++;
			}
		}

		if (j == sampleLength)
		{
			cout << "Seached word was found. Number of comparings: " << counter;
		}
	}
}


int main()
{
	string searchedWord = "EC";
	string sentence = "EEEEEEEC";
	BruteForceXD(searchedWord, sentence);
	getchar();
	return(0);
}
