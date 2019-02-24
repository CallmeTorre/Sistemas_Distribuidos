#include <iostream> 
#include <string>
#include <algorithm>
using namespace std;

string genWord(){
    string result;
    for(int i = 0; i < 3; i++){
        char letter = (rand() % 26 + 65);
        result += letter;
    }
    return result;
}

int countOcurrencies(string line){
    int count;
    for(int i = 0; i < line.length() - 1; i++){
        if(line.at(i) == 'I' && line.at(i+1) == 'P' && line.at(i+2) == 'N'){
            count += 1;
        }
    }
    return count;
}

int main(){
    string line;
    int n;
    for(int j = 0; j < 10000; j++){
        if(j == 0){
            line += genWord();
        }
        else{
            line += " " + genWord();
        }
    }
    n = countOcurrencies(line);
    cout << n << endl;
    return 0;
} 