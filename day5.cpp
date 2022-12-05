#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

/* PARTE 1
    1) TLNGFGMFN -> giusto al primo tentativo

    PARTE 2
    1) FGLQJCMBD -> first dendadivo GGEZ
*/

void Solve1(int hm, int fr, int to, std::vector<std::vector<char>> &a){ // devo  passare il vettore per riferimento

    char c;

    for(int i = 0; i < hm; i++){
        c = a[fr].back();
        //std::cout << c << " ";
        a[fr].pop_back();
        a[to].push_back(c);
    }
    //std::cout << "\n";
}

void Solve2(int hm, int fr, int to, std::vector<std::vector<char>> &a){
    std::vector<char> save;
    char c;

    for(int i = 0; i < hm; i++){
        c = a[fr].back();
        save.push_back(c);
        a[fr].pop_back();
    }

    std::reverse(save.begin(), save.end());

    for(int i = 0; i < save.size(); i++){
        a[to].push_back(save[i]);
    }

}


void ReadFromFile(char *filename){
    std::string a = "";
    std::ifstream ifs(filename, std::ios::in );
    
    std::vector<char> arr1;
    std::vector<char> arr2;
    std::vector<char> arr3;
    std::vector<char> arr4;
    std::vector<char> arr5;
    std::vector<char> arr6;
    std::vector<char> arr7;
    std::vector<char> arr8;
    std::vector<char> arr9;

    ifs.seekg(0, std::ios::beg);

    std::getline(ifs, a, ']');
    arr4.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr5.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr6.push_back(a[a.size() - 1]);

    std::getline(ifs, a);

    std::getline(ifs, a, ']');
    arr3.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr4.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr5.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr6.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr7.push_back(a[a.size() - 1]);

    std::getline(ifs, a);

    std::getline(ifs, a, ']');
    arr1.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr3.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr4.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr5.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr6.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr7.push_back(a[a.size() - 1]);

    std::getline(ifs, a);

    std::getline(ifs, a, ']');
    arr1.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr3.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr4.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr5.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr6.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr7.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr8.push_back(a[a.size() - 1]);

    std::getline(ifs, a);

    std::getline(ifs, a, ']');
    arr1.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr3.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr4.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr5.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr6.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr7.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr8.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr9.push_back(a[a.size() - 1]);

    std::getline(ifs, a);

    std::getline(ifs, a, ']');
    arr1.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr2.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr3.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr4.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr5.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr6.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr7.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr8.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr9.push_back(a[a.size() - 1]);

    std::getline(ifs, a);

    std::getline(ifs, a, ']');
    arr1.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr2.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr3.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr4.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr5.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr6.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr7.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr8.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr9.push_back(a[a.size() - 1]);

    std::getline(ifs, a);

    std::getline(ifs, a, ']');
    arr1.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr2.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr3.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr4.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr5.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr6.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr7.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr8.push_back(a[a.size() - 1]);
    std::getline(ifs, a, ']');
    arr9.push_back(a[a.size() - 1]);

    std::getline(ifs, a);
    std::getline(ifs, a);

    std::vector<std::vector<char>> res(9);

    //std::cout << "\n";
    //std::cout << "1 ";
    for(int i = 0; i <= arr1.size(); i++){
        //std::cout << arr1[i] << " ";
        res[0].push_back(arr1[i]);
    }
    //std::cout << "\n";
    //std::cout << "2 ";
    for(int i = 0; i <= arr2.size(); i++){
        //std::cout << arr2[i] << " ";
        res[1].push_back(arr2[i]);
    }
    //std::cout << "\n";
    //std::cout << "3 ";
    for(int i = 0; i <= arr3.size(); i++){
        //std::cout << arr3[i] << " ";
        res[2].push_back(arr3[i]);
    }
    //std::cout << "\n";
    //std::cout << "4 ";
    for(int i = 0; i <= arr4.size(); i++){
        //std::cout << arr4[i] << " ";
        res[3].push_back(arr4[i]);
    }
    //std::cout << "\n";
    //std::cout << "5 ";
    for(int i = 0; i <= arr5.size(); i++){
        //std::cout << arr5[i] << " ";
        res[4].push_back(arr5[i]);
    }
    //std::cout << "\n";
    //std::cout << "6 ";
    for(int i = 0; i <= arr6.size(); i++){
        //std::cout << arr6[i] << " ";
        res[5].push_back(arr6[i]);
    }
    //std::cout << "\n";
    //std::cout << "7 ";
    for(int i = 0; i <= arr7.size(); i++){
        //std::cout << arr7[i] << " ";
        res[6].push_back(arr7[i]);
    }
    //std::cout << "\n";
    //std::cout << "8 ";
    for(int i = 0; i <= arr8.size(); i++){
        //std::cout << arr8[i] << " ";
        res[7].push_back(arr8[i]);
    }
    //std::cout << "\n";
    //std::cout << "9 ";
    for(int i = 0; i <= arr9.size(); i++){
        //std::cout << arr9[i] << " ";
        res[8].push_back(arr9[i]);
    }


    for(int i = 0; i < 9; i++){
        std::cout << i + 1 << " ";
        for(int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
    int howmuch = 0;
    int from = 0;
    int to = 0;
    
    for(int i = 0; i < 9; i++){
        
        std::reverse(res[i].begin(), res[i].end());
        
    }

    std::cout << "\n";

    for(int i = 0; i < 9; i++){
        std::cout << i + 1 << " ";
        for(int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }

    if(ifs.is_open()){
        while ( ifs ){
            std::getline(ifs, a, ' '); //così itero sulle linee intere fino al delimitatore di default che e' \n ifs.get() -> restituisce carattere per carattere invece
            std::getline(ifs, a, ' ');
            //std::cout << a << " ";
            howmuch = std::stoi(a);
            std::getline(ifs, a, ' ');
            std::getline(ifs, a, ' ');
            //std::cout << a << " ";
            from = std::stoi(a);
            std::getline(ifs, a, ' ');
            std::getline(ifs, a);
            //std::cout << a << "\n";
            to = std::stoi(a);
            //array.push_back(std::stoi(a)); //inserisco in un array senza dimensione iniziale che cresce mano a mano
            //Solve1(howmuch, from-1, to-1, res);
            Solve2(howmuch, from-1, to-1, res);
        }
    }else{
        std::cout << "impossibile aprire il file\n";
    }
    
    //std::cout << "\n" << array.size() << "\n";
    ifs.close();

    std::cout << "\n";

    for(int i = 0; i < 9; i++){
        std::cout << i + 1 << " ";
        for(int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }
    
}

int main(int argc, char **argv){

    if(argc < 1){
        std::cout << "errore nel passaggio dei file\n";
        return 0;
    }

    std::vector<int> a;

    ReadFromFile(argv[1]);


    return 0;
}