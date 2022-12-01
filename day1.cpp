#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>


/* PARTE 1
    1) 90277 -> too high
    2) 70613 -> giusto

    PARTE 2
    1) 205805 -> giust (GG in un tentativo)
*/

std::vector<int> ReadFromFile(char *filename){
    std::string a = "";
    std::ifstream ifs(filename, std::ios::in );
    std::vector<int> array;

    ifs.seekg(0, std::ios::beg);

    if(ifs.is_open()){
        while ( ifs ){
            std::getline(ifs, a); //così itero sulle linee intere fino al delimitatore di default che e' \n ifs.get() -> restituisce carattere per carattere invece
            //std::cout << a << "\n";
            if(a.size() > 2 ){
                //std::cout << a << "\n";
                array.push_back(std::stoi(a)); //inserisco in un array senza dimensione iniziale che cresce mano a mano
            }else{
                array.push_back(-1);
            }
        }
    }else{
        std::cout << "impossibile aprire il file\n";
    }
    //std::cout << "\n" << array.size() << "\n";
    ifs.close();

    return array;
}

int main(int argc, char **argv){

    if(argc < 1){
        std::cout << "errore nel passaggio dei file\n";
        return 0;
    }

    std::vector<int> result = ReadFromFile(argv[1]);

    //std::cout << result.size();

    std::vector<int> res;
    int a = 0;

    for(int i = 0; i < result.size(); i++){
        if(result[i] != (-1)){
            a += result[i];
        }else{
            res.push_back(a);
            a = 0;
        }
    }
    
    int max = 0;

    max = res[0];

    for(int i = 0; i < res.size(); i++){
        if(res[i] > max){
            max = res[i];
        }
    }

    std::cout << max << "\n";


    std::sort(res.begin(), res.end());

    std::reverse(res.begin(), res.end());

    int final_res = res[0] + res[1] + res[2];

    std::cout << final_res << "\n";
    
    return 0;
}