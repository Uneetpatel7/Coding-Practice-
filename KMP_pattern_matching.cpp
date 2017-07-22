#include <bits.stdc++.h>

void KMP(char *txt, char *pat){
	int size_pat = strlen(pat);
	int size_txt = strlen(txt);
	int lps[size_pat];
}

void pre_processed_array(char *pat, int *lps, int size_pat){
	lps[0] = 0;
	int i=0;
	int j=1;
	while (j<size_pat){
		if (pat[i] == pat[j]){
			i++;
			lps[j] = i;
			j++; 
		}
		else{
			if(!i){
				i=lps[i-1];
			}
			else{
				lps[j]=0;
				j++;
			}
		}
	}	
}




int main(){
	char *txt = "ABABDABACDABABCABAB";
    char *pat = "ABABCABAB";
	return 0;
}