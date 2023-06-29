//домашнє завдання №27 артyp
#include <iostream>
#include <iomanip>
#include <string>
#include<fstream>
#include <vector>
#include <Windows.h>
using namespace std;



class Dictionary
{

    int count;
    string filename1;



    vector<string>  arr1, arr2;
public:
    Dictionary(string filename1, string filename2) {
        Load(filename1, &arr1); Load(filename2, &arr2);
    }
    bool Load(string path, vector<string>* arr)
    {
        ifstream file1(path);
        if (file1.is_open())
        {
            string line;
            int i = 0;



            while (getline(file1, line))
            {
                
                ++i;
                arr->push_back(line);
            }
            return true;
        }
        cout << "Error" << endl;
        return false;
    };
    string Translate(string word, string translate)
    {
        for (int i = 0; i < 3900; i++)
        {
            if (word == arr1[i])
                return arr2[i];
        }
        return "";
    }
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Dictionary dictionary("Eng.txt", "UA.txt");
    string S = dictionary.Translate("abandon", "Eng-UA");
    string S1 = dictionary.Translate("highlight", "Eng-UA");
    string S2 = dictionary.Translate("highway", "Eng-UA");
    string S3 = dictionary.Translate("motorbike", "Eng-UA");
    string S4 = dictionary.Translate("window", "Eng-UA");
    cout << "abandon " << "Translation > > >  " << S << endl;
    cout << "highlight " << "Translation > > >  " << S1 << endl;
    cout << "highway " << "Translation > > >  " << S2 << endl;
    cout << "motorbike " << "Translation > > >  " << S3 << endl;
    cout << "window " << "Translation > > >  " << S4 << endl;
}

