#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>


/* PARTE 1
    1) 10380 -> too low
    2) 10582 -> too low
    3) 11767 -> lesssgooo

    PARTE 2
    1) 13886 -> lessgoo
*/

int Controllo(std::vector<char> a, std::vector<char> b){
    int punteggio = 0;
    int rock = 1;
    int paper = 2;
    int scissor = 3;
    int win = 6;
    int draw = 3;

    for(int i = 0; i < a.size()-1; i++){
                //rock          Paper
        if(a[i] == 'A' && b[i] == 'Y'){
            punteggio += paper + win;
            //std::cout << punteggio << "\n";
        }
                //rock          Rock
        if(a[i] == 'A' && b[i] == 'X'){
            punteggio += rock + draw;
        }
                //rock          Scissors
        if(a[i] == 'A' && b[i] == 'Z'){
            punteggio += scissor;
        }

                //paper         Paper
        if(a[i] == 'B' && b[i] == 'Y'){
            punteggio += paper + draw;
        }
                //paper         Rock
        if(a[i] == 'B' && b[i] == 'X'){
            punteggio += rock;
            //std::cout << punteggio << "\n";
        }
                //paper         Scissors
        if(a[i] == 'B' && b[i] == 'Z'){
            punteggio += scissor + win;
        }
        
                //scissor       Paper
        if(a[i] == 'C' && b[i] == 'Y'){
            punteggio += paper;
        }
                //scissor       Rock
        if(a[i] == 'C' && b[i] == 'X'){
            punteggio += rock + win;
        }
                //scissor       Scissors
        if(a[i] == 'C' && b[i] == 'Z'){
            punteggio += scissor + draw;
            //std::cout << punteggio << "\n";
        }
    }

    return punteggio;
}

int SecondaParte(std::vector<char> a, std::vector<char> b){
    int result = 0;
    int rock = 1;
    int paper = 2;
    int scissor = 3;
    int win = 6;
    int draw = 3;


    for(int i = 0; i < a.size()-1; i++){
                //rock           draw  
        if(a[i] == 'A' && b[i] == 'Y'){
            result += draw + rock;
            //std::cout << result << "\n";
        }
                //Rock            lose
        if(a[i] == 'A' && b[i] == 'X'){
            result += scissor;
        }
                //Rock            win
        if(a[i] == 'A' && b[i] == 'Z'){
            result += win + paper;
        }

                //Paper           draw
        if(a[i] == 'B' && b[i] == 'Y'){
            result += draw + paper;
        }
                //Paper           lose
        if(a[i] == 'B' && b[i] == 'X'){
            result += rock;
            //std::cout << result << "\n";
        }
                //Paper           win
        if(a[i] == 'B' && b[i] == 'Z'){
            result += win + scissor;
        }
        
                //Scissors        draw
        if(a[i] == 'C' && b[i] == 'Y'){
            result += draw + scissor;
        }
                //Scissors         lose
        if(a[i] == 'C' && b[i] == 'X'){
            result += paper;
        }
                //Scissors        win
        if(a[i] == 'C' && b[i] == 'Z'){
            result += win + rock;
            //std::cout << result << "\n";
        }
    }
    return result;
}


void ReadFromFile(char *filename){
    std::string a = "";
    std::ifstream ifs(filename, std::ios::in );
    std::vector<char> array1;
    std::vector<char> array2;
    

    ifs.seekg(0, std::ios::beg);

    if(ifs.is_open()){
        while ( ifs ){
            std::getline(ifs, a); //così itero sulle linee intere fino al delimitatore di default che e' \n ifs.get() -> restituisce carattere per carattere invece
            //std::cout << a << "\n";
            
            array1.push_back(a[0]);
            
            array2.push_back(a[2]);
        }
    }else{
        std::cout << "impossibile aprire il file\n";
    }
    //std::cout << "\n" << array.size() << "\n";
    ifs.close();

    std::cout << Controllo(array1, array2) << "\n";
    std::cout << SecondaParte(array1, array2) << "\n";
    //std::cout << array1.size() << " " << array2.size() << "\n";
    
}

int main(int argc, char **argv){

    if(argc < 1){
        std::cout << "errore nel passaggio dei file\n";
        return 0;
    }

    ReadFromFile(argv[1]);

    return 0;
}