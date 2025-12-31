#include "variable_length_quantity.h"
int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
   if(integers==NULL || output==NULL) return -1;
   int out_idx=0;
   for(size_t i=0; i<integers_len; i++){
      uint32_t nbr=integers[i];
      uint8_t chunks[5];//maximum of 5 7-bit bytes in 32-bit int (32/7=4.57)
      uint8_t count=0;
      do{//break 32-bit int into seperate bytes
         chunks[count]=nbr & 0x7f;
         nbr= nbr>>7;
         count++;
      }while (nbr>0);
      

      for(int j=count - 1; j>=0; j--){//reverse and add continuation bit
         if(j>0) output[out_idx]= chunks[j] | 0x80;
         else output[out_idx]=chunks[j];
         out_idx++;
      }  
   }
   return out_idx;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
   if(bytes == NULL || output == NULL) return -1;
   int out_idx=0;
   uint32_t decoded=0;
   for(size_t i=0; i<buffer_len; i++){
      decoded=decoded | (bytes[i] & 0x7f);
      if(bytes[i] >> 7 == 0){//write decoded value to output if current byte is the last byte
         output[out_idx++]=decoded;
         decoded=0;//reset decoded to hold the next decoded VLQ
         continue;
      }
      if(i+1>=buffer_len) return -1;//current VLQ byte is the last VLQ byte, but it isn't marked as so.
      decoded<<=7;
   }
   return out_idx;
}