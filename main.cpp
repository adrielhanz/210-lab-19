// COMSC-210 | Lab 18 | Adriel Chandra
// IDE used: Visual Studio Code

#include <iostream>
#include <string>

using namespace std;

// Node structure
struct ReviewNode {
    float rating;
    string comment;
    ReviewNode * next;
};

// Function prototypes
void addToHead(ReviewNode *&, float, string&);
void addToTail(ReviewNode *&, float, string&);
void displayReviews(ReviewNode *);

int main(){
    ReviewNode * head = nullptr;
    int choice;
    char anotherReview;

    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes are added at the head of the linked list\n";
    cout << "    [2] New nodes are added at the tail of the linked list\n";

    // Input validation for choice
    while (true) {
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2){
            break; // Valid choice, exit loop
        } else{
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
    }
    
    // Enter a loop until user enters anything other than Y
    do{
        float rating;
        string comment;

        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore();

        cout << "Enter review comments: ";
        getline(cin, comment);

        if (choice == 1){
            addToHead(head, rating, comment);
        } else {
            addToTail(head, rating, comment);
        }

        cout << "Enter another review? Y/N: ";
        cin >> anotherReview;
    } while (anotherReview == 'Y' || anotherReview == 'y');

    cout << "\nOutputting all reviews:\n";
    displayReviews(head);

    return 0;
}

// Function definitions
void addToHead(ReviewNode *& head, float rating, string& comment){
    ReviewNode * newNode= new ReviewNode;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = head;
    head = newNode;
}

void addToTail(ReviewNode *& head, float rating, string& comment){
    ReviewNode * newNode= new ReviewNode;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = nullptr;

    if (head == nullptr){
        head = newNode;
    } else{
        ReviewNode * temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayReviews(ReviewNode * head){
    ReviewNode* temp = head;
    int count = 0;
    float totalRating = 0.0;

    while (temp != nullptr){
        count++;
        cout << "> Review #" << count << ": " << temp->rating << ": " << temp->comment << endl;
        totalRating += temp->rating;
        temp = temp->next;
    }

    if (count > 0){
        float average = totalRating / count;
        cout << "> Average: " << average << endl;
    } else{
        cout << "No reviews to display." << endl;
    }
}