#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <tuple>

/* PARTE 1
    1) 571 -> orgo boio ho capito un botto di robe

    PARTE 2
    1) 917 -> gg primo tentativo
*/

std::vector<std::pair<std::pair<int,int>, std::pair<int,int>>> ReadFromFile(char *filename){
    std::string a = "";
    std::ifstream ifs(filename, std::ios::in );
    std::vector<std::pair<std::pair<int,int>, std::pair<int,int>>> array;
    int c = 0;
    std::string a1 = "";
    std::string a2 = "";
    std::string a3 = "";
    std::string a4 = "";

    ifs.seekg(0, std::ios::beg);

    if(ifs.is_open()){
        while ( ifs ){ //potevo usare direttamente una a sola rip
            std::getline(ifs, a1, '-'); //così itero sulle linee intere fino al delimitatore di default che e' \n ifs.get() -> restituisce carattere per carattere invece
            std::getline(ifs, a2, ',');
            std::getline(ifs, a3, '-');
            std::getline(ifs, a4);
            array.push_back(std::make_pair(std::make_pair(std::stoi(a1), std::stoi(a2)), std::make_pair(std::stoi(a3), std::stoi(a4))));
        }
    }else{
        std::cout << "impossibile aprire il file\n";
    }
    //std::cout << "\n" << array.size() << "\n";
    ifs.close();

    return array;
    
}

int Solution1(int a, int b, int c, int d){ //strictly contains
    
    if( c >= a && c <= b){
        if( d >= a && d <= b){
            //std::cout << a << " " << b << " " << c << " " << d << " primo caso\n";
            return 1;
        }
    }

        //oppure

    if( a >= c && a <= d){
        if(b >= c && b <= d){
            //std::cout << a << " " << b << " " << c << " " << d << " secondo caso\n";
            return 1;
        }
    }

    return 0;
}

int Solution2(int a, int b, int c, int d){ //overlap

    if(c >= a && c <= b){
        //std::cout << a << " " << b << " " << c << " " << d << " primo caso1\n";
        return 1;
        
    }else if(d >= a && d <= b){
        //std::cout << a << " " << b << " " << c << " " << d << " primo caso2\n";
        return 1;
    }

        //oppure

    if( a >= c && a <= d){
        //std::cout << a << " " << b << " " << c << " " << d << " secondo caso1\n";
        return 1;
    }else if(b >= c && b <= d){
        //std::cout << a << " " << b << " " << c << " " << d << " secondo caso2\n";
        return 1;
    }


    return 0;
}

int main(int argc, char **argv){
    
    if(argc < 1){
        std::cout << "errore nel passaggio dei file\n";
        return 0;
    }
    std::vector<std::pair<std::pair<int,int>, std::pair<int,int>>> array;

    array = ReadFromFile(argv[1]);

    //std::cout << array.size() << "\n";

    /*for(int i = 0; i < array.size() -1 ; i++){
        std::cout << array[i].first.first << " ";
        std::cout << array[i].first.second << "-";
        std::cout << array[i].second.first << " ";
        std::cout << array[i].second.second << "\n";
    }*/

    int sol = 0;

    for(int i = 0; i < array.size() - 1; i++){
        sol += Solution1(array[i].first.first,array[i].first.second,array[i].second.first,array[i].second.second);
    }

    std::cout << sol << "\n";

    sol = 0;
    for(int i = 0; i < array.size() - 1; i++){
        sol += Solution2(array[i].first.first,array[i].first.second,array[i].second.first,array[i].second.second);
    }

    std::cout << sol << "\n";

    return 0;
}