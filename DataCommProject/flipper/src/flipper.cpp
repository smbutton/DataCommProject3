#include "..\include\flipper.h"
#include <time.h>
#include <iostream>
#include <iterator>
#include <deque>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
deque<unsigned char> getMessage(){

 // cin >> noskipws;

// use stream iterators to copy the stream to a string
 // istream_iterator<char> it(cin);
 // istream_iterator<char> end;
 // string results(it, end);
  //  cout<< results;

  //if(cin == null){
  ////  cout<<"Please type the message to encode";
  //  cin>>

 //}

    deque<unsigned char> result;
    result.push_back('a');
    result.push_back('b');
    result.push_back('c');
    result.push_back('d');
    result.push_back('d');
    result.push_back('f');
    result.push_back('h');
    result.push_back('j');
    result.push_back('r');
    result.push_back('c');
result.push_back('a');
    result.push_back('b');
    result.push_back('c');
    result.push_back('d');
    result.push_back('d');
    result.push_back('f');
    result.push_back('h');
    result.push_back('j');
    result.push_back('r');
    result.push_back('c');
    return result;

}

short flipOrNoFlip(short bitToFlip){
    short result = bitToFlip;
    //srand(time(NULL));
    int theGuess = rand()%125;
    //cout<<"\nTHE GUESS!!!!!"<<theGuess<<"WAS THAT!\n";
    int theAnswer = 47;
    if(theGuess == theAnswer){
        result = result xor 1;
    }

    return result;
}

unsigned char flipByte(unsigned char data){

    //data = 'a';
   // short orig = 0;
  //  short message[7];
    unsigned short input[8];
    char newChar;

    //cout<<"MyData "<<data<<"which is "<<data<<"\n";

for(int i =0; i< 8;i++){
unsigned char temp = (data<< (7-i));
temp = (temp >> (7-i));
temp = (temp >> (i));
input[7-i]=temp;
}

for(int i =0;i<8 ; i++){
cout<<input[i];
input[i] = flipOrNoFlip(input[i]);

}
cout<<"\n";
for(int i =0;i<8 ; i++){
cout<<input[i];
}
cout<<"\n";


int result = 0;
for(int i =0; i< 8; i++){
result += pow(2.0, (double)i)*(int)input[(7-i)];
}
newChar = (char)result;
return newChar;
}

deque<unsigned char> flipMessage(deque<unsigned char> message){
deque<unsigned char> flippingResults;
while(message.size()!=0){
unsigned char myData = message.front();
message.pop_front();
flippingResults.push_back(flipByte(myData));
}
return flippingResults;
}

void printOut(deque<unsigned char> x){
while(x.size()!=0){
cout<< x.front();
x.pop_front();
}
}


int main ()
{
    srand(time(0));
    deque<unsigned char> message;
    deque<unsigned char> erroredOutput;
    message = getMessage();



    erroredOutput = flipMessage(message);
    printOut(erroredOutput);

    return 0;
}

