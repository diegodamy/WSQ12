
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int CheckFile(string textname3){
  ifstream InList;
  InList.open(textname3.c_str());

  if (InList.is_open()) {
    cout << "File was opened succesfully!" << endl;
    return 1;
    } else {
    return 0;
  }
}

int ReadFile(string word2, string textname2){
  int counter;
  string textword;
  ifstream InList;
  InList.open(textname2.c_str());

  while (!InList.eof()) { // keep counting until you rach the last string
      InList >> textword; // create a string out of all words in the text file
      if (textword == word2) {
          counter++;
      }
    }

    InList.close();
    return counter;
}


int KeepRunning(char decision){
  if (decision == 'Y' || decision == 'y'){
    return 1;
  } else {
    return 0;
  }
}

int main(){
  string word;
  string textname;
  char decision;

  do {
  cout <<"Please enter the name of the text:" << endl;
  cin >> textname;

  if (CheckFile(textname)==0) {
    cout << "Unable to open file." << endl;
    cout <<"Please enter the name of the text:" << endl;
    cin >> textname;
  }

  cout <<"Please enter the word you wish to find in the text:" << endl;
  cin >> word;

  cout << endl << word << " was found " << ReadFile(word, textname) << " time(s) in the text." << endl;
  cout << endl << "Do you wish to look for another word?: Y/N" << endl;
  cin >> decision;

  } while (KeepRunning(decision) == 1);
  cout << "Goodbye!" << endl;
}
