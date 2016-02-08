/*
 * StringExamples.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: carolsusieo
 */
#include <iostream>

using namespace std;
#include <stdio.h>

#include <string>

StringExamples::StringExamples() {
	// TODO Auto-generated constructor stub

}

StringExamples::~StringExamples() {
	// TODO Auto-generated destructor stub
}

void StringExamples::main(char** args) {
		string str = "hello reverse words hello";
		cout << str;
		char* in = (char*)str.c_str();
		reverseWords(in);
		cout << "Reverse Recursively";
		reverseRecursively(str);
		cout << (str);
		string str2 = "Reverse words in-place";
		cout << str2;
		in = (char*) str2.c_str();
		cout << (reverseWordsInPlace(in));
		string str3 = "remove whitespace\t\t\tin place";
		cout << str3;
		cout << (removeWhitespaceInplace(str3));
		string str4 = "AAA BBB CC D EE A";
		cout << "remove duplicate characters" + str4;
		cout << (removeDuplicateChars(str4));

		char c=firstNonRepeatedCharacter(str);
        cout << "\nThe first non repeated character in '" << str << "' is :  " << c;
	}


void StringExamples::reverseWords(char* sentence)
{
	int index = strlen(sentence) - 1,hold,last = '\0';
	while (index >= 0)
	{
		while (index>=0 && sentence[index] != ' ')
		index--;

	/* You can print the whitespace later*/

	hold = index - 1;  // This keeps track of the last character
					   // of preceding word

	index++; //character after space

	while (sentence[index] != last)
	{
			cout << sentence[index];
			index++;
		}
	last = ' ';
	index = hold;

		/* Dont print space after 1st word*/
	if(index > 0)
		cout<<" ";
	}
}

// reverse all words in place by first reversing entire string, then word by word
char* StringExamples::reverseWordsInPlace(string* bufin)
{
	int lindex = 0;

	int rindex = bufin->length() - 1;
	char* hold = bufin->c_str();
	if (rindex > 1)
	{
		//reverse complete phrase
		hold = iterativeReverse(hold,0,rindex);

		//reverse each word in resultant reversed phrase
		for (rindex = 0; rindex <= bufin->length(); rindex++)
		{
			if (rindex == bufin->length() || hold[rindex] == ' ')
			{
				hold = iterativeReverse(hold, lindex, rindex - 1);
				lindex = rindex + 1;
			}
		}
	}
	return hold;
}

char* StringExamples::iterativeReverse(char* intext, int lindex, int rindex)
{
	char tempc;
	while (lindex < rindex)
	{
		tempc = intext[lindex];
		intext[lindex++] = intext[rindex];
		intext[rindex--] = tempc;
	}
	return intext;
}
/*
string StringExamples::reverseRecursively(string &s)
{
	if( s.length() == 0 )  // end condtion to stop recursion
		return "";

	string last(1,s[s.length()-1]);  // create string with last character
	string reversed = reverseRecursively(s.substr(0,s.length()-1));
	return last+reversed; // Make he last character first
}
*/
string StringExamples::reverseRecursively(string str){
    if (str.length() == 1) {
        return str;
    }else{
        return reverseRecursively(str.substr(1,str.length())) + str.at(0);
    }
}
string* StringExamples::removeWhitespaceInplace(string intext){return &intext;}
string* StringExamples::removeDuplicateChars(string intext){return &intext;}
char StringExamples::firstNonRepeatedCharacter(string in){ return 0;}

/*
	static private StringBuffer removeWhitespaceInplace(StringBuffer intext)
	{
		int sindex= 0;
		int orgindex = 0;
	    while (orgindex < intext.length())
	    {
	    	if(!(Character.isWhitespace(intext.charAt(orgindex)))){
	        	intext.setCharAt(sindex++,intext.charAt(orgindex));

	        }
	    	orgindex++;
	    }
	    intext.setLength(sindex);
	    return intext;
	}
	//("AAA BBB" -> "A B")
	static private StringBuffer removeDuplicateChars(StringBuffer intext)
	{
		int sindex= 0;
		char temp = intext.charAt(sindex++);
		int orgindex = sindex + 1;
	    while (orgindex < intext.length())
	    {
	    	if(temp != intext.charAt(orgindex)){
	    		temp = intext.charAt(orgindex);
	        	intext.setCharAt(sindex++,temp);
	        }
	    	orgindex++;
	    }
	    intext.setLength(sindex);
	    return intext;

	}

	static private Character firstNonRepeatedCharacter(String str)
	{
        HashMap<Character,Integer>  characterhashtable=
                     new HashMap<Character ,Integer>();
        int i,length ;
        Character c ;
        length= str.length();  // Scan string and build hash table
	    for (i=0;i < length;i++)
	    {
	        c=str.charAt(i);
	        if(characterhashtable.containsKey(c))
	        {
	            // increment count corresponding to c
	            characterhashtable.put(  c ,  characterhashtable.get(c) +1 );
	        }
	        else
	        {
	            characterhashtable.put( c , 1 ) ;
	        }
	    }
	    // Search characterhashtable in in order of string str

	    for (i =0 ; i < length ; i++ )
	    {
	        c= str.charAt(i);
	        if( characterhashtable.get(c)  == 1 )
	        return c;
	    }
	    return null ;
	}
*/
int main(int num, char** args)
{
	StringExamples test = new StringExamples(args);
	test.main(args);
	return 0;
}
