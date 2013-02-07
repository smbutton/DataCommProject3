#include "..\include\encode.h"
#include <iostream>
#include <iterator>
#include <deque>
using namespace std;


deque<char> getMessage(){

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

    deque<char> result;
    result.push_back('h');
    result.push_back('e');
    result.push_back('l');
    result.push_back('l');
    result.push_back('o');
    result.push_back('w');
    result.push_back('o');
    result.push_back('r');
    result.push_back('l');
    result.push_back('d');
    result.push_back('!');
    return result;

}

unsigned short encodeByte(char data){
    short expanded = 0;
    //data = 'a';
    short orig[8];
    short hammed[12];
    cout<<"MyData "<<data<<"which is "<<(int)data<<"\n";

    for(int i =0; i< 8;i++){
          //  cout<<"position "<<i<<" ==\n";
       unsigned char temp = data;
       if(i == 7){

        temp = (temp >> (i));
       // cout<<(int)temp<<"\n";
        orig[0]=temp;

       }else{
       temp = (temp<< (7-i));
      // cout<<(int)temp<<"\n";
        temp = (temp >> (7-i));
       // cout<<(int)temp<<"\n";
        temp = (temp >> (i));
       // cout<<(int)temp<<"\n";
        orig[7-i]=temp;
       }
      // cout<<"orig i"<<i<<" "<<orig[i]<<"\n\n";
    }
   // cout<<"\n";
hammed[11] = orig[7];
hammed[10] = orig[6];
hammed[9] = orig[5];
hammed[8] = orig[4];
hammed[6] = orig[3];
hammed[5] = orig[2];
hammed[4] = orig[1];
hammed[2] = orig[0];
cout<<"The Binary was:\n";
for(int i =0;i<8 ; i++){
cout<<orig[i];

}
cout<<"\n";
hammed[7] = hammed[11] xor hammed[10] xor hammed[9] xor hammed[8];
hammed[3] = hammed[11] xor hammed[6] xor hammed[5] xor hammed[4];
hammed[1] = hammed[10] xor hammed[9] xor hammed[6] xor hammed[5] xor hammed[2];
hammed[0] = hammed[10] xor hammed[8] xor hammed[6] xor hammed[4] xor hammed[2];
cout<<"I got the code:\n";
for(int i =0;i<12 ; i++){
cout<<hammed[i];

}
cout<<"\n";

for(int i =0; i< 12; i++){

    hammed[i] = hammed[i] << 11-i;
    expanded = expanded | hammed[i];
cout<<"expanded "<<expanded<<" \n";
}


return expanded;
}

deque<unsigned short> encodeMessage(deque<char> message){
    deque<unsigned short> fullyEncoded;
   cout<<message.size();
    while(message.size()!=0){

        fullyEncoded.push_back(encodeByte(message.front()));
        message.pop_front();
    }

    return fullyEncoded;
}

void printOut(deque<unsigned short> x){
//cout<<"X IS OF SIZE"<<x.size()<<"\n";
while(x.size()!=0){

   unsigned char a = x.front() >> 8;
    unsigned char b = (x.front() << 8) >> 8;
//cout<< x.front()<<"NOW\n";
cout<<(int)a<<"  "<<(int)b<<"\n";
//cout<<a<<b;
    x.pop_front();
   // cout<<"NOW "<<x.size()<<"\n";
}

}


int main ()
{
    deque<char> message;
    deque<unsigned short> encoded;
//cout<<" here12";
    message = getMessage();//
//cout<<" here14";


    encoded = encodeMessage(message);
printOut(encoded);

    return 0;
}

