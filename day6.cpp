#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>


/* PARTE 1
    1) 1175 -> non capivo come si doveva risolvere sta roba all'inizio

    PARTE 2
    1) 28 -> no
    2) 114 -> no
    3) 3217 -> si, fino all'ultimo non avevo capito la consengna -> ho risolto con una mappa ed è diventato estremamente facile
*/

std::string ReadFromFile(char *filename){
    std::string a = "";
    std::ifstream ifs(filename, std::ios::in );
    std::vector<int> array;

    ifs.seekg(0, std::ios::beg);

    if(ifs.is_open()){
        while ( ifs ){
            std::getline(ifs, a); //così itero sulle linee intere fino al delimitatore di default che e' \n ifs.get() -> restituisce carattere per carattere invece
            //std::cout << a << "\n";
            //array.push_back(std::stoi(a)); //inserisco in un array senza dimensione iniziale che cresce mano a mano
        }
    }else{
        std::cout << "impossibile aprire il file\n";
    }
    //std::cout << "\n" << array.size() << "\n";
    ifs.close();

    return a;
}

bool controllo(char a, char b, char c, char d){
    if(a != b && a != c && a != d){
        if(b != c && b != d){
            if(c != d){
                return true;
            }
        }
    }
    return false;
}

int Resolve1(std::string a){

    for(int i = 1; i < a.size() - 3; i++){
        if(controllo(a[i], a[i+1], a[i+2], a[i+3])){
            return i + 4;
        }
    }



    return 0;
}

bool Controllo2( std::string resolve){

    std::map <char, int> a;

    /*for(int i = 0; i < resolve.size(); i++){
        //a[resolve[i]] = 0; 
    }*/
    for(int i = 0; i < resolve.size(); i++){
        a[resolve[i]] += 1; 
    }

    /*for(int i = 0; i < resolve.size(); i++){
        std::cout << a[resolve[i]] << " ";
    }*/
    //std::cout << "\n";

    //std::cout << resolve.size() << " " << a.size() << "\n";

    if(a.size() == resolve.size()){
        return true;
    }


    return false;
}

int Resolve2(std::string a){
    std::string resolve = "";

    for(int i = 0; i < a.size()-13; i++){
        resolve.erase(resolve.begin(), resolve.end());
        for(int j = 0; j < 14; j++){
            resolve += a[i + j];
        }
        //std::cout << resolve << "\n";
        if(Controllo2(resolve)){
            return i + 14;
        }
    }

    return 0;
}

int main(int argc, char **argv){

    if(argc < 1){
        std::cout << "errore nel passaggio dei file\n";
        return 0;
    }


    std::string result = ReadFromFile(argv[1]);

    //std::cout << result.size() / 4 << "\n";

    std::cout << Resolve1(result) << "\n";
    std::cout << Resolve2(result) << "\n";

    return 0;

}