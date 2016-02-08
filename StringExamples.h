/*
 * StringExamples.h
 *
 *  Created on: Feb 2, 2016
 *      Author: carolsusieo
 */

#ifndef STRINGEXAMPLES_H_
#define STRINGEXAMPLES_H_

//namespace std {

class StringExamples {
public:
	StringExamples();
	virtual ~StringExamples();
	void main(char** args);


private:
	void reverseWords(char* s);
	char* reverseWordsInPlace(string* bufin);
	char* iterativeReverse(char* intext, int lindex, int rindex);
	string reverseRecursively(string str);
	string* removeWhitespaceInplace(string intext);
	string* removeDuplicateChars(string intext);
	char firstNonRepeatedCharacter(string in);


};

//} /* namespace std */


#endif /* STRINGEXAMPLES_H_ */
