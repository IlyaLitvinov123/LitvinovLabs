#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <vector>

enum class Gender {
    Male,
    Female
};

struct Person {
    std::array<char, 20> name;
    int age;
    Gender gender;
};

// ������� ��� ������������ ������ � ����� ������
bool serializeString(const std::array<char, 20>& str, std::ostream& stream) {
    // ������ ������� ������� ������ � �����, �������� �� ������� �������� ������� ��� �������
    for (const char& c : str) {
        if (c == '\0' || c == ',') {
            return false; // ������� false, ���� ������� ������� ��� ������� ������
        }
        stream << c;
    }
    return true; // ������� true, ���� ������������ ������ �������
}

// ������� ��� ������������ �������������� �������� � ����� ������
bool serializeInt(int value, std::ostream& stream) {
    stream << value; // ������ �������� � �����
    return true; // ������� true, ���� ������������ ������ �������
}

// ������� ��� ������������ �������� enum Gender � ����� ������
bool serializeGender(Gender gender, std::ostream& stream) {
    // ������ �������� enum � ���� ������� ��� ������ � �����
    switch (gender) {
    case Gender::Male:
        stream << "M"; // ������� ��� �������������� ��� "M"
        break;
    case Gender::Female:
        stream << "F"; // ������� ��� �������������� ��� "F"
        break;
    }
    return true; // ������� true, ���� ������������ ������ �������
}

// ������� ��� ������������ ������� Person � ����� ������
bool serializePerson(const Person& person, std::ostream& stream) {
    // ������������ ������� ���� ������� Person, ���������� �������� ��������
    if (!serializeString(person.name, stream) || !stream << ',' || !serializeInt(person.age, stream) || !stream << ',' || !serializeGender(person.gender, stream)) {
        return false; // ������� false, ���� ������������ �� �������
    }
    return true; // ������� true, ���� ������������ ������ �������
}

// ������� ��� �������������� ������ �� ������ � ������ ��������
bool deserializeString(std::array<char, 20>& buffer, std::istream& stream) {
    // ���������� ������ �� ������ �� �������, ������ � ������ ��������
    stream.getline(buffer.data(), 20, ',');
    return !stream.fail(); // ������� true, ���� �������� ���������� ������ �������
}

// ������� ��� �������������� �������������� �������� �� ������
bool deserializeInt(int& value, std::istream& stream) {
    stream >> value; // ���������� �������������� �������� �� ������
    return !stream.fail(); // ������� true, ���� �������� ���������� ������ �������
}

// ������� ��� �������������� �������� enum Gender �� ������
bool deserializeGender(Gender& gender, std::istream& stream) {
    char genderChar;
    stream >> genderChar;

    switch (genderChar) {
    case 'M':
        gender = Gender::Male; // ���������� �������� Male, ���� ��������� ������ - 'M'
        break;
    case 'F':
        gender = Gender::Female; // ���������� �������� Female, ���� ��������� ������ - 'F'
        break;
    default:
        return false; // ������� false, ���� �������� ��������������
    }
    return true; // ������� true, ���� �������� ������ �������
}

// ������� ��� �������������� ������� Person �� ������
bool deserializePerson(Person& person, std::istream& stream) {
    // �������������� ������� ���� ������� Person �� ������, ��������� ���������� �������� ��������
    if (!deserializeString(person.name, stream) || !deserializeInt(person.age, stream) || !deserializeGender(person.gender, stream)) {
        return false; // ������� false, ���� �������������� �� �������
    }
    return true; // ������� true, ���� �������������� ������ �������
}

// ������� ��� ������������ ������� �������� Person � ����� ������
bool serializePeople(const std::vector<Person>& people, std::ostream& stream) {
    for (const auto& person : people) {
        if (!serializePerson(person, stream) || !stream << '\n') {
            return false; // ������� false, ���� ������������ �� �������
        }
    }
    return true; // ������� true, ���� ������������ ������ �������
}

// ������� ��� �������������� ������� �������� Person �� ������
bool deserializePeople(std::vector<Person>& people, std::istream& stream) {
    std::string line;
    while (std::getline(stream, line)) {
        Person person;
        if (!deserializePerson(person, stream)) {
            return false; // ������� false, ���� �������������� �� �������
        }
        people.push_back(person); // ���������� ������� � ������
    }
    return true; // ������� true, ���� �������������� ������ �������
}

int main() {
    // ... (��� ��� ������ � �������)
    return 0;
}