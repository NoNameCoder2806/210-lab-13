// COMSC-210 | Lab 13 | Dat Hoang Vien
// IDE used: Visual Code Studio

// Libraries
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>  // for sort(), find()
#include <numeric>    // for accumulate()
#include <string>
#include <vector>
using namespace std;

// Function prototypes
void fileInput(vector<double>& gpaVector, string path);

void displayVector(const vector<double>& gpaVector);

void findElement(vector<double>& gpaVector, double targetGPA);

// Main
int main()
{
    // Declare a vector to store double gpa data
    vector<double> gpaVector;

    // Output the address to the console
    cout << " - Address of the vector: " << gpaVector.data() << endl;

    // Check whether the current vector is empty
    cout << " - Empty?: ";
    if (gpaVector.empty())
    {
        cout << "True!" << endl;
    }
    else
    {
        cout << "False!" << endl;
    }

    // Read the data from the file
    fileInput(gpaVector, "data.txt");

    // Print the current size
    cout << " - Vector current size: " << gpaVector.size() << endl;
    cout << endl;
    
    // Display all the gpa in the vector
    cout << "Original vector: ";
    displayVector(gpaVector);
    cout << endl;

    // Display the first and last element of the vector
    cout << " - First element: " << gpaVector.front() << endl;
    cout << " - Last element: " << gpaVector.back() << endl;
    cout << endl;

    // Sort the vector
    sort(gpaVector.begin(), gpaVector.end());

    // Display the sorted vector
    cout << "Sorted vector: ";
    displayVector(gpaVector);
    cout << endl;

    // Declare a few GPA scores to search for
    double target1 = 2.25;
    double target2 = 2.5;
    double target3 = 2.75;
    double target4 = 3.0;

    vector<double>::iterator it;

    // Check whether they are in the vector or not
    findElement(gpaVector, target1);
    findElement(gpaVector, target2);
    findElement(gpaVector, target3);
    findElement(gpaVector, target4);

    // Find the min, max, and average GPA score from the vectors
    cout << " - Highest GPA: " << *max_element(gpaVector.begin(), gpaVector.end()) << endl;
    cout << " - Lowest GPA: " << *min_element(gpaVector.begin(), gpaVector.end()) << endl;
    cout << " - Average GPA: " << accumulate(gpaVector.rbegin(), gpaVector.rend(), 0.0) / gpaVector.size() << endl;
    cout << endl;

    // Create 2 vectors and fill them with 4.0 and 2.0
    vector<double> fours(5, 4.0);     // Fill 5 elements
    vector<double> twos(5, 2.0);      // Fill 5 elements

    // Display the 2 vectors
    cout << "Vector of Fours: ";
    displayVector(fours);
    cout << "Vector of Twos: ";
    displayVector(twos);
    cout << endl;

    // Swap the 2 vector
    fours.swap(twos);
    cout << " --- The 2 vectors are swapped! --- " << endl;

    // Display the 2 vectors again
    cout << "Vector of Fours: ";
    displayVector(fours);
    cout << "Vector of Twos: ";
    displayVector(twos);
    cout << endl;

    return 0;
}

// Function implementations
/*
    fileInput()
    Add new gpa from a file
    Arguments: 
        - gpaVector: reference to the std::vector<double> that will store the data
        - path: path to the data file
    Returns: none
*/
void fileInput(vector<double>& gpaVector, string path)
{
    // Create a file stream and read the file
    ifstream fin;
    fin.open(path);

    // Exit the function if the file fails to open
    if (!fin.is_open()) {
        cerr << "Error: Unable to open file: " << path << endl;
        return;
    }

    // Declare a double variable to store the value
    double value = 0.0;

    // Iterate through the file and read the data line by line
    while (fin >> value)
    {
        // Add the value into the vector
        gpaVector.push_back(value);
    }
}

/*
    displayVector()
    Display the data of the gpa (double type) in the vector
    Arguments:
        - gpaVector: const reference to the std::vector<double> containing gpa values
    Returns: none
*/
void displayVector(const vector<double>& gpaVector)
{
    // Iterate through the vector
    for (int i = 0; i < gpaVector.size(); i++)
    {
        // Display the fields
        cout << gpaVector[i];

        // Add a comma and a space if this is not the last element
        if (i != gpaVector.size() - 1)
        {
            cout << ", ";
        }
    }

    // Enter a new line
    cout << endl;
}

/*
    findElement()
    Search the gpaVector for a specific gpa.
    Arguments:
        - gpaVector: reference to the std::vector<double> containing the gpa
        - targetGPA: the GPA value to search for
    Returns:
        - none (prints search results to the console)
*/
void findElement(vector<double>& gpaVector, double targetGPA)
{
    // Display a message to notify the user of the element being searched
    cout << " --- Searching for: " << targetGPA << " --- " << endl;

    // Declare an iterator to point to the found element
    vector<double>::iterator it;
    it = find(gpaVector.begin(), gpaVector.end(), targetGPA);
    
    // Check whether the iterator points to an element or not
    if (it != gpaVector.end())
    {
        // Displaying a message
        cout << "Element found! Position: " << it - gpaVector.begin() << endl;
    }
    else
    {
        // Displaying a message
        cout << "Element not found!" << endl;
    }

    // Enter a new line
    cout << endl;
}