// Advantages of vectors: allows dymnamic allocation.
// Even you fixed the size of vector, while creation. You can append element
// after the size exceeds using push_back() method.
#include <iostream>
#include <vector> // You need to vector header before using it.
using namespace std;

int main() {

  // vector<char> vowels; // empty vector.
  // vector<char> vowels(5); // creating a vector with 5 elements.

  vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
  cout << vowels[0] << endl; // displaying data with square bracket. We can also
                             // get data using this.
  cout << vowels[4] << endl;

  // vector<int> scores (3); // all 3 elements initialized to 0.
  // vector<int> scores (3, 100); // all 3 elements initialized to 100.

  vector<int> scores{100, 90, 80};
  cout << scores.at(0) << endl; // displaying data with at method. We can also
                                // get data using this.
  cout << scores.at(1) << endl;
  cout << scores.at(2) << endl;
  cout << "The size of scores vector " << scores.size() << endl;

  int new_score_1{0};
  scores.push_back(new_score_1);

  int new_score_2{10};
  scores.push_back(new_score_2);

  cout << scores.at(0) << endl;
  cout << scores.at(1) << endl;
  cout << scores.at(2) << endl;
  cout << scores.at(3) << endl;
  cout << scores.at(4) << endl;

  cout << "==============================" << endl;
  cout << "Two Dimensional Vector (2-D Vector)" << endl;

  vector<vector<int>> movie_ratings{{1, 2, 3, 4}, {1, 2, 4, 5}, {1, 2, 5, 6}};

  cout << "Movie rating of No.1 reveiwer" << endl;
  cout << movie_ratings[0][0] << endl;
  cout << movie_ratings[0][1] << endl;
  cout << movie_ratings[0][2] << endl;
  cout << movie_ratings[0][3] << endl;

  cout << "Movie rating of No.2 reveiwer" << endl;
  cout << movie_ratings[1][0] << endl;
  cout << movie_ratings[1][1] << endl;
  cout << movie_ratings[1][2] << endl;
  cout << movie_ratings[1][3] << endl;

  cout << "Movie rating of No.3 reveiwer" << endl;
  cout << movie_ratings[2][0] << endl;
  cout << movie_ratings[2][1] << endl;
  cout << movie_ratings[2][2] << endl;
  cout << movie_ratings[2][3] << endl;
  return 0;
}