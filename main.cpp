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
    
    // Generate random number

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
    while(temp != nullptr){
        count++;
        cout << fixed << setprecision(1);
        cout << "> Review #" << count << ": " << temp->rating << ": " << temp->comment << endl;
        totalRating += temp->rating;
        temp = temp->next;
    }

    if (count > 0) {
        double average = totalRating / count;
        cout << "> Average Rating: " << average << endl;
    }
}

double generateRandomRating(){
    return static_cast<double>(10 + rand() % 41) / 10.0;
}

void loadComments(string filename, vector<string> comments){
    ifstream inputFile(filename);
    if(!inputFile){
        cout << "Error opening file.";
    }
    exit;

    string comment;
    while(getline(inputFile, comment)){
        comments.push_back(comment);
    }

    inputFile.close();
}

void displayAllMovies(vector<Movie> movies){
    for (Movie& movie : movies){
        movie.displayReviews();
    }
    for (Movie& movie : movies){
        random_shuffle(shuffledComments.begin(), shuffledComments.end()); // Shuffle comments
        for(int i = 0; i < 3; ++i){
            double rating = generateRandomRating();
            movie.addReview(rating, shuffledComments[i]);
        }
    }
}
void shuffleandAssignReviews(vector<Movie> movies, vector<string> comments){
    vector<string> shuffledComments = comments;

}
