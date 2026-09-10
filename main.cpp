#include <iostream>
#include <cstdio>


int main(int argc, char** argv){
    if (argc != 2){
        std::cout << "Usage: " << argv[0] << "data.txt" << std::endl;
        return 1;
    }

    FILE* f = fopen(argv[1], "r");
    if (!f){
        std::cout << "Cannot read the file(" << std::endl;
        return 1;
    }


    int cur_char;
    int prev_char = fgetc(f);
    int ch;
    int mx = 0;
    int count = 0;

    while ((cur_char = fgetc(f)) != EOF){
        if (cur_char == prev_char){
            count ++;
            if (mx < count){
                count = mx;
                ch = cur_char;
            }

        }
        else{
            if (mx < count){
                count = mx;
                ch = cur_char;
            }
        }
        prev_char = cur_char;
    }
    std::cout << mx << " " << ch << std::endl;
    return 0;
}
