#include <stdio.h>
#include <string.h>

int palindromeparmutation(char s[]){
    //creating array which store frequency of character in letter
    int freq[26] = {0};
    for(int i=0;i<strlen(s);i++){
        freq[s[i]-'a'] = freq[s[i]-'a'] + 1;
    }

    //count odd number of freqency 
    int count = 0;
    for(int i=0;i<26;i++){
        if(freq[i]%2 == 1 ){
            count++;
        }
    }

    if(count <= 1){
        return 1;
    }
    return 0;
}

int main()
{
    char a[] = "mmaad";
    printf("%d",palindromeparmutation(a));

    // time complexity: O(n) where n is size of string
    // space complexity: O(1) it is constant as we need constant amount of space which is 26 element matrix to store frequency
}