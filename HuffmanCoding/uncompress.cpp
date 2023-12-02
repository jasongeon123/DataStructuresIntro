#include <queue>
#include <vector>
#include <fstream>
#include "Helper.hpp"
#include "HCTree.hpp"
int main(int argc, char* argv[]){
   char* input_file = argv[1];
   char* output_file = argv[2];
   FancyInputStream input (input_file);
   FancyOutputStream output (output_file);
   //int count_num = input.read_int();//number of bytes of file 
   //int count_char = input.read_int();//number of different letters in original file
   // if(count_num==0){
   //    return 0;
   // }
   if(input.filesize()<=0){
      return 0;
   }
   input.reset();
   vector<int> freqs(256,0);
   int count;
   for(long unsigned int i=0;i<freqs.size();i++){
      int ye = input.read_int();
      freqs[i] = ye;
      count = count + freqs[i];
   }
   // vector<char>place(count_char,0);
   // vector<int>height(count_char,0);
   // for(int i=0;i<count_char;i++){
   //    place[i]=input.read_byte();
   //    height[i] = input.read_byte();
   // }
   // for(int j=0;j<count_char;j++){
   //    cout<<place[j]<<endl;
   //    cout<<height[j]<<endl;
   // }
   HCTree huffman;
   huffman.build(freqs);
   //huffman.btraverse(place, height);

   for(int num =0;num<count;num++){
      char condi = huffman.decode(input);
      if(condi == -1){
         continue;
      }
      output.write_byte(condi);
   }

   output.flush();
   input.reset();
   return 0;
}









