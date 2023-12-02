#include <queue>
#include <vector>
#include <fstream>
#include "Helper.hpp"
#include "HCTree.hpp"
#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
   char* input_file = argv[1];
   char* output_file = argv[2];
   int byte_count=0;
   // int diff_byte =0;
   FancyInputStream input (input_file);
   FancyOutputStream output (output_file);
   vector<int> freqs(256,0);
   if(input.filesize()<=0){
      return 0;
   }
   while(true){
      int cond = input.read_byte();
      if(cond==-1){
         break;
      }

      freqs[cond]++;
      byte_count++;
   }
   // int j=0;
   // while(j<256){
   //    if(freqs[j]!=0){
   //       diff_byte++;
   //    }
   //    j++;
   // }
   HCTree huffman;
   huffman.build(freqs);

   for(long unsigned int p=0;p<freqs.size();p++){
      output.write_int(freqs[p]);
   }
   // output.write_int(byte_count);
   // output.write_int(diff_byte);
   // huffman.traverse(huffman.getRoot(),output,0);
   input.reset();
   for(int num =0;num<byte_count;num++){
      int condi = input.read_byte();

      huffman.encode(condi,output);
      
   }
   input.reset();
   output.flush();
   return 0;
}