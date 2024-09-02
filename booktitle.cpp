#include <iostream>
#include <vector>
#include <string>

using namespace std;

int linearSearch(const vector<string>& books, const string& title) {
    for (int i = 0; i < books.size(); ++i) {
        if (books[i] == title) {
            return i;
        }
    }
    return -1;
}

void selectionSort(vector<string>& books) {
    int n = books.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (books[j] < books[minIndex]) {
                minIndex = j;
            }
        }
        swap(books[i], books[minIndex]);
    }
}

int binarySearch(const vector<string>& books, const string& title) {
    int left = 0;
    int right = books.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (books[mid] == title) {
            return mid;
        }
        if (books[mid] < title) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<string> books = {
        "Tom Lake",
        "Holly",
        "The Exchange",
        "House of Flame and Shadow",
        "Funny Story",
        "Poverty, by America",
        "Elon Musk",
        "Pageboy",
        "Prequel",
        "The Woman in Me",
        "Gone Girl",
        "The Girl with the Dragon Tattoo",
        "The Silence of the Lambs",
        "Rebecca",
        "Shutter Island",
        "The Da Vinci Code",
        "Before I Go to Sleep",
        "The Woman in White",
        "The Talented Mr. Ripley",
        "Big Little Lies",
        "The Diary of a Young Girl",
        "Long Walk to Freedom",
        "The Story of My Experiments with Truth",
        "I Know Why the Caged Bird Sings",
        "The Autobiography of Malcolm X",
        "Bossy Pants",
        "Becoming",
        "Steve Jobs",
        "Born a Crime",
        "All Quiet on the Western Front",
        "War and Peace",
        "The Things They Carried",
        "Catch-22",
        "The Red Badge of Courage",
        "For Whom the Bell Tolls",
        "A Farewell to Arms",
        "The Naked and the Dead",
        "Slaughterhouse-Five",
        "The Book Thief"
    };

    string searchTitle;
    cout << "Enter the title to search for (linear search): ";
    getline(cin, searchTitle);
    int index = linearSearch(books, searchTitle);
    if (index != -1) {
        cout << "Book found at index " << index << " (linear search)" << endl;
    } else {
        cout << "Book not found (linear search)" << endl;
    }

    selectionSort(books);
    cout << "Books after sorting:" << endl;
    for (const auto& book : books) {
        cout << book << endl;
    }

    cout << "Enter the title to search for (binary search): ";
    getline(cin, searchTitle);
    index = binarySearch(books, searchTitle);
    if (index != -1) {
        cout << "Book found at index " << index << " (binary search)" << endl;
    } else {
        cout << "Book not found (binary search)" << endl;
    }

    return 0;
}
