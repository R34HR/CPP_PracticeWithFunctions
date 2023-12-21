#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/* 
    In this function we will display the menu with of every
    mathematical operation that can be performed on our. 
*/  
void displayMenu();

 
//  In this function we will print all numbers in the vector array . 
void printNumbers(const vector<int> userNums, size_t listSize);

// In this function we are appending numbers to our vector
void addNumber(vector <int> &userNums);

// in this function we will calculate the mean of our vector array
void totalMean(vector <int> &userNums, size_t listSize);

// In this function we display the smallest number on our vector array
void displaySmallest(vector <int> &userNums, size_t listSize);

// In this function we display the largest number on our vector array
void displayLargest(vector <int> &userNums, size_t listSize);



int main (){


    displayMenu();

    return 0; 
}

void displayMenu(){

    bool exitMenu = false; 

    vector<int> userNumbers;

    while (exitMenu == false){

        char userOption {};
        cout << "---------- Welcome to Math Operations! ---------- \n"
             << "----------            Menu             ---------- \n"
             << "--------- P. Print numbers on your list --------- \n"
             << "-------- A. Add a number on to your list -------- \n"
             << "---- M. Display Mean of numbers on your list ---- \n" 
             << "---- S. Display Smallest number on your list ---- \n"
             << "---- L. Display Largest number on your list ----- \n"
             << "----------      E. Exit Program        ---------- \n"<< endl;

        cout << "Please enter the operation you want to perform: ";
        cin >> userOption;

        cout << "\n";

        size_t listSize = userNumbers.size();

        switch (userOption){

            case 'P':
            case 'p':{

                printNumbers(userNumbers, listSize);
                break;
            }
            case 'A':
            case 'a': {

                addNumber(userNumbers);
                break;
            }
            case 'M':
            case 'm': {

                totalMean(userNumbers,listSize);
                break;

            }
            case 'S':
            case 's': {

                displaySmallest(userNumbers, listSize);
                break;
            }
            case 'L':
            case 'l': {

                displayLargest(userNumbers, listSize);
                break;
            }

            case 'E':
            case 'e':{

                cout << "You are now exiting the program, Goodbye!" << endl;
                exitMenu = true;
                break;

            }

            default: {
                cout << "You are now exiting the program, Goodbye!" << endl;
                exitMenu = true;
                break;
            }

        }

    }
}

void printNumbers(const vector<int> userNums, size_t listSize){
    
    if (listSize == 0){
        cout << "The list is empty --- []" << endl;
        cout << "Please add numbers to your list \n \n" << endl;
    } else {

        cout << "List : ";
        for(size_t i {0}; i < listSize; i++){
            if (i == (listSize - 1)){
                cout << userNums[i] << endl;
            } else {
            cout << userNums[i] << ", "; 
            }
        }
        cout << "\n \n ";
    }

}
void addNumber(vector <int> &userNums){

    int userNumber;

    cout << "Please enter the number you want to add to your list: ";
    cin >> userNumber;

    if (!cin){
        cout  << "Please enter a Valid Number: ";
        cin >> userNumber;
    }

    cout << "Number added: " << userNumber << "\n \n" << endl;

    userNums.push_back(userNumber);
}
void totalMean (vector <int> &userNums, size_t listSize){

    double retMean {0.0};

    if(listSize == 0){
        cout << "list is empty -- [] --> MEAN: 0.0 \n \n" << endl;
    } else {
        for(int i {0}; i < listSize; i++){
            retMean += userNums[i];
        } 

        cout << "The total mean of your list is: " << (retMean/double(listSize)) << "\n \n" << endl;
    }

}
void displaySmallest(vector <int> &userNums, size_t listSize) {

    int smallestNum = userNums[0];

    if(listSize == 0){
        cout << "list is empty -- [] \n \n" << endl;
    } else {
        for(int i {1}; i < listSize; i++){
            if (userNums[i] < smallestNum) {
                smallestNum = userNums[i];
            }
        } 

        cout << "The smallest value of your list is: " << smallestNum << "\n \n" << endl;
    }

}
void displayLargest(vector <int> &userNums, size_t listSize){
    int largestNum = userNums[0];

    if(listSize == 0){
        cout << "list is empty -- [] \n \n" << endl;
    } else {
        for(int i {1}; i < listSize; i++){
            if (userNums[i] > largestNum) {
                largestNum = userNums[i];
            }
        } 

        cout << "The Largest value of your list is: " << largestNum << "\n \n" << endl;
    }

}