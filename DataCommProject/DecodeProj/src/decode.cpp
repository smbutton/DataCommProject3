#include "..\include\decode.h"
#include <iostream>
#include <iterator>
#include <deque>
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
    result.push_back(4);
    result.push_back(216);
    result.push_back(9);
    result.push_back(197);
    result.push_back(0);
    result.push_back(204);
    result.push_back(0);
    result.push_back(204);
    result.push_back(13);
    result.push_back(207);
    result.push_back(8);
    result.push_back(247);
    result.push_back(13);
    result.push_back(207);
    result.push_back(13);
    result.push_back(242);
    result.push_back(0);
    result.push_back(204);
    result.push_back(8);
    result.push_back(212);
    result.push_back(4);
    result.push_back(81);

    return result;

}


unsigned char decodeChunk(unsigned char dataFirst, unsigned char dataSecond){

    //data = 'a';
   // short orig = 0;
  //  short message[7];
    unsigned short expanded[12];
    unsigned char orig[8];

    unsigned char originalChar = 0;

    //cout<<"MyData "<<data<<"which is "<<data<<"\n";

    for(int i =0; i< 8;i++){
       unsigned char temp = (dataSecond<< (7-i));
        temp = (temp >> (7-i));
        temp = (temp >> (i));
        expanded[11-i]=temp;
    }
    for(int i =8; i< 12;i++){
       unsigned char temp = (dataFirst<< (7-(i-8)));
        temp = (temp >> (7-(i-8)));
        temp = (temp >> (i-8));
        expanded[11-i]=temp;
    }

for(int i =0;i<12 ; i++){
//cout<<expanded[i];
}
//cout<<"\n";


short parity1 = expanded[10] xor expanded[8] xor expanded[6] xor expanded[4] xor expanded[2];
short parity2 = expanded[10] xor expanded[9] xor expanded[6] xor expanded[5] xor expanded[2];
short parity4 = expanded[11] xor expanded[6] xor expanded[5] xor expanded[4];
short parity8 = expanded[11] xor expanded[10] xor expanded[9] xor expanded[8];
deque<short> problems;
if(parity1 == expanded[0]){
    problems.push_back(1);
}
if(parity2 == expanded[1]){
    problems.push_back(2);
}
if(parity4 == expanded[3]){
    problems.push_back(4);
}
if(parity8 == expanded[7]){
    problems.push_back(8);
}

if(!problems.empty()){
    int wrongBit = 0;
    while(!problems.empty()){
        wrongBit += problems.front();
        problems.pop_front();
    }
    expanded[wrongBit-1] = expanded[wrongBit-1] xor 1;
}

orig[0] = expanded[2];
orig[1] = expanded[4];
orig[2] = expanded[5];
orig[3] = expanded[6];
orig[4] = expanded[8];
orig[5] = expanded[9];
orig[6] = expanded[10];
orig[7] = expanded[11];
int result = 0;

for(int i =0; i< 8; i++){
//cout<<orig[i];
//  orig[i] = (orig[i])<<(7-i);
 // originalChar = (originalChar & orig[i]);
result += pow(2.0, (double)i)*(int)orig[(7-i)];
//cout<<"SO FAR WE GOT "<<result<<" for "<<i<<"and "<<(int)orig[(7-i)]<<"\n";
}
//cout<<"here is the character "<<(char)result<<"  with the stored value of "<< result;
originalChar = (char)result;


return originalChar;
}

deque<unsigned char> decodeMessage(deque<unsigned char> message){
    deque<unsigned char> fullyDecoded;
  // cout<<message.size();
    while(message.size()!=0){

        unsigned char myDataFront = message.front();
       ////// cout<<"Check This out:"<<myData<<"\n";

       ////// cout<<"Check This out:"<<myData<<"\n";
        message.pop_front();
        unsigned char myDataBack = message.front();
      /////  cout<<"Check This out:"<<temp<<"\n";

       ///// cout<<"Check This out:"<<myData<<"\n";
        message.pop_front();
        fullyDecoded.push_back(decodeChunk(myDataFront,myDataBack));
    }

    return fullyDecoded;
}

void printOut(deque<unsigned char> x){
//cout<<"X IS OF SIZE"<<x.size()<<"\n";
while(x.size()!=0){

  // unsigned char a = x.front() >> 8;
 //   unsigned char b = (x.front() << 8) >> 8;
cout<< x.front();
//cout<<(int)a<<"  "<<(int)b<<"\n";
//cout<<a<<b;
   x.pop_front();
   // cout<<"NOW "<<x.size()<<"\n";
}

}


int main ()
{
    deque<unsigned char> message;
    deque<unsigned char> decoded;
    message = getMessage();



    decoded = decodeMessage(message);
    printOut(decoded);

    return 0;
}

