
///Anneliese English
//record each character, number, word, and how frequent they appear
#include<string>
#include<vector>
#include<iostream>
#include<cctype>
#include<algorithm>
#include<sstream>
using namespace std;

typedef pair<string, int> WordFreq;	//linking two data types to make code more readable

bool checkWord(const string& word, vector<string>& words, vector<int>& frequencies) {	//funtion to see if word exists and update frequency
	for (size_t i = 0; i < words.size(); ++i) {	//size_t reps the num of elements in words vector
		if (words[i] == word) {	//loop through & if word exists inc freq and update
		   ++frequencies[i];
		   return true;	//word found
		}
	}
	return false;	//word not found
}

vector<WordFreq> sortFreq(const vector<string>& words, const vector<int>& frequencies) {  //sorts frequency by descending order
	vector<WordFreq> wordFreqs;
	for (size_t i = 0; i < words.size(); ++i) {
	   wordFreqs.push_back(make_pair(words[i], frequencies[i]));	//adds new pair to end of vector
	}

	sort(
	 wordFreqs.begin(),	//beginning of vector
	 wordFreqs.end(),   //end of vector
	 [](const WordFreq &a, const WordFreq &b) {  //lambda function
	   return a.second > b.second;	//sorting terms
	});

	return wordFreqs;
}

void results(const vector<WordFreq>& wordFreqs, const string& label) {	//function to display top 10
	cout << "\nTop 10: " << label << endl;	//label is whether to display char, int, or strings
	size_t limit = min((size_t)10, wordFreqs.size());   //no more than 10

	for (size_t i = 0; i < limit; ++i) {   //list the results
	   cout << wordFreqs[i].first << "- " << wordFreqs[i].second << endl;
	}
}

int main() {

	vector<string> words;	//vector to record input strings
	vector<int> numWords;	//storing frequency of words

	vector<string> numbers;
	vector<int> numNumbers;

	vector<string> chars;
	vector<int> numChars;

	string input;
	cout << "Please enter the input. When finished, press enter on an empty line: " << endl;	//ask for user input

	while (getline(cin, input)) {	//process inputs
		if(input.empty()) break; //if input is empty stop processing

		stringstream ss(input);
		string segment;

		while (ss >> segment) {
			string word = segment;
			transform(word.begin(), word.end(), word.begin(), ::tolower);	//make lowercase 

		if(all_of(segment.begin(), segment.end(), ::isdigit)) {	//segment is number
			if (!checkWord(segment, numbers, numNumbers)) {
				numbers.push_back(segment);
				numNumbers.push_back(1);
			}
		} else if (all_of(segment.begin(), segment.end(), ::isalpha)) {	//segment is word
			if (!checkWord(word, words, numWords)) {
				words.push_back(word);
				numWords.push_back(1);
			}
		} else {	//special chars
			for (char ch : segment) {	// does it have special characters
			   if (!isspace(ch)) {	//ignore spaces
				string chStr(1, ch);	//convert char to string
			   if (!checkWord(chStr, chars, numChars)) {
				chars.push_back(chStr);
				numChars.push_back(1);
	    }
	  }
	 }
      }
   }
}
	vector<WordFreq> wordSorted = sortFreq(words, numWords);	//sort by each frequency
	vector<WordFreq> numSorted = sortFreq(numbers, numNumbers);
	vector<WordFreq> charSorted = sortFreq(chars, numChars);

	results(wordSorted, "Words");		//display results
	results(numSorted, "Numbers");
	results(charSorted, "Characters");

	return 0;
}






