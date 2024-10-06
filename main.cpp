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


// Movie class
class Movie{
private:
    string title;
    ReviewNode * review;
public:
    // Constructor
    Movie(string movieTitle) : title(movieTitle), review(nullptr){}

    // Destructor to free up memory
    ~Movie(){
        while (reviewHead != nullptr) {
            ReviewNode* temp = reviewHead;
            reviewHead = reviewHead->next;
            delete temp;
        }
    }

    // Function prototypes
    void addReview();
    void displayReviews();
}
// Function prototypes
double generateRandomRating();
void loadComments();
void displayAllMovies();
void shuffleandAssignReviews();

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

void Movie::addReview(double rating, string comment){
    ReviewNode * newNode= new ReviewNode;
    review = newNode;
}

void Movie::displayReviews(){
    ReviewNode * temp = review;
    int count = 0;
    double totalRating = 0.0;

    cout << "Movie name: " << title << endl;
}
void addReview(ReviewNode *& head, float rating, string& comment){
    ReviewNode * newNode= new ReviewNode;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = head;
    head = newNode;
}
