// reads in binary arrays and creates their boolean OR AND XOR equivalents
// as well as their decimal equivalents
// Program Description : Two dimensional arrays boolean operatons
// *****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;
const int ROWS = 10;
const int COLS = 10;
typedef int Dataset[ROWS][COLS];
void open_inFile(ifstream&);
void read_data(ifstream&, int&, int&, Dataset, Dataset);
void calculate_boolean(int&, int&, Dataset, Dataset, Dataset, Dataset, Dataset);
void print_input_results(int&, int&, Dataset, Dataset, Dataset, Dataset, Dataset);
void decimal(Dataset, Dataset, Dataset, int&, int&);
int main()
{
    ifstream inFile;
    int rows;
    int cols;
    Dataset set1;
    Dataset set2;
    Dataset OR;
    Dataset AND;
    Dataset XOR;
    open_inFile(inFile);
    read_data(inFile, rows, cols, set1, set2);
    calculate_boolean(rows, cols, set1, set2, OR, AND, XOR);
    print_input_results(rows, cols, set1, set2, OR, AND, XOR);
    decimal(OR, AND, XOR, rows, cols);
    
    return 0;
}
void open_inFile(ifstream& inFile)
{
    string filename;  // local file holder variable
    cout << "\nEnter the name of the input file: ";
    cin >> filename; // extract
    cout << filename << endl; // echo
    cout << endl; // CHANGE BACK TO SINGLE END LINE
    inFile.open(filename.c_str());  // open
    while(!inFile)  // oops
    {
        cout << string(15,'*') <<  " File Open Error " << string(15,'*') << endl;
        cout << "==> Input file failed to open properly!!" << endl;
        cout << "==> Attempted to open file: " << filename << endl;
        cout << "==> Please try again..." << endl;
        cout << string(47,'*') << endl;
        inFile.clear(); // clear infile stream
        cout << "\nEnter the name of the input file: ";
        cin >> filename; // extract local file holder variable
        cout << filename << endl;
        cout << endl;
        inFile.open(filename.c_str()); // open for real
    }
    
}
void read_data(ifstream& inFile, int& rows, int& cols, Dataset set1, Dataset set2)
{
  while(inFile) // while ! EOF
   {
       inFile >> rows; // get array # of rows
       inFile.ignore(256,'\n');
       inFile >> cols; // get array # of cols
       inFile.ignore(256,'\n');
       for (int row = 0; row < rows; row++)
       {
          for (int col = 0; col < cols; col++)
          {
              inFile >> set1[row][col];  //populate
          }
       }
      for (int row = 0; row < rows; row++)
       {
          for (int col = 0; col < cols; col++)
          {
              inFile >> set2[row][col];  //populate
          }
       }
   }
}
void calculate_boolean(int& rows, int& cols, Dataset set1, Dataset set2, Dataset OR, Dataset AND, Dataset XOR)
{
    for (int row = 0; row < rows; row++)
       {
          for (int col = 0; col < cols; col++)
          {
              if (set1[row][col] == 1 || set2[row][col] == 1)
              {
                  OR[row][col] = 1;
              }
              else
              {
                  OR[row][col] = 0;
              }
              
              if(set1[row][col] == 1 && set2[row][col] == 1)
              {
                  AND[row][col] = 1;
              }
              else
              {
                  AND[row][col] = 0;
              }
              
              if((set1[row][col] == 1 && set2[row][col] == 0) || (set1[row][col] == 0 && set2[row][col] == 1))
              {
                  XOR[row][col] = 1;
              }
              else
              {
                  XOR[row][col] = 0;
              }
          }
       }
}
void print_input_results(int& rows, int& cols, Dataset set1, Dataset set2, Dataset OR, Dataset AND, Dataset XOR)
{
    // INITIAL INPUT PRINT
    cout << "Initial values of the arrays processed" << endl;
    cout << string(38,'-') << endl;
    cout << setw(2*cols) << left << "Array 1" << "    " << setw(2*cols) << "Array 2" << endl;
    cout << setw(2*cols) << left << string(7,'-') << "    " << setw(2*cols) << string(7,'-') << endl;
   for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cout << set1[row][col] << " " ;
        }
        cout << "    ";
        for (int col = 0; col < cols; col++)
        {
            cout << set2[row][col] << " ";
        }
       cout << endl;
    }
    cout << endl;
    // BOOLEAN PRINT
    cout << "OR, AND and XOR results" << endl;
    cout << string(23,'-') << endl;
    cout << setw(2*cols) << left << "OR" << "    " << setw(2*cols) << "AND" << "    " <<
     setw(2*cols) << "XOR" <<  endl;
    cout << setw(2*cols) << left << string(2,'-') << "    " << setw(2*cols) << left << string(3,'-') << "    "
    << setw(2*cols) << left << string(3,'-') << endl;
      for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cout << OR[row][col] << " " ;
        }
        cout << "    ";
        for (int col = 0; col < cols; col++)
        {
            cout << AND[row][col] << " " ;
        }
        cout << "    ";
        for (int col = 0; col < cols; col++)
        {
            cout << XOR[row][col] << " ";
        }
       cout << endl;
    }
    cout << endl << endl;
    // INTEGERS PRINT
    cout << "Integer Equivalents for the rows" << endl;
    cout << "of the OR, AND and XOR arrays" << endl;
    cout << string(32,'-') << endl;
    cout << setw(8) << left << "OR" << setw(8) << left <<  "AND"
    <<  setw(8) << left << "XOR" << endl;
    cout << setw(8) << left << "--" << setw(8) << left << "---" <<
    setw(8) << left << "---" << endl;
 
}
void decimal(Dataset OR, Dataset AND, Dataset XOR, int& rows, int& cols)
{
int row = 0;
while(row < rows)
{
int col = cols-1;
int integer = 0;
int base = 1;

while (col >= 0)
{

if (OR[row][col] == 1)
{
base = pow(2,((cols-1)-col));
integer += base;

}
col--;

}
cout << setw(8) << left <<  integer;


col = cols-1;
integer = 0;
base = 1;
while (col >= 0)
{

if (AND[row][col] == 1)
{
base = pow(2,((cols-1)-col));
integer += base;
}
col--;
}
cout << setw(8) << left << integer;


col = cols-1;
integer = 0;
base = 1;
while (col >= 0)
{

if (XOR[row][col] == 1)
{
base = pow(2,((cols-1)-col));
integer += base;

}
col--;
}
cout << setw(8) << left << integer;

row++;
cout << endl;

}
}


