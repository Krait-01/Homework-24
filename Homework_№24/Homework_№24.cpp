#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cwctype>
#include <limits>

/*
Задача 1
Дана строка str. Пользователь вводит символ sym. Программа создаёт новую строку, которая состоит изсимвола sym. Длина новой строки равна количеству совпадений введённого символа в изначальной строке str.
Пример:
str = "Hello world!"
sym = 'l'
newStr = "lll"

Задача 2
Создайте функцию, которая принимает слово и возвращает true, если оно является палиндромом. В противном случае возвращается false. Функция должна быть нерегистрозависимой.

Задача 3
Создайте функцию, которая принимает строку. Функция считает все пробелы, точки, запятые, восклицательные и вопросительные знаки, которые есть в переданной строке и возвращает их общее количество.
*/

using namespace std;

// Задача 2
static bool equalsNoCase(const string& s1, const string& s2)
{
    if (s1.size() != s2.size())
        return false;
    for (int i = 0; i < s1.size(); i++)
    {
        if (towlower(s1[i]) == towlower(s2[i]))
            continue;
        return false;
    }

    return true;
}

static bool isPalindrome(const string& s)
{
    string reversed(s.crbegin(), s.crend());
    return equalsNoCase(s, reversed);
}

// Задача 3
static int countPunct(const string& s)
{
    int result = 0;
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case ' ':
        case '.':
        case ',':
        case '!':
        case '?':
        case '\t':
        
            result++;
            break;
        }
    }

    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // Задача 1
    cout << "Задача 1\n";
    string str = "Hello world!";
    char sym;
    cout << "Введите один символ из предложения 'Hello world!': ";
    cin >> sym;
    cout << "Количество совпадений введённого символа: ";
    string res;
    for (int i = 0; i < str.length(); i++)
        if (str[i] == sym)
            res += sym;
    cout << res << "\n\n";

    // Задача 2
    cout << "Задача 2\n";
    cout << "Палиндром \"ХОЧУ ПИЦЦУ\": " << boolalpha << isPalindrome("хочу пиццу") << endl;
    cout << "Палиндром \"ЛЕПС СПЕЛ\": " << boolalpha << isPalindrome("лепс спел") << endl;

    // Задача 3
    cout << "\nЗадача 3\nПринятая строка:\nСегодня был очень пасмурный, хмурый, дождливый день и погулять с моими друзьями не удалось!";
    const string sv = "Сегодня был очень пасмурный, хмурый, дождливый день и погулять с моими друзьями не удалось!";
    cout << "\nОбщее количество всех знаков из переданной строки: " << countPunct(sv) << endl;

    return 0;
}