#include <iostream>
#include <fstream>
#include <string>

//Task1
bool file_insert(std::string path, int pos, std::string str)
{
	static std::fstream fs; //для записи и считывания в статической области видимости, для эффективности
	fs.open(path, std::ios::in); // открываем в режиме считывания in

	if (!fs.is_open())
	{
		return false; //если не получилось открыть то возвращаем фолс
	}
	std::string file, line; // file - строка для содкржмого файла , line - строка для построчного считывания
	
	while (std::getline(fs, line))
		file += line + '\n';

	fs.close(); //закрываем

	file.insert(pos, str); //вставляет строку в позицию строки

	fs.open(path, std::ios::out); //открыли файл чобы записать в нег, out - для уничтожения  всего что внутри строки
		if (!fs.is_open())
			return false; // если не полуичлось открыть

		fs << file; //  записываем данные в файл
		fs.close(); // закрываем файл
		return true; 
}
//Task2


int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	const std::string path = "file.txt";
	//класс fstream для записи и чтения файла
	
	std::fstream fs; // использование метода fstream
	fs.open(path, std::ios::in | std::ios::app); //объединяем режимы открытия с помощью перегрузки операции битового или 
	// || - логическое или, | - битовое или 

	if (fs.is_open())
	{
		std::cout << "Файл открыт\n";
		//Ввод данных в файл, вводит с помощью режима app
		std::cout << "Введите строку -> ";
		std::string str;
		std::getline(std::cin, str);
		fs << str << "\n";
		//смещение курсора для считывания в начало файла
		fs.seekg(0, std::ios::beg);

		//чтение данных из файла
		std::cout << "Содержимое файла:\n";
		char sym;
		while (fs.get(sym))
			std::cout << sym;
		std::cout << std::endl;

	}

	else
	{
		std::cout << "Файл не открывается\n";
	}

	fs.close();
	

	//Задача 1 вставка в середину файла
	
	if (file_insert(path, 3, "###"))
		std::cout << "строка вставлена успешно\n\n";
	else
		std::cout << "ошибка выполнения функции\n\n";
		
	//Task2 парсинг даты файла
	std::cout << "Дата: ";
	std::ifstream in;
	in.open("date.txt");

	if (in.is_open())
	{
		std::string date;
		in >> date;
		std::cout << date << std::endl;

		int day = std::stoi(date);
		int month = std::stoi(date.substr(date.find('.') + 1)); 
		int year = std::stoi(date.substr(date.rfind('.') + 1));

		std::cout << "День: " << day << std::endl;
		std::cout << "Месяц: " << month << std::endl;
		std::cout << "Год: " << year << std::endl;
	}


	return 0;
}