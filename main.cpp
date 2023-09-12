#include "iostream"
#include "fstream"
#include <sstream>
#include <string>

using namespace std;
//создание файла
void in_file(ofstream &fout,char *name){
    fout.open(name, ios::out | ios::trunc);
    for (int i = 0; i < 10; i++)
    {
        fout << i << endl;
    }
    fout.close();
}

void output(const char* name){
    int x;
    ifstream fin;
    fin.open(name, ios::in);
    while(!fin.eof()){
        fin >> x;
        fin.get();
        cout << x;
    }
    fin.close();
}

void nextLine(ofstream &fout, char *name, int x){
    fout.open(name, ios::out | ios::app );
    fout << x;
    fout.close();
}

int numbers(char *name, int nums, int n){
    ifstream fout;
    fout.open(name);
    int x;
    int i;
    for( i = 1; (i < n && (!fout.eof()));i++){
        fout >> x;
        fout.get();
    }
    cout << endl;
    while(!fout.eof() && (i == n)){
        fout >> x;
        fout.get();
        cout << x;
        i++;
    }
    fout.close();
}

void length_file( char *name){
    ifstream fout;
    fout.open(name);
    int n = 0, x;
    cout << endl;
    while(!fout.eof()){
        fout >> x;
        fout.get();
        n++;
    }
    cout << "Количество чисел в файле = " << n;
    fout.close();
}
int main(){
    ofstream fout;
    in_file(fout,"a.txt");
    output("a.txt");
    nextLine(fout, "a.txt",5);
    int nums;
    cout << "Введите порядковый номер в файле:";
    cin >> nums;
    numbers("a.txt", nums,5);
    length_file("a.t");
}
