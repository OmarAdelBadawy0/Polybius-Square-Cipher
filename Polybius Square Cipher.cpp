// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Polybius Square Cipher.cpp
// Program Description: The program Cipher and Decipher depend on the key which set he rows and columns to Cipher Table
// Last Modification Date: 16/3/2022
// Author1 and ID and Group: Omar Adel, 20210266, Group A
// Teaching Assistant: xxxxx xxx
// Purpose: Make ciphers that no one understands except for someone who has the program and the right key


#include<iostream>
#include <algorithm>
#include <string>

using namespace std;

string key;
string cipherSentens;
string decipherSentence;

// Cipher table
char cipherTable(int row,int col){
        char test[5][5] = {
        {'A','B','C','D','E'},
        {'F','G','H','I','K'},
        {'L','M','N','O','P'},
        {'Q','R','S','T','U'},
        {'V','W','X','Y','Z'},
    };

    return test[row][col];
}

// function which creat the cipher sentence
void cipher(int row,int column){
    
    switch (row)
    {
    case 0:
        cipherSentens += key[0];
        break;
    case 1:
        cipherSentens += key[1];
        break;
    case 2:
        cipherSentens += key[2];
        break;
    case 3:
        cipherSentens += key[3];
        break;
    case 4:
        cipherSentens += key[4];
        break;
    }
    switch (column)
    {
    case 0:
        cipherSentens += key[0];
        break;
    case 1:
        cipherSentens += key[1];
        break;
    case 2:
        cipherSentens += key[2];
        break;
    case 3:
        cipherSentens += key[3];
        break;
    case 4:
        cipherSentens += key[4];
        break;
    }

}

// Function which search and get the character from cipher table
void search(char character){

    for(int i = 0; i < 5; i++){                 // search in every row
        for(int r = 0; r < 5; r++){             // search in every column
            if (character == cipherTable(i,r)){
                cipher(i,r);
            }
        }
    }
}


// function which prepare the input to cipher it
void setToSipher(){
    string sentence;
    char letter;
    
    cout<< "Please enter the message to cipher: ";
    cin.ignore();
    getline(cin,sentence);
    transform(sentence.begin(), sentence.end(),sentence.begin(), ::toupper);
    
    for(int i = 0; i < sentence.length(); i++){   // this loop to swich every j to i
        if(sentence[i] == 'J'){
            sentence[i] = 'I';
        }
        
        search(sentence[i]);
    }

}

// function which deal with cipherd sentence to translate it
void decipher(){
    string sentenc;
    char row,col;

    cout << "Enter the code to decipher it: " ;
    cin >> sentenc;
    
    for(int i = 0; i < sentenc.length(); i+=2){    
        
        if(sentenc[i] == key[0]){                 // check the character in any row
            row = 0;
        } else if(sentenc[i] == key[1]){
            row = 1;
        } else if(sentenc[i] == key[2]){
            row = 2;
        } else if(sentenc[i] == key[3]){
            row = 3;
        } else if(sentenc[i] == key[4]){
            row = 4;
        }

        if(sentenc[i+1] == key[0]){                // check the character in any column
            col = 0;
        } else if(sentenc[i+1] == key[1]){
            col = 1;
        } else if(sentenc[i+1] == key[2]){
            col = 2;
        } else if(sentenc[i+1] == key[3]){
            col = 3;
        } else if(sentenc[i+1] == key[4]){
            col = 4;
        }
    
    decipherSentence += cipherTable(row,col);
    }
}

// this function to display the function and the key on it
void display(){
    char test[5][5] = {
        {'A','B','C','D','E'},
        {'F','G','H','I','K'},
        {'L','M','N','O','P'},
        {'Q','R','S','T','U'},
        {'V','W','X','Y','Z'},
    };
    cout<<"   "<<key[0]<<"  "<<key[1]<<"  "<<key[2]<<"  "<<key[3]<<"  "<<key[4];
    
    for(int i = 0; i < 5; i++){
        cout<<endl<<key[i]<<"|";
        for(int j = 0; j < 5; j++){
            cout<<" "<<test[i][j]<<" ";
        }
        cout<<"|";
    }
    cout<<endl;
}


int main(){
    int choice;
    
    cout<< "Ahlan ya user ya habibi. :)\nWhat do you like to do today?\n1- Cipher a message\n2- Decipher a message\n3- Exit\n";
    cin>> choice;


    if(choice == 1){
        cout<< "Enter The Key: ";
        cin>> key;
        display();
        setToSipher();
        cout<< cipherSentens;

    }else if(choice == 2){
        cout<< "Enter The Key: ";
        cin>> key;
        display();
        decipher();
        cout << decipherSentence;

    }else if(choice == 3){
        exit(0);
    }


    return 0;
}