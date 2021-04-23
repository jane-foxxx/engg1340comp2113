
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
    // set random key number 
    srand((unsigned)time(NULL)); 
    int key1 = rand();
    // test range , random number is between -26 and 26
    int a = -26;
    int b = 26;
    int key2 = (rand() % (b - a + 1)) + a;
    int key = 3;
    string input = "I love YOU";
    string data = "abcdefghijklmnopqrstuvwxyz";
    string data_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "Key number = "<< key << endl;
    cout << "initial input is " << input << endl;
    
    string output = "";
    //Encrypt
    string::size_type position;
    string::size_type position1;
    if (key >= 0){
        for (int i = 0; i < input.size(); i++){
            position = data.find(input[i]);
            position1 = data_upper.find(input[i]);
            if (position != data.npos || position1 != data_upper.npos){
                //Encrypy Uppercase letters
                if (isupper(input[i])){
                    output += char(int(input[i] + key - 65) % 26 + 65);
                }
                // Encrypt Lowercase letters
                else{
                    output += char(int(input[i] + key -97) % 26 + 97);
                }
            }
            else{
                output += input[i];
            }
        }
    }
    else{
        for (int i = 0; i < input.size(); i++){
            position = data.find(input[i]);
            position1 = data_upper.find(input[i]);
            if (position != data.npos || position1 != data_upper.npos){
                //Encrypy Upper letters
                if (isupper(input[i])){
                    if (int(key % 26 + input[i]) <= 65){
                        output += char(int(key % 26 + 26 + input[i]));
                    }
                    else{
                        output += char(int(key % 26 + input[i])); 
                    }
                }
                // Encrypt Lowercase letters
                else{
                    if (int(key % 26 + input[i]) <= 96){
                        output += char(int(key % 26 + 26 + input[i]));
                    }
                    else{
                        output += char(int(key % 26 + input[i])); 
                    }
                }
            }
            else{
                output += input[i];
            }
        }
    }
    cout << "encrypyed answer is " << output << endl;

    //Decrypy
    string input1 = output;
    string output1;
    string::size_type position_d;
    string::size_type position1_d;
    if (key < 0){
        for (int i = 0; i < input1.size(); i++){
            position_d = data.find(input1[i]);
            position1_d = data_upper.find(input1[i]);
            if (position_d != data.npos || position1_d != data_upper.npos){
                //Decrypy Uppercase letters
                if (isupper(input1[i])){
                    output1 += char(int(input1[i] - key - 65) % 26 + 65);
                }
                // Decrypt Lowercase letters
                else{
                    output1 += char(int(input1[i] - key - 97) % 26 + 97);
                }
            }
            else{
                output1 += input1[i];
            }
        }
    }
    else{
        for (int i = 0; i < input1.size(); i++){
            position_d = data.find(input1[i]);
            position1_d = data_upper.find(input1[i]);
            if (position_d != data.npos || position1_d != data_upper.npos){
                //Decrypy Upper letters
                if (isupper(input1[i])){
                    if (int(-key % 26 + input1[i]) <= 65){
                        output1 += char(int(-key % 26 + 26 + input1[i]));
                    }
                    else{
                        output1 += char(int(-key % 26 + input1[i])); 
                    }
                }
                // Decrypt Lowercase letters
                else{
                    if (int(-key % 26 + input1[i]) <= 96){
                        output1 += char(int(-key % 26 + 26 + input1[i]));
                    }
                    else{
                        output1 += char(int(-key % 26 + input1[i])); 
                    }
                }
            }
            else{
                output1 += input1[i];
            }
        }
    }
    cout << "decrypyed answer is " << output1;
}
