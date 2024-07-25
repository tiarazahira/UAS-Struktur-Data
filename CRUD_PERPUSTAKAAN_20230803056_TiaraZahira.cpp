 #include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

vector<Book> bookDatabase;

void clearScreen() {
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear");
    #endif
}

void createBook() {
    Book newBook;
    cout << "Masukkan Judul Buku: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Masukkan Nama Penulis: ";
    getline(cin, newBook.author);
    cout << "Masukkan Tahun Terbit Buku: ";
    cin >> newBook.year;
    bookDatabase.push_back(newBook);
    cout << "Data Buku Berhasil Dibuat!" << endl;
}

void readBooks() {
    if (bookDatabase.empty()) {
        cout << "Data Buku Tidak Ditemukan." << endl;
        return;
    }
    int index = 1;
    for (const auto& book : bookDatabase) {
        cout << index << ". Judul: " << book.title << endl;
		cout << "   Penulis: " << book.author << endl;
		cout << "   Tahun Terbit: " << book.year << endl;
		cout << endl;
        ++index;
    }
}

void updateBook() {
    if (bookDatabase.empty()) {
        cout << "Data Buku Tidak Ditemukan." << endl;
        return;
    }
    int index;
    cout << "Pilih Buku Berapa yang Ingin Diperbarui: ";
    cin >> index;
    if (index < 1 || index > bookDatabase.size()) {
        cout << "Tidak Ada Buku dalam List Angka Tersebut." << endl;
        return;
    }
    Book &book = bookDatabase[index - 1];
    cin.ignore(); // Clear the newline character from the input buffer
    cout << "Masukkan Nama Buku Terbaru (current: " << book.title << "): ";
    getline(cin, book.title);
    cout << "Masukkan Nama Penulis Terbaru (current: " << book.author << "): ";
    getline(cin, book.author);
    cout << "Masukkan Tahun Terbit Terbaru (current: " << book.year << "): ";
    cin >> book.year;
    cout << "Data Buku Berhasil Diperbarui!" << endl;
}

void deleteBook() {
    if (bookDatabase.empty()) {
        cout << "Data Buku Tidak Ditemukan." << endl;
        return;
    }
    int index;
    cout << "Pilih Buku Berapa yang Ingin Dihapus: ";
    cin >> index;
    if (index < 1 || index > bookDatabase.size()) {
        cout << "Tidak Ada Buku dalam List Angka Tersebut." << endl;
        return;
    }
    bookDatabase.erase(bookDatabase.begin() + index - 1);
    cout << "Data Buku Berhasil Dihapus!" << endl;
}

void adminMenu();
void userMenu();

void mainMenu() {
    int role;
    while (true) {
        clearScreen();
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        cout << " Selamat Datang Dalam Sistem Perpustakaan Online! " << endl;
        cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
        cout << endl;
        cout << "Pilihan Menu: " << endl;
		cout << "1. Admin" << endl;
		cout << "2. User" << endl;
		cout << "3. Exit" << endl;
		cout << endl;
		cout << "Masukkan Pilihan Anda Sebagai: ";
        cin >> role;
        switch (role) {
            case 1:
                adminMenu();
                break;
            case 2:
                userMenu();
                break;
            case 3:
            	cout << endl;
            	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                cout << "         Program Selesai. Terimakasih Sudah Menggunakan Sistem Perpustakaan Online. Goodbye!        " << endl;
      			cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
                return; // Exit the program
            default:
                cout << "Pilihan Tidak Ada. Pilihlah 1, 2, atau 3." << endl;
                cout << "Klik Enter Untuk Melanjutkan...";
                cin.ignore();
                cin.get();
        }
    }
}

void adminMenu() {
    int choice;
    while (true) {
        clearScreen();
        cout << "Admin Menu:" << endl;
        cout << "1. Create book" << endl;
        cout << "2. Read books" << endl;
        cout << "3. Update book" << endl;
        cout << "4. Delete book" << endl;
        cout << "5. Exit to Main Menu" << endl;
        cout << endl;
        cout << "Masukkan Pilihan Anda: ";
        cin >> choice;
        switch (choice) {
            case 1:
                createBook();
                break;
            case 2:
                readBooks();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                return; // Return to main menu
            default:
                cout << "Pilihan Tidak Ada." << endl;
        }
        cout << endl;
        cout << "Klik Enter Untuk Melanjutkan...";
        cin.ignore();
        cin.get();
    }
}

void userMenu() {
    int choice;
    while (true) {
        clearScreen();
        cout << "User Menu:" << endl;
        cout << "1. Read books" << endl;
        cout << "2. Exit to Main Menu" << endl;
        cout << endl;
        cout << "Masukkan Pilihan Anda: ";
        cin >> choice;
        switch (choice) {
            case 1:
                readBooks();
                break;
            case 2:
                return; // Return to main menu
            default:
                cout << "Pilihan Tidak Ada." << endl;
        }
        cout << "Klik Enter Untuk Melanjutkan...";
        cin.ignore();
        cin.get();
    }
}

int main() {
    mainMenu();
    return 0;
}