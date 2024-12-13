#include <stdlib.h>
#include <string.h>
#include <math.h>

int num_length(int k){
  int length=0;
  while(k>0)
  {
    length++;
    k/=10;
    
  }
    return length;
  
  
}

int * turn_num_toarr(int k , int length){
  int *arr=(int*)malloc(sizeof(int)*length);
  if(arr!=NULL)
  {
  int i=1;
  while(k>0)
  {
    arr[length-i]=k%10;
    k/=10;
    i++;
    
  }
  return arr;
  }
  else return NULL;
  
  
}

unsigned char *encode(const char *s, unsigned k)
{
    int length = strlen(s),l= num_length(k);
    unsigned char *ret = (unsigned char *)malloc(sizeof(unsigned char) * (length + 1));
    int *arr =turn_num_toarr(k,l);
    
    
    if(arr!=NULL)
    {
    if (ret != NULL)
    {
        for (int i = 0; i <length; i++)
            ret[i] = s[i] - 'a' + 1 +arr[i%l];
        ret[length] = '\0'; 
        free(arr);
        return ret;
    }
    }
    free(arr);
        return NULL;
    
}
