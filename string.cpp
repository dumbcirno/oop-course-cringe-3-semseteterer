#include "string.hpp"
#include <cstring>
#include <iostream>

// Конструктор по умолчанию
String::String() : data(new char[1]), length(0) {
    data[0] = '\0';
}

// Конструктор от C-строки
String::String(const char* str) : length(strlen(str)) {
    data = new char[length + 1];
    strcpy(data, str);
}

// Конструктор копирования
String::String(const String& other) : length(other.length) {
    data = new char[length + 1];
    strcpy(data, other.data);
}

// Деструктор
String::~String() {
    delete[] data;
}

// Длина строки
int String::getLength() const {
    return length;
}

// Возврат C-строки
const char* String::c_str() const {
    return data;
}

// Очистка строки
void String::clear() {
    delete[] data;
    data = new char[1];
    data[0] = '\0';
    length = 0;
}

// Конкатенация
String String::concat(const String& str1, const String& str2)  {
    String result;
    result.length = str1.length + str2.length;
    result.data = new char[result.length + 1];
    strcpy(result.data, str1.data);
    strcat(result.data, str2.data);
    return result;
}

// Поиск символа
int String::find(char ch) const {
    for (int i = 0; i < length; i++) {
        if (data[i] == ch) return i;
    }
    return -1;
}

// Подстрока
String String::substr(int start, int len) const {
    if (start < 0 || start >= length || len <= 0) return String();
    if (start + len > length) len = length - start;
    char* sub = new char[len + 1];
    strncpy(sub, data + start, len);
    sub[len] = '\0';
    String result(sub);
    delete[] sub;
    return result;
}

// Вставка строки
void String::insert(int pos, const String& other) {
    if (pos < 0 || pos > length) return;
    int newLen = length + other.length;
    char* newData = new char[newLen + 1];
    strncpy(newData, data, pos);
    strcpy(newData + pos, other.data);
    strcpy(newData + pos + other.length, data + pos);
    delete[] data;
    data = newData;
    length = newLen;
}

// Вставка C-строки
void String::insert(int pos, const char* str) {
    if (pos < 0 || pos > length || str == nullptr) return;
    int strLen = strlen(str);
    int newLen = length + strLen;
    char* newData = new char[newLen + 1];
    strncpy(newData, data, pos);
    strcpy(newData + pos, str);
    strcpy(newData + pos + strLen, data + pos);
    delete[] data;
    data = newData;
    length = newLen;
}

// Удаление части строки
void String::remove(int pos, int len) {
    if (pos < 0 || pos >= length || len <= 0) return;
    if (pos + len > length) len = length - pos;
    int newLen = length - len;
    char* newData = new char[newLen + 1];
    strncpy(newData, data, pos);
    strcpy(newData + pos, data + pos + len);
    delete[] data;
    data = newData;
    length = newLen;
}

String String::concat(const String& other) const {
    String result;
    result.length = length + other.length;
    delete[] result.data;
    result.data = new char[result.length + 1];
    strcpy(result.data, data);
    strcat(result.data, other.data);
    return result;
}

// Оператор присваивания
String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }
    return *this;
}

// Оператор сложения
String String::operator+(const String& other) const {
    return concat(other);
}

// Оператор +=
String& String::operator+=(const String& other) {
    *this = *this + other;
    return *this;
}

// Оператор сравнения
bool String::operator==(const String& other) const {
    return strcmp(data, other.data) == 0;
}

bool String::operator!=(const String& other) const {
    return !(*this == other);
}

// Оператор индексации
char& String::operator[](int index) {
    return data[index];
}

const char& String::operator[](int index) const {
    return data[index];
}

// Вывод строки
void String::print() const {
    std::cout << data;
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.data;
    return os;
}

// Оператор ввода
std::istream& operator>>(std::istream& is, String& str) {
    char buffer[256];
    is >> buffer;
    str = String(buffer);
    return is;
}