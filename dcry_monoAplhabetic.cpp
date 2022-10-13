/***************************************************************************************************************/
/******************************* Decryption of MonoAlphabetic Cipher by frequency attack ***********************/
/***************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<char,int> &a, const pair<char,int> &b){
    return a.second >  b.second;
}


string encrypt(string pText){
    string encryptedString = "";
    for(int i = 0;i<pText.size();i++){
        if(pText[i] != ' ') 
        {char ch = pText[i];
        char newChar = 25-(ch -'A')+'A';
        encryptedString += newChar;
        }
        else{
            encryptedString += pText[i];
        }
    }
    return encryptedString;
}

void countFrequency(string encryptedString, vector<pair<char,int>> &freq){
    for(int i = 0;i<encryptedString.size();i++){
        freq[encryptedString[i]-'A'].first = encryptedString[i];
        freq[encryptedString[i]-'A'].second++;
    }
}

void swappingClosestChars(vector<pair<char,int>> &freq,int cnt){
        
        swap(freq[cnt],freq[cnt+1]);
}

string decrypt(string encryptedString, vector<pair<char,int>> &freq, string standardString,vector<string> &decrypted){
        int cnt =0;
        for(int i=0;i<10;i++){

        map<char,char> randomMapping;
        for(int j = 0;j<26;j++){
            char ch = freq[j].first;
            char st = standardString[j];
            randomMapping[ch] = st;
        }
        string decryptedString = "";
        for(int j = 0;j<encryptedString.size();j++){
            if(encryptedString[j] != ' '){
            
            decryptedString += randomMapping[encryptedString[j]];
            }
            else{
                decryptedString += encryptedString[j];     
            }
        
        } 
        decrypted.push_back(decryptedString);
        swappingClosestChars(freq,cnt);
        cnt++;
}
    for(auto i: decrypted){
        cout << i;
        cout <<endl;
    }
}



int main(){
    // Create a string to store Plain Text
    string pText = "ABCDEFGHIJKLMNOP QRSTUVWXYYZZZ";
    cout << "Plain Text: ";

    cout << pText<<endl;
    // Convert Plain Text into Cipher Text using Key
    cout<<"Encryption of Plain Text ..."<<endl<<endl;
    string cText = encrypt(pText);

    string standardString = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    cout << cText << endl<<endl;


    vector<pair<char,int>> frq(26);
    countFrequency(cText, frq);
    sort(frq.begin(),frq.end(),comp);
   
    vector<string> decryptedString;
    cout << "Decryption of Cipher Text ..."<<endl<<endl;
    cout<< "Print all 10 possible outcomes: "<<endl<<endl;
    decrypt(cText, frq,standardString, decryptedString);

    for(auto i: decryptedString){
        cout << i;
        cout <<endl;
    }


// ABCDEFGHIJKLMNOPQRSTUVWXYZ
    return 0;




}