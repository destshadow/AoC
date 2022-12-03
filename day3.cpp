#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>

/* PARTE 1
    1) 7967 -> giusto al primo tentativo

    PARTE 2
    1) 
*/

std::vector<std::string> ReadFromFile(char *filename){
    std::string a = "";
    std::ifstream ifs(filename, std::ios::in );
    std::vector<std::string> array;
    

    ifs.seekg(0, std::ios::beg);

    if(ifs.is_open()){
        while ( ifs ){
            std::getline(ifs, a); //così itero sulle linee intere fino al delimitatore di default che e' \n ifs.get() -> restituisce carattere per carattere invece
            //std::cout << a << "\n";
            array.push_back(a);
        }
    }else{
        std::cout << "impossibile aprire il file\n";
    }
    //std::cout << "\n" << array.size() << "\n";
    ifs.close();

    return array;
    
}

char Compare(std::vector<char> a, std::vector<char> b){
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] == b[j]){
                //std::cout << a[i];
                return a[i];
            }
        }
    }
    return -1;
}

int soluzione(std::string a){
    std::vector<char> primaparte;
    std::vector<char> seconda;

    for(int i = 0; i < a.size() / 2; i++){
        primaparte.push_back(a[i]);
    }

    for(int i = a.size() / 2; i < a.size() ; i++){
        seconda.push_back(a[i]);
    }

    char lettera = Compare(primaparte, seconda); // da fare un loop per ogni lettera;

    if(lettera >= 'a'){
        //std::cout << (lettera - 'a') + 1<< "\n";
        return (lettera - 'a') + 1;
    }else{
        //std::cout << (lettera - 'A') + 27 << "\n";
        return (lettera - 'A') + 27;
    }
}

char Compare2(std::string a, std::string b, std::string c){

    std::vector<char> sol;

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] == b[j]){
                //std::cout << a[i];
                sol.push_back(a[i]);
            }
        }
    }

    for(int i = 0; i < c.size(); i++){
        for(int j = 0; j < sol.size(); j++){
            if(c[i] == sol[j]){
                //std::cout << c[i];
                return c[i];
            }
        }
    }
    
    return -1;
}

int Soluzione2(std::string a, std::string b, std::string c){
    char lettera = Compare2(a, b, c);
    //std::cout << lettera << "\n";

    if(lettera >= 'a'){
        //std::cout << (lettera - 'a') + 1<< "\n";
        return (lettera - 'a') + 1;
    }else{
        //std::cout << (lettera - 'A') + 27 << "\n";
        return (lettera - 'A') + 27;
    }
}

int main(int argc, char **argv){

    if(argc < 1){
        std::cout << "errore nel passaggio dei file\n";
        return 0;
    }

    std::vector<std::string> array;

    array = ReadFromFile(argv[1]);
    int sol = 0;

    for(int i = 0; i < array.size() - 1; i++){
        sol += soluzione(array[i]);
    }
    //std::cout << array.size() << "\n";
    std::cout << sol << "\n";

    sol = 0;

    for(int i = 3; i < array.size(); i += 3){
        sol += Soluzione2(array[i - 1], array[i-2], array[i-3]);
    }

    std::cout << sol << "\n";

    return 0;
}