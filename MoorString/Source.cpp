#include<iostream>
#include<string>

// Прототип функции Задачи 1:
std::string spaces_str(std::string str);
// Прототип функции Задачи 2:
bool is_spam(std::string str);

int main() {
	system("chcp 1251>null");
	int n;
	// Задача 1. Пробелы в строке.
	
	std::cout << "Задакча 1.\nВведите строку -> ";
	std::string str1;
	std::getline(std::cin, str1);
	std::cout << spaces_str(str1) << std::endl;
	
	// задача 2. Проверка спама.
	std::cout << "Задача 2. Проверка спама.\nВведите строку -> ";
	std::string str2;
	std::getline(std::cin, str2);
	if (is_spam(str2))
		std::cout << "Обнаружен спам!!!\n\n";
	else
		std::cout << "Спам не обнаружен!!!\n\n";
	
	return 0;
}
// Функция Задачи 1:
std::string spaces_str(std::string str) {
	std::string result(str.length()*2 - 1, ' ');
	for (int i = 0; i < str.length(); i++)
		result[i * 2] = str[i];
	return result;
}
// Прототип функции Задачи 2:
bool is_spam(std::string str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]); // возведение каждого элемента в нижний регистр для обеспечения нерегистрозависимости функции.
	const int spams_number = 4;
	static const std::string spams[spams_number]{
		"100 free",
		"sales increase",
		"only today",
		"black friday"
	};
	for (int i = 0; i < spams_number; i++)
		if (str.find(spams[i]) < str.length()) // уточнить
			return true;
	return false;
}