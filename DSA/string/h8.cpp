/*Burrows – Wheeler Data Transform Algorithm
Difficulty Level : Medium
Last Updated : 08 Aug, 2019
What is the Burrows-Wheeler Transform?
The BWT is a data transformation algorithm that restructures data in such a way that the transformed message is more compressible. Technically, it is a lexicographical reversible permutation of the characters of a string. It is first of the three steps to be performed in succession while implementing the Burrows-Wheeler Data Compression algorithm that forms the basis of the Unix compression utility bzip2.

Why BWT? The main idea behind it.
The most important application of BWT is found in biological sciences where genomes(long strings written in A, C, T, G alphabets) don’t have many runs but they do have many repeats.
The idea of the BWT is to build an array whose rows are all cyclic shifts of the input string in dictionary order and return the last column of the array that tends to have long runs of identical characters. The benefit of this is that once the characters have been clustered together, they effectively have an ordering, which can make our string more compressible for other algorithms like run-length encoding and Huffman Coding.
The remarkable thing about BWT is that this particular transform is reversible with minimal data overhead.

Steps involved in BWT algorithm
Let’s take the word “banana$” as an example.

Step 1: Form all cyclic rotations of the given text.
                                     banana$ 
       $    b                        $banana 
    a           a                    a$banan
   Cyclic rotations    ---------->   na$bana
    n         n                      ana$ban 
          a                          nana$ba
                                     anana$b
Step 2: The next step is to sort the rotations lexicographically. The ‘$’ sign is viewed as first letter lexicographically, even before ‘a’.
banana$                    $banana
$banana                    a$banan
a$banan       Sorting      ana$ban
na$bana      ---------->   anana$b 
ana$ban    alphabetically  banana$
nana$ba                    na$bana
anana$b                    nana$ba
Step 3: The last column is what we output as BWT.
BWT(banana$) = annb$aa
Examples:

Input: text = “banana$”
Output: Burrows-Wheeler Transform = “annb$aa”



Input: text = “abracadabra$”
Output: Burrows-Wheeler Transform = “ard$rcaaaabb”

Why last column is considered BWT?

The last column has a better symbol clustering than any other columns.
If we only have BWT of our string, we can recover the rest of the cyclic rotations entirely. The rest of the columns don’t possess this characteristic which is highly important while computing the inverse of BWT.
Why ‘$’ sign is embedded in the text?
We can compute BWT even if our text is not concatenated with any EOF character (‘$’ here). The implication of ‘$’ sign comes while computing the inverse of BWT.

Way of implementation

Let’s instantiate “banana$” as our input_text and instantiate character array bwt_arr for our output.
Let’s get all the suffixes of “banana$” and compute it’s suffix_arr to store index of each suffix.
0 banana$                6 $   
1 anana$                 5 a$
2 nana$      Sorting     3 ana$
3 ana$     ---------->   1 anana$
4 na$     alphabetically 0 banana$
5 a$                     4 na$
6 $                      2 nana$
Iterating over the suffix_arr, let’s now add to our output array bwt_arr, the last character of each rotation.
The last character of each rotation of input_text starting at the position denoted by the current value in the suffix array can be calculated with input_text[(suffix_arr[i] – 1 + n ) % n], where n is the number of elements in the suffix_arr.
bwt_arr[0] 
  = input_text[(suffix_arr[0] - 1 + 7) % 7] 
  = input_text[5] 
  = a
bwt_arr[1] 
  = input_text[(suffix_arr[1] - 1 + 7) % 7] 
  = input_text[4] 
  = n */
#include <bits/stdc++.h>
using namespace std;

// to store therotation
struct rotation{
    int index;
    char *suffix;
};

int cmpfunc(const void *x, const void *y)
{
    rotation *rx=(rotation*)x;
    rotation *ry=(rotation*)y;

    return strcmp(rx->suffix,ry->suffix);
}

int *computeSuffix(char *inp, int len){
    rotation suff[len];
    for(int i=0;i<len;i++)
    {
        suff[i].index=i;
        suff[i].suffix=(inp+i);
    }
    qsort(suff,len,sizeof(rotation),cmpfunc);

    int *suffarr=(int*)malloc(len*sizeof(int));
    for(int i=0;i<len;i++)
        suffarr[i]=suff[i].index;
    
    return suffarr;
}

char *findLastChar(char *inp, int *suffixarr,int n)
{
    char *arr=new char[n];
    int i;
    for(i=0;i<n;i++){
        int j=suffixarr[i]-1;
        if(j<0)
            j=j+n;
        arr[i]=inp[j];
    }
    arr[i]='\0';
    return arr;
}

int main(){
    char input[]="banana$";
    int len=strlen(input);
    // compute the suffix array
    int *suffixArr=computeSuffix(input,len);
    // add it to the output array the last chaar of each rotation
    char *bwtArr=findLastChar(input, suffixArr,len);

    cout<<"input text: "<<input<<endl;
    cout<<"burrows-wheeler transform: "<<bwtArr<<endl;
}