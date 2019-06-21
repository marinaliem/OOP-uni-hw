#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

class Book {
	char* title;
	int pageNum;
public:
	Book() {
		copy("Default Title", 1);
	}
	Book(const char* _title, int _pageNum) {
		copy(_title, _pageNum);
	}
	Book(const Book &b) {
		copy(b.title, b.pageNum);
	}
	~Book() {
		del();
	}
	void setTitle(const char* title1) {
		del();
		strcpy_s(title, strlen(title) + 1, title1);
	}
	char* getTitle() const {
		return title;
	}
	void setPageNum(int pageNum1) {
		pageNum = pageNum1;
	}
	int getPageNum() const {
		return pageNum;
	}
	void del() {
		delete[] title;
	}
	void copy(const char* nTitle, int nPageNum) {
		int len = strlen(nTitle) + 1;
		title = new char[len];
		strcpy_s(title, len, nTitle);
		pageNum = nPageNum;
	}
	friend ostream &operator<<(ostream &o, const Book &other) {
		o << "Title: " << other.title << endl << "Number of pages: " << other.pageNum;
		return o;
	}
	friend istream &operator>>(istream &i, Book &other) {
		i >> other.title >> other.pageNum;
		return i;
	}
	bool operator>(const Book &b) {
		if (strcmp(title, b.title) > 0) return true;
		else return false;
	}
	bool operator<(const Book &b) {
		if (strcmp(title, b.title) < 0) return true;
		else return false;
	}
};

class EBook : public Book {
	int size;
	int timesOpen;
public:
	EBook(int s, int t) {
		setSize(s);
		setTimesOpen(t);
	}
	int getSize() const {
		return size;
	}
	int getTimesOpen() const {
		return timesOpen;
	}
	void setSize(int _size) {
		size = _size;
	}
	void setTimesOpen(int _timesOpen) {
		timesOpen = _timesOpen;
	}
	double rating() {
		if (timesOpen > 200) return 5;
		return timesOpen / 40;
	}
};

template<typename T>
class Library {
	T* books;
	int current;
	int cap;//capacity
public:
	int getCap() {
		return cap;
	}
	Library<T>() {
		current = -1;
		cap = 10;
		books = new T[cap];
	}
	void remove() {
		delete[] books;
	}
	void resize() {
		T* books2 = new T[cap];
		for (int i = 0; i < current; i++) {
			books2[i] = books[i];
		}
		remove();
		books = new T[cap * 2];
		for (int i = 0; i <= current; i++) {
			books[i] = books2[i];
		}
		cap = cap * 2;
		delete[] books2;
	}
public:
	void addBook(T const& bk) {
		if (current == cap - 1) {
			resize();
		}
		books[current] = bk;
		current++;
	}
	void removeBook() {
		delete books[cap - 1];
		current--;
	}
	double avr() {
		double sum = 0;
		for (int i = 0; i < cap - 1; i++) {
			sum += books[i].getPageNum();
		}
		return sum / cap;
	}
	Book &operator[](int index) {
		return books[index];
	}
	void sortByTitle() {
		for (int i = 0; i < cap - 1; i++) {
			if (books[i] > books[i + 1]) swap(books[i], books[i + 1]);
		}
	}

};

int main()
{
	//test

	//Library<Book> lib = Library<Book>();
	////lib.resize();
	//Book book1 = Book();
	//for (int i = 0; i < 10; i++) {
	//	lib.addBook(book1);
	//}
	//lib[5].setTitle("April");
	//cout << lib.avr();
	//lib.sortByTitle();
	//cout << (Book) lib[0];
	/*Book boo1 = Book("Ave maria", 4);
	Book boo2 = Book("Xander 1vi", 9);
	cout << (boo1 > boo2) << endl;*/
	return 0;
}