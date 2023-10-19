#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {


    string word;
    int numberOfSentences=0;
    int numberOfWords=0;
    string filename = "input.txt";

    vector<string> Lines;
    ifstream myFile(filename);
    vector<string> Words;

    while (getline(myFile, word )) {
        // Add to the list of output strings
        Lines.push_back(word);
    }
    vector<string> FinalWords;
    string temp;

    for(string& i:Lines){
        for (char& j:i){
            if(j==' '){
                FinalWords.push_back(temp);
                numberOfWords++;
                temp.clear();
            }
            if(isalnum(j)){
              //  j=tolower(j);
                temp.push_back(j);
            }
            if(j =='.' ||j=='!'||j=='?'){
                numberOfSentences++;
            }
        }
        FinalWords.push_back(temp);
        numberOfWords++;
        temp.clear();
    }

    cout<<"number of sentences is "<<numberOfSentences<<endl;
    cout<<"number of words is "<<numberOfWords<<endl;

    int Count=0;
    int ite=0;

    while(numberOfWords!=ite) {
       Count=count(FinalWords.begin(), FinalWords.end(), FinalWords[ite]);

        cout<<FinalWords[ite]<<' '<<Count<<endl;
        ite++;
    }

    myFile.close();
   /*for( string& i : Lines){
        for(char& j:i){
            j=tolower(j);
            if(j =='.' ||j=='!'||j=='?'){
                numberOfSentences++;
                j=' ';
            }
            if(j==','){
                j=' ';
            }
        }
    }*/

   /* int Var=0;

   // vector<string> FinalWords;
    while(Lines.size()!=Var) {

        cout << Lines[Var] << endl;
        Var++;
    }
    */

    if (myFile.is_open()){
        cout<< "Hey ho";
    }

        return 0;
}
