#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "JsonFacade.hpp"
#include "json.hpp"
#include "read_dict.cpp"
#include "Timer.hpp"

using namespace std;
using json = nlohmann::json;

//struct that is used to organize all city information used in the entire program
struct WordNode
{
    string Word;
    string Definition;
    char FirstLetter;
    WordNode *next;

    // default constructor
    WordNode()
    {
        Word = "";
        Definition = "";
        FirstLetter = "";
        next = NULL;
    }
    // parameterized constructor using json file
    WordNode(json obj)
    {
        Word = obj["word"];
        Definition = obj["definition"];
        FirstLetter = obj[Word.charAt(0)];
    }
    // user defined parameterized constructor, for easy access of all struct variables
    WordNode(string W,string D) :Word(W), Definition(D)){}
};

int main()
{
    // using Fstream library to open a text file called output.txt
    ofstream outfile;
    outfile.open("output.txt");

    int count = 0;
    // user can change how many cities that they want printed
    int NumberOfLetters = 26;

    // Creating instance of Json Class
    // instantiating a Json Object
    // And using a string with the name of the cities input json file in conjunction to
    //                  instantiating an JsonFacade object.
    string DictionaryDef = "dict_w_defs.json";
    json object;
    JsonFacade JF(DictionaryDef);

    // Creating 2 pointers of struct city
    WordNode **LetterPointer;
    WordNode *temp;

    // Using the cities.json files size for the instantiation of SizeOfJsonfile
    int SizeOfJsonFile = JF.getSize();
    vector<WordNode> H(SizeOfJsonFile + 1, false);

    // Creating an Array of pointers using the size of the json Cities file
    LetterPointer = new WordNode *[SizeOfJsonFile];

    // Iterating through every pointer and dynamically assigning new son struct objects on every pointer
    for (int i = 0; i < SizeOfJsonFile; i++)
    {
        object = JF.getNext();
        // if(object.Word.CharAt(i) == )
        temp[i] = new WordNode(object);
    }

    // test code
    /*H.Heapify(CityPointer,SizeOfJsonFile);
int b = 0;
while(!H.Empty()){
        temp = H.Extract();
        outfile <<b<<" "<<temp->Name<< " " <<temp->Priority << endl;
        b++;
}
*/

    //Main loop that loops the size of the JsonFile , in this case 1000,
    // and has the abllity to change dynamically due to the size of the file
    for (int i = 0; i < SizeOfJsonFile; i++)
    {

        // Prints the first 10 cities and last 10 cities that are first used to compare coordinate A
        if (i < 10 || i >= (SizeOfJsonFile - 10))
        {
            outfile << setfill('0') << setw(4);
            outfile << i + 1 << ": " << CityPointer[i]->Name << endl;
        }

        for (int j = 0; j < SizeOfJsonFile; j++)
        {
            // Both coordinates used to evetually be inputed into Haversine Formula
            Coordinate A(CityPointer[i]->Latitude, CityPointer[i]->Longitude);
            Coordinate B(CityPointer[j]->Latitude, CityPointer[j]->Longitude);

            HaversineDistanceValue = HaversineDistance(A, B);

            // Priority is decided and struct objects priority is recorded
            CityPointer[j]->Priority = HaversineDistanceValue;
            // Inserts all needed objects into the heap
            H.Insert(CityPointer[j]);
        }

        // loop that runs until heap is empty by the size of the input json file
        while (count < SizeOfJsonFile)
        {

            ReadCity = H.Extract();

            // Another comparison that makes sure only the first 10 and the last 10 cities information is printed
            if (i < 10 || i >= (SizeOfJsonFile - 10))
            {
                if (count <= howManyCities)
                {
                    // Use of iomanip and other forms of output manipulation to print neatly, the first city being different
                    // then the second and third city output
                    if (count == 1)
                    {
                        if (ReadCity->Name != CityPointer[i]->Name)
                        {
                            outfile << "\t" << count << ")"
                                    << " " << ReadCity->Name << " (" << ReadCity->Priority << ") " << endl;
                        }
                    }
                    // the rest print normally
                    if (count != 1)
                    {
                        if (ReadCity->Name != CityPointer[i]->Name)
                        {
                            outfile << "\t"
                                    << "\t" << count << ") " << ReadCity->Name << " (" << ReadCity->Priority << ") " << endl;
                        }
                    }
                }
            }
            // incrementation and makes sure pointers go back to being null
            count++;
            ReadCity = NULL;
        }
        count = 0;
    }

    return 0;
}