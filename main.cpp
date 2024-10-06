// COMSC-210 | Lab 19 | Adriel Chandra
// IDE used: Visual Studio Code

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
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
    Movie(const string movieTitle) : title(movieTitle), review(nullptr){}

    // Destructor to free up memory
    ~Movie(){
        while(review != nullptr){
            ReviewNode * temp = review;
            review = review->next;
            delete temp;
        }
    }

    // Function prototypes
    void addReview(double rating, const string& comment);
    void displayReviews() const;

    string getTitle(){
        return title;
    }
};

// Function prototypes
double generateRandomRating();
void loadComments(const string& filename, vector<string>& comments);
void displayAllMovies(const vector<Movie>& movies);
void assignReviews(vector<Movie>& movies, const vector<string>& comments);

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

    assignReviews(movies, reviewComments);
    displayAllMovies(movies);

    return 0;
}

// Function definitions
void Movie::addReview(double rating, const string& comment){
    ReviewNode * newNode = new ReviewNode;
    newNode->rating = rating;        
    newNode->comment = comment;       
    newNode->next = review; 
    review = newNode;
}

void Movie::displayReviews() const{
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
    return static_cast<double>(rand() % 41 + 10) / 10.0;
}

void loadComments(const string& filename, vector<string>& comments){
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

void displayAllMovies(const vector<Movie>& movies){
    for (const Movie& movie : movies) {
        movie.displayReviews();
    }
}

void assignReviews(vector<Movie>& movies, const vector<string>& comments){
    size_t numComments = comments.size();

    // For each movie, assign 3 comments
    for (Movie& movie : movies) {
        for (int i = 0; i < 3; ++i) {
            if (i < numComments) { 
                double rating = generateRandomRating();
                movie.addReview(rating, comments[i]);
            }
        }
    }
}