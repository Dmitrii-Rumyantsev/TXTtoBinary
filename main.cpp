#include "iostream"
#include "fstream"
#include <sstream>
#include <string>

using namespace std;
//создание файла
/*
void in_file(ofstream& fout,const char* name) {
    fout.open(name, ios::out | ios::trunc);
    for (int i = 0; i < 10; i++)
    {
        fout << i << endl;
    }
    if( fout.good())
    {
        cout << "Ошибок не найдено в функции создания файла\n";
    }
    else
    {
        cout << "Найдена ошибка ввода или вывода\n";
    }
    fout.close();
}

void output(const char* name) {
    int x;
    ifstream fout;
    fout.open(name, ios::in);
    while (fout >> x) {
        cout << x << " ";
    }
    cout << endl;
    fout.close();
}

void nextLine(ofstream& fout, const char* name, int x) {
    fout.open(name, ios::out | ios::app);
    fout << x;
    if (fout.good())
    {
        cout << "Ошибок не найдено в функции добавления записи в файл\n";
    }
    else
    {
        cout << "Найдена ошибка вывода\n";
    }
    fout.close();
}

void numbers(const char* name, int nums) {
    ifstream fout;
    fout.open(name);
    int x;
    int i;
    for (i = 1; (i < nums && (!fout.eof())); i++) {
        fout >> x;
        fout.get();
    }
    cout << endl;
    while (!fout.eof() && (i == nums)) {
        fout >> x;
        fout.get();
        cout << x;
        i++;
    }
    if (fout.good())
    {
        cout << "\nОшибок не найдено в функции нахождения порядкового номера\n";
    }
    fout.close();
}

void length_file( const char* name) {
    ifstream fout;
    fout.open(name);
    int n = 0, x;
    cout << endl;
    while (!fout.eof()) {
        fout >> x;
        fout.get();
        n++;
    }
    cout << "Количество чисел в файле = " << n << endl;
    fout.close();
}

void myTasks(const char* a_file, const char* b_file)
{
    ifstream first_file;
    first_file.open(a_file, ios::in);
    ofstream second_file;
    second_file.open(b_file, ios::out | ios::trunc);
    int x;
    while (first_file >> x)
    {
        bool del = true;
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0 || x == 0 || x == 1)
            {
                del = false;
            }
        }
        if (del && x != 0 && x != 1)
        {
            second_file << x << endl;
        }
    }
    if (second_file.good())
    {
        cout << "Ошибка ввода не найдено!\n";
    }
    second_file.close();
    ifstream output_second_file;
    output_second_file.open(b_file, ios::in);
    cout << "Вывод простых чисел нового файла извлеченных из старого\n";
    while (output_second_file >> x)
    {
        cout << x << endl;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    ofstream fout;
    if(!fout)
    {
        cout << "Файл не удалось открыть";
        return -1;
    }
    in_file(fout, "a.txt");
    output("a.txt");
    int x;
    cout << "Введите элемент который хотите добавить: ";
    cin >> x;
    nextLine(fout, "a.txt", x);
    int nums;
    cout << "Введите порядковый номер в файле:";
    cin >> nums;
    numbers("a.txt", nums);
    length_file("a.txt");
    myTasks("a.txt", "b.txt");
}
*/
#include "string"

struct diseases
{
    int number_OMS, number_disease, date, doctor;
    string family, name, patronymic;
};

void txt_to_binary(ifstream &txt, ofstream &bin)
{
    diseases human;
    while (!txt.eof())
    {
        txt >> human.number_OMS;
        txt.get();
        getline(txt, human.family);
        getline(txt, human.name);
        getline(txt, human.patronymic);
        txt >> human.number_disease;
        txt.get();
        txt >> human.date;
        txt.get();
        txt >> human.doctor;
        txt.get();
        bin.write((char*)&human, sizeof(diseases));
    }
    txt.close();
    bin.close();
}

void binary_to_txt(ifstream& bin, ofstream& txt)
{
    diseases human;
    bin.read((char*)&human, sizeof(diseases));
    while (bin.read((char*)&human, sizeof(diseases)))
    {
        txt << human.number_OMS << endl << human.family << endl << human.name << endl << human.patronymic << endl << human.number_disease << endl << human.date << endl << human.doctor << endl;
    }

    if (!bin.eof() && bin.fail())
    {
        // Обработайте ошибку чтения из файла
        cout << "Error reading from binary file." << endl;
    }
}

void print_binnary(ifstream &bin)
{
    diseases human;
    bin.read((char*)&human, sizeof(diseases));
    while (!bin.eof())
    {
        cout << human.number_OMS << endl << human.family << endl << human.name << endl << human.patronymic << endl << human.number_disease << endl << human.date << endl << human.doctor;
        bin.read((char*)&human, sizeof(diseases));
    }
    bin.close();
}

void key_bin(ifstream &bin, int n)
{
    diseases human;
    int count = 0;
    while(!bin.eof() && n != count + 1)
    {
        bin.read((char*)&human, sizeof(diseases));
        count++;
    }
    bin.read((char*)&human,sizeof(diseases));
    cout << human.number_OMS << endl << human.family << endl << human.name << endl << human.patronymic << endl << human.number_disease << endl << human.date << endl << human.doctor;
    if(bin.good())
    {
        cout << "Ошибок вывод не обрнаружено\n";
    }
    else
    {
        cout << "Обнаружена ошибка вывода\n";
    }
    bin.close();
}


void delete_bin(fstream &bin, int n)
{
    diseases human;
    int key = 0;
    while (!bin.eof())
    {
        bin.read((char*)&human, sizeof(diseases));
        if (key == n) {
            bin.seekp(0, ios::end);
        }
        if(key > n)
        {
            bin.seekg(key - 2, ios::beg);
        }
    }
    bin.close();

}

int main()
{
    setlocale(LC_ALL, "Russian");
    string binary_name, txt_name;
    cin >> txt_name >> binary_name;
    ifstream txt(txt_name, ios::out);
    ofstream bin(binary_name, ios::binary | ios::out);

    if (!bin || !txt)
    {
        cout << "Файл не открыт!\n";
        return -1;
    }
    int x = 1;
    
    while (x != 0)
    {
        cin >> x;
        switch (x)
        {
        case 1: {
            txt_to_binary(txt, bin);
            break;
        }
        case 2: {
            ofstream tt(txt_name, ios::out);
            ifstream bn(binary_name, ios::binary | ios::in);
            binary_to_txt(bn, tt);
            bn.close();
            break;
        }
        case 3: {
            ifstream bn(binary_name, ios::binary | ios::in);
            print_binnary(bn);
            break;
        }
        case 4: {
            ifstream bn(binary_name, ios::binary | ios::in);
            key_bin(bn, 2);
            break;
        }
        case 5: {
            fstream bg(binary_name, ios::binary | ios::in);
            delete_bin(bg, 1);
            break;
        }
        }
    }
    return 0;
}
