#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cwctype>
#include <limits>

/*
������ 1
���� ������ str. ������������ ������ ������ sym. ��������� ������ ����� ������, ������� ������� ��������� sym. ����� ����� ������ ����� ���������� ���������� ��������� ������� � ����������� ������ str.
������:
str = "Hello world!"
sym = 'l'
newStr = "lll"

������ 2
�������� �������, ������� ��������� ����� � ���������� true, ���� ��� �������� �����������. � ��������� ������ ������������ false. ������� ������ ���� �������������������.

������ 3
�������� �������, ������� ��������� ������. ������� ������� ��� �������, �����, �������, ��������������� � �������������� �����, ������� ���� � ���������� ������ � ���������� �� ����� ����������.
*/

using namespace std;

// ������ 2
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

// ������ 3
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

    // ������ 1
    cout << "������ 1\n";
    string str = "Hello world!";
    char sym;
    cout << "������� ���� ������ �� ����������� 'Hello world!': ";
    cin >> sym;
    cout << "���������� ���������� ��������� �������: ";
    string res;
    for (int i = 0; i < str.length(); i++)
        if (str[i] == sym)
            res += sym;
    cout << res << "\n\n";

    // ������ 2
    cout << "������ 2\n";
    cout << "��������� \"���� �����\": " << boolalpha << isPalindrome("���� �����") << endl;
    cout << "��������� \"���� ����\": " << boolalpha << isPalindrome("���� ����") << endl;

    // ������ 3
    cout << "\n������ 3\n�������� ������:\n������� ��� ����� ���������, ������, ��������� ���� � �������� � ����� �������� �� �������!";
    const string sv = "������� ��� ����� ���������, ������, ��������� ���� � �������� � ����� �������� �� �������!";
    cout << "\n����� ���������� ���� ������ �� ���������� ������: " << countPunct(sv) << endl;

    return 0;
}