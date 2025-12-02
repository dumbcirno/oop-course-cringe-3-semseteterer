#ifndef STRING_H
#define STRING_H

#include <iostream>

class AbstractString {
public:
    virtual int getLength() const = 0;
    virtual void print() const = 0;
    virtual ~AbstractString() {}
};

class String : public AbstractString {
private:
    char* data;
    int length;
    static int count; // статический счетчик строк

public:
    // Конструкторы
    String();
    String(const char* str);
    String(const String& other); // конструктор копирования
    ~String();

    // Методы
    int getLength() const override;
    const char* c_str() const;
    void clear();
    static String concat(const String& str1, const String& str2);
    String concat(const String& other) const;
    int find(char ch) const;
    String substr(int start, int len) const;
    void insert(int pos, const String& other);
    void insert(int pos, const char* str);
    void remove(int pos, int len);

    // Перегрузка операторов
    String& operator=(const String& other);
    String operator+(const String& other) const;
    String& operator+=(const String& other);
    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;
    char& operator[](int index);
    const char& operator[](int index) const;

    // Виртуальный метод вывода
    void print() const override;

    // Дружественные функции для ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, String& str);
};

#endif