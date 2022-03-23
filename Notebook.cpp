#include <iostream>
#include "Notebook.hpp"
#include "Direction.hpp"
#include <string>
#include <algorithm>
#include <map>
#include <stdexcept>
#define ROW_LENGTH 100

using namespace ariel;
namespace ariel{
    Notebook::Notebook() {}

    void Notebook::write(int page,int row,int col,Direction d,std::string text){
//        if (page<0 || row<0 || col<0){
//            throw  std::invalid_argument("Page,Row,Column MUST be an unsigned integer (above 0)");
//        }
//        if (col >= 100 || text.length() + col > 100){
//            throw  std::invalid_argument("Trying to write over 100 characters");
//        }
//        int stringLen = text.length();
//        if(d == Direction::Horizontal){
//            pair<int, int> pair = make_pair(page,row);
//            if (notebook[pair] == ""){
//                notebook[pair] = newLine();
//            }
//            else{
//                for (int i = col; i < col+stringLen; ++i) {
//                    if (notebook[pair][i] != "_"){
//                        throw  std::invalid_argument("Trying to overwrite an existing character");
//                    }
//                }
//            }
//        }
//        else{
//            for (int i = row; i < row+stringLen; ++i) {
//                pair<int, int> pair = make_pair(page,row);
//                if(notebook[pair] == ""){
//                    notebook[pair] = newLine();
//                }
//                else{
//                    if(notebook[pair][col] != "_"){
//                        throw  std::invalid_argument("Trying to overwrite an existing character");
//                    }
//                }
//            }
//        }
//        if(d == Direction::Horizontal){
//            pair<int, int> pair = make_pair(page,row);
//            for (int i = 0; i < stringLen; ++i) {
//                notebook[pair][col+i] = text[i];
//            }
//        }
//        else{
//            for (int i = 0; i < stringLen; ++i) {
//                pair<int, int> pair = make_pair(page,row+i);
//                notebook[pair][col] = text[i];
//            }
//        }
    }
    std::string Notebook::read(int page,int row,int col,Direction d,int readSize){
        return "Hi";
    }
    void Notebook::erase(int page,int row,int col,Direction d,int eraseSize){

    }
    std::string Notebook::show(int page){
        return "Hi";
    }
    std::string newLine(){
        std::string ans = "";
        for(int i=0;i<ROW_LENGTH;i++){
            ans += "_";
        }
        return ans;
    }
}

