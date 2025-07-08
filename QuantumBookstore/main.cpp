#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int isbn;
    string title;
    string author;
    float price;
    int quantity;
    string type;
    int year;

    Book() {}

    Book(int i, string t, string a, float p, int q, string ty, int y) {
        isbn = i;
        title = t;
        author = a;
        price = p;
        quantity = q;
        type = ty;
        year = y;
    }
};

vector<Book> store;
vector<Book> cart;

Book* findBook(int isbn) {
    for (int i = 0; i < store.size(); i++) {
        if (store[i].isbn == isbn) {
            return &store[i];
        }
    }
    return nullptr;
}

void showBooks() {
    cout << "\nQuantum book store: Available books:\n";
    for (int i = 0; i < store.size(); i++) {
        Book b = store[i];
        cout << i + 1 << ". " << b.title
             << " | Author: " << b.author
             << " | Type: " << b.type
             << " | Price: " << b.price
             << " | ISBN: " << b.isbn
             << " | Year: " << b.year << endl;
    }
}

void showCart() {
    cout << "\nQuantum book store: Your cart:\n";
    if (cart.empty()) {
        cout << "Quantum book store: Cart is empty.\n";
    } else {
        for (int i = 0; i < cart.size(); i++) {
            cout << i + 1 << ". " << cart[i].title << " | ISBN: " << cart[i].isbn << endl;
        }
    }
}

int main() {
    store.push_back(Book(1, "C++ Basics", "Sara", 100, 5, "paper", 2020));
    store.push_back(Book(2, "Java Guide", "Ali", 80, 2, "ebook", 2023));
    store.push_back(Book(3, "Demo Book", "Nada", 0, 0, "showcase", 2010));

    int choice;
    do {
        cout << "\n--- Quantum book store: Menu ---\n";
        cout << "1. Show books\n";
        cout << "2. Add book to cart\n";
        cout << "3. Show cart\n";
        cout << "4. Remove book from cart\n";
        cout << "5. Checkout\n";
        cout << "6. Exit\n";
        cout << "7. Remove old books\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1) {
            showBooks();
        } else if (choice == 2) {
            int isbn;
            cout << "Quantum book store: Enter ISBN to add: ";
            cin >> isbn;
            Book* b = findBook(isbn);
            if (b != nullptr) {
                cart.push_back(*b);
                cout << "Quantum book store: Book added to cart.\n";
            } else {
                cout << "Quantum book store: Book not found.\n";
            }
        } else if (choice == 3) {
            showCart();
        } else if (choice == 4) {
            int isbn;
            cout << "Quantum book store: Enter ISBN to remove: ";
            cin >> isbn;
            bool removed = false;
            for (int i = 0; i < cart.size(); i++) {
                if (cart[i].isbn == isbn) {
                    cart.erase(cart.begin() + i);
                    cout << "Quantum book store: Book removed from cart.\n";
                    removed = true;
                    break;
                }
            }
            if (!removed) cout << "Quantum book store: Book not found in cart.\n";
        } else if (choice == 5) {
            if (cart.empty()) {
                cout << "Quantum book store: Your cart is empty.\n";
            } else {
                string name, address, phone, deliveryDate;
                float total = 0;

                cout << "\nQuantum book store: Please enter your details:\n";
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Address: ";
                getline(cin, address);

                cout << "Phone number: ";
                getline(cin, phone);

                cout << "Delivery date: ";
                getline(cin, deliveryDate);

                cout << "\nQuantum book store: Order Summary:\n";
                for (Book b : cart) {
                    if (b.type == "showcase") {
                        cout << "Quantum book store: " << b.title << " is not for sale.\n";
                    } else if (b.quantity <= 0) {
                        cout << "Quantum book store: " << b.title << " is out of stock.\n";
                    } else {
                        cout << "- " << b.title << " | " << b.price << " EGP\n";
                        total += b.price;
                    }
                }

                cout << "Quantum book store: Total = " << total << " EGP\n";
                cout << "Quantum book store: Shipping to " << address << " on " << deliveryDate << "\n";
                cout << "Quantum book store: Contact " << name << " | " << phone << "\n";
                cout << "Quantum book store: Thank you for your order!\n";

                cart.clear();
            }
        } else if (choice == 6) {
            cout << "Quantum book store: Goodbye!\n";
        } else if (choice == 7) {
            int currentYear = 2025;
            int maxAge;
            cout << "Quantum book store: Enter max age of books to keep (e.g., 5): ";
            cin >> maxAge;

            vector<Book> updated;
            for (Book b : store) {
                if ((currentYear - b.year) <= maxAge) {
                    updated.push_back(b);
                } else {
                    cout << "Quantum book store: Removed old book - " << b.title << endl;
                }
            }
            store = updated;
        } else {
            cout << "Quantum book store: Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}