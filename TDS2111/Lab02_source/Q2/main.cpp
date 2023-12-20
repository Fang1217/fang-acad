
#include <iostream>
#include <fstream>
#include <iomanip>
#include "ListP.cpp"

using namespace std;

int main()
{
    char choice;
    bool done = false;
    //WRITE CODE HERE
    // declare the object of linked list
    List alist;

    do
    {
        cout << endl << endl << endl;
        cout << "          1. Add Record To Back" << endl;
        cout << "          2. Insert a Record" << endl;
        cout << "          3. Erase a Record by Record Number" << endl;
        cout << "          4. Remove A Record by Content" << endl;
        cout << "          5. Clear ALL Records" << endl;
        cout << "          6. Display A Record" << endl;
        cout << "          7. Display ALL Records" << endl;
        cout << "          8. Save Records to File" << endl;
        cout << "          9. Load Records from File" << endl;
        cout << "          Q. Quit" << endl;
        cout << endl;
        cout << "        => ";
        cin >> choice;
        choice = toupper(choice);

        ListItemType ch, content;
        char yesorno;
        string filename;
        int recno;

        switch( choice )
        {
            case '1' :
                cout << "Character to add to back => ";
                cin >> ch;
                //WRITE CODE HERE
                // insert item to the back of linked list
                alist.insert(alist.getLength(), ch);
                break;

            case '2' :
                cout << "Record number to insert => ";
                cin >> recno;
                cout << "Character to insert => ";
                cin >> ch;
                //WRITE CODE HERE
                // insert item the specified location
                alist.insert(recno, ch);
                break;

            case '3' :
                cout << "Record number to erase => ";
                cin >> recno;

                //WRITE CODE HERE
                // remove item according to item position
                alist.remove(recno);
                break;

            case '4' :
                cout << "Character to remove => ";
                cin >> ch;
                for( int i = 1; i <= alist.getLength(); ++i )
                {
                    alist.retrieve( i, content );
                    if ( content == ch )
                    {
                        alist.remove( i );
                        break;
                    }
                }
                break;

            case '5' :
                cout << "Clear ALL records ? (Y/N) => ";
                cin >> yesorno;
                yesorno = toupper(yesorno);
                if ( yesorno == 'Y' )
                {
                    //WRITE CODE HERE
                    // remove all items in linked list
                    for(int i = 0; i = alist.getLength(); i-- ) alist.remove(i);
                }
                break;

            case '6' :
                cout << "Record number to display => ";
                cin >> recno;

                //WRITE CODE HERE
                // display item content based on the position
                alist.retrieve(recno, content);

                cout << "Data for Record Number " << recno << endl;
                cout << "----------------------------" << endl;
                cout << "[";
                cout << content;
                cout << "]" << endl;;
                cout << "----------------------------" << endl;
                break;

            case '7' :
                cout << "Data for ALL Records" << endl;
                cout << "----------------------------" << endl;

                //WRITE CODE HERE
                // display all items in list
                for (int i = 0; i < alist.getLength(); i++) {
                    alist.retrieve(i, content);
                    cout << "[";
                    cout << content;
                    cout << "]" << endl;;
                }
                cout << endl;
                cout << "----------------------------" << endl;
                break;

            case '8' :
                cout << "Save records to? File name = ";
                cin >> filename;
                alist.save( filename );
                break;

            case '9' :
                cout << "Load records from? File name = ";
                cin >> filename;
                alist.load(filename);
                break;

            case 'Q' :
                done = true;
                break;

            default :
                cout << "Invalid choice" << endl;
    }
  } while ( !done );
  cout << "Good Bye !!" << endl;
}
