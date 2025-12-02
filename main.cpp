#include "string.hpp"
#include <iostream>

int main() {
    // Создание строк
    String s1("Hello");
    String s2(" World!");
    String s3 = s1 + s2;

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3 (s1 + s2): " << s3 << std::endl;

    // Длина строки
    std::cout << "Длина s3: " << s3.getLength() << std::endl;

    // Поиск символа
    int pos = s3.find('W');
    std::cout << "Символ 'W' в s3 на позиции: " << pos << std::endl;

    // Подстрока
    String sub = s3.substr(6, 5);
    std::cout << "Подстрока s3[6-10]: " << sub << std::endl;

    // Вставка
    s1.insert(5, " C++");
    std::cout << "После вставки: " << s1 << std::endl;

    // Удаление
    s1.remove(5, 4);
    std::cout << "После удаления: " << s1 << std::endl;

    // Конкатенирование
    std::cout << "Конкатенация: " << String::concat(s1, s2) << std::endl;

    // Проверка операторов
    String s4 = s1;
    std::cout << "s4 (копия s1): " << s4 << std::endl;
    std::cout << "s1 == s4? " << (s1 == s4 ? "Да" : "Нет") << std::endl;
    std::cout << "s1 != s2? " << (s1 != s2 ? "Да" : "Нет") << std::endl;

    return 0;
}