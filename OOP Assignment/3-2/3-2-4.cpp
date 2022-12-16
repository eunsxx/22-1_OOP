#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class wNode {
public:
	char word[100] = { 0, };
	wNode() {
		next = nullptr;
	}
	char* getWord() { return word; } // node의 단어 return
	wNode* getNext() { return next; } // node의 다음 단어 return
	void setWord(char* word) { strcpy(this->word, word); } // node의 단어 설정
	void setNext(wNode* next) { this->next = next; } // node의 다음 단어 설정

	wNode* next;
};

class aNode {
public:
	// char *value = new char;
	wNode* nextWord; // 다음 단어
	aNode* nextAlphabet; // 다음 알파벳
	char alphabet;

	aNode() {
		nextAlphabet = nullptr;
		nextWord = nullptr;
		alphabet = '\0';
	}

	aNode(char ch) { alphabet = ch; }

	char getAlphabet() { return alphabet; }
	aNode* getNextAlphabet() { return nextAlphabet; }
	wNode* getNextWord() { return nextWord; }

	void setAlphabet(char ch) { alphabet = ch; }
	void setNextAlphabet(aNode* nextAlphabet) { this->nextAlphabet = nextAlphabet; }
	void setNextWord(wNode* nextWord) { this->nextWord = nextWord; }
};

class AL { // 알파벳 리스트
private:
	aNode* alphabetHead; // 알파벳 리스트의 head
public:
	AL() {
		alphabetHead = nullptr;
	}
	aNode* getAlphabetHead() { return alphabetHead; }
	void insertAlphbetList(char alphabet);
};

void AL::insertAlphbetList(char alphabet) {
	aNode* pNew = new aNode;
	pNew->setAlphabet(alphabet);
	if (alphabetHead == nullptr) {
		alphabetHead = pNew;
	}
	else {
		aNode* curr;
		curr = alphabetHead;
		while (true) {
			if (curr->getNextAlphabet() == nullptr) break;
			curr = curr->getNextAlphabet();
		}
		curr->setNextAlphabet(pNew);
	}
}

class WL { // 단어 리스트
private:
	AL* ap;
	wNode* wordHead;
public:
	WL() {
		wordHead = nullptr;
	}
	wNode* getWordHead() { return wordHead; } // 단어 리스트의 head
	void insertWord(wNode* pNew, aNode* alphabetHead);
	void sort() {
		wNode* wh = getWordHead();
		wNode* temp = NULL;

		char tempName[100] = { 0, };

		if (getWordHead() == nullptr) {
			return;
		}
		cout << "wh->word = " << wh->next << endl;
		for (; wh->getNext() != NULL; wh = wh->getNext()) {
			for (temp = wh->getNext(); temp != NULL; temp = temp->getNext()) {
				cout << "wh->word = " << wh->word << endl;
				cout << "temp->word = " << temp->word << endl;
				if (strcmp(wh->word, temp->word) < 0) {
					strcpy_s(tempName, wh->word);
					strcpy(wh->word, temp->word);
					strcpy(temp->word, tempName);
				}
				cout << "wh->word = " << wh->word << endl;
				cout << "temp->word = " << temp->word << endl;
			}
		}
	}

};

void WL::insertWord(wNode* pNew, aNode* alphabetHead) {
	char temp[100];

	if (alphabetHead->getNextWord() == nullptr) {
		alphabetHead->setNextWord(pNew);
	}
	else {
		wNode* wordListCurr;
		wordListCurr = alphabetHead->getNextWord();
		while (true) {
			if (wordListCurr->getNext() == nullptr) break;
			if (_stricmp(wordListCurr->getWord(), wordListCurr->getNext()->getWord()) > 0) {
				strcpy(temp, wordListCurr->next->word);
				strcpy(wordListCurr->next->word, wordListCurr->word);
				strcpy(wordListCurr->word, temp);
			}
			wordListCurr = wordListCurr->getNext();
		}
		wordListCurr->setNext(pNew);
	}
}

class LL {
private:
	WL wl;
public:
	int insert(char* input, AL al);
	void print(AL al);
	void sort(AL al);
};

int LL::insert(char* input, AL al) {
	char arr[100];
	aNode* alphabetCurr;
	alphabetCurr = al.getAlphabetHead();

	while (true) {
		for (int i = 0; i < strlen(input); i++) {
			if (input[i] >= 'a' && input[i] <= 'z') {
				arr[i] = input[i] - 32;
			}
			else arr[i] = input[i];
		}
		if (alphabetCurr->getAlphabet() == arr[0]) {
			wNode* newWord = new wNode;
			newWord->setWord(input);
			wl.insertWord(newWord, alphabetCurr);
			break;
		}
		if (alphabetCurr->getNextAlphabet() == nullptr) {
			break;
		}
		alphabetCurr = alphabetCurr->getNextAlphabet();
	}

	return 0;
}

void LL::print(AL al) {
	aNode* alphbetCurr = al.getAlphabetHead();
	wNode* pW;
	while (true) {
		pW = alphbetCurr->getNextWord();
		if (pW) {
			cout << alphbetCurr->getAlphabet() << " -> ";
			while (pW) {
				cout << pW->getWord();
				if (pW->getNext() != nullptr) {
					cout << " -> ";
				}
				pW = pW->getNext();
			}
			cout << endl;
		}
		if (alphbetCurr->getNextAlphabet() == nullptr) break;
		alphbetCurr = alphbetCurr->getNextAlphabet();
	}
	return;
}

void LL::sort(AL al) {
	aNode* alphbetCurr = al.getAlphabetHead();
	wNode* pW;
	wNode* move;
	wNode* temp = new wNode;
	while (alphbetCurr != nullptr) {
		pW = alphbetCurr->getNextWord();
		if (pW) {
			while (pW->next != nullptr) {
				move = pW->next;
				while (move != nullptr) {
					if (_stricmp(pW->word, move->word) > 0) {
						strcpy(temp->word, pW->word);
						strcpy(pW->word, move->word);
						strcpy(move->word, temp->word);
					}
					move = move->getNext();
				}
				pW = pW->getNext();
			}
		}
		alphbetCurr = alphbetCurr->getNextAlphabet();
	}
	return;
}
int main() {
	ifstream readFile;
	char str[100] = { 0, };
	char arr[100] = { 0, };
	LL link;
	AL alpha;
	WL wordlist;
	readFile.open("Assignment.txt");

	if (readFile.fail()) {
		cout << "error" << endl;
		return 0;
	}

	for (int i = 'A'; i <= 'Z'; i++) {
		alpha.insertAlphbetList(i);
	}

	while (readFile.getline(str, 100)) {
		link.insert(str, alpha);
	}

	link.sort(alpha);

	link.print(alpha);
	return 0;
}