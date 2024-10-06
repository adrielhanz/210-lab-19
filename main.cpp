// COMSC-210 | Lab 18 | Adriel Chandra
// IDE used: Visual Studio Code

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <random>

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
        while(review != nullptr){
            ReviewNode * temp = review;
            review = review->next;
            delete temp;
        }
    }

    // Function prototypes
    void addReview(double, string&);
    void displayReviews();
};

// Function prototypes
double generateRandomRating();
void loadComments(string& filename, vector<string>& comments);
void displayAllMovies(vector<Movie>& movies);

int main(){
    // Read comments from file
    vector<string> reviewComments;
    loadComments("reviews.txt", reviewComments);

    // Container of movies
    vector<Movie> movies;
    movies.push_back(Movie("Indiana Jones: The Dial of Destiny"));
    movies.push_back(Movie("Avengers: Endgame"));
    movies.push_back(Movie("Spiderman: No Way Home"));
    movies.push_back(Movie("Oppenheimer"));

    // Display all movies with their reviews
    displayAllMovies(movies);

    return 0;
}

// Function definitions
void Movie::addReview(double rating, string& comment){
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

void loadComments(string& filename, vector<string>& comments){
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    string comment;
    while(getline(inputFile, comment)){
        comments.push_back(comment);
    }

    inputFile.close();
}

void displayAllMovies(vector<Movie>& movies){
    for (Movie& movie : movies){
        movie.displayReviews();
    }
}
