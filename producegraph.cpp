/*
intput : file pointer
output : Graph
Graph a = new Graph() -> a.add_ve....
*/
#include <fstream>
#include <string>
#include <iostream>

//Graph producegraph(String file){
int main(){
  std::string file="testdata.net";
  std::string line;
  std::ifstream in(file);
  while(getline(in, line)){
    std::cout<<line<<std::endl;
  }

  //Graph data = new Graph();
  return 0;

}
