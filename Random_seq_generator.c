#include <stdio.h>
#include <stdlib.h>

int printRandoms(int lower, int upper) 
{   	 
  int rn;      
  
  rn = (rand() % (upper - lower + 1)) + lower; 
  
  //~ n = (rand() % (upper + 1 - lower)) + lower; 
  
  //~ n = lower + rand() / (RAND_MAX/(upper - lower + 2) + 1);
  
  /*
   (Note, by the way, that RAND_MAX is a constant telling you what the fixed range of the C library rand function is. You cannot set RAND_MAX to some other value, and there is no way of requesting that rand return numbers in some other range.) 
  */
  // floating point (int)((double)rand() / ((double)RAND_MAX + 1) * N)
   
  
  //~ printf("N = %d\n",n);  
  
  return rn;
  
}


char * getRandomDNA(int n)
{

	int lower = 0, upper = 3; 
	int i,num;    
    char DNAT[] = {'A','T','G','C'}; 
	
	
	char * DNASEQ;
	DNASEQ = malloc (sizeof (char) * 2);
	
	for (i = 0; i < n; i++) 
	{ 	
		num = printRandoms(lower, upper);		
		//~ printf("N = %d\n",num);  				
		//~ *(DNASEQ + i) = DNAT[num];		
		DNASEQ[i] = DNAT[num];		
	}
	
	DNASEQ[n] = '\0';
	
	//~ printf("DNA %s \n",DNASEQ);	
		
	return DNASEQ;	
}

char * getRandomProtein(int m)
{

	int lower = 0, upper = 19; 
	int i,num;        
    char ProT[] = {'G','A','L','M','F','W','K','Q','E','S','P','V','I','C','Y','H','R','N','D','T'}; 
	
	char * PROSEQ;
	PROSEQ = malloc (sizeof (char) * 2);
	
	for (i = 0; i < m; i++) 
	{ 	
		num = printRandoms(lower, upper);		
		//~ printf("N = %d\n",num);  				
		//~ *(PROSEQ + i) = ProT[num];		
		PROSEQ[i] = ProT[num];		
	}
	
	PROSEQ[m] = '\0';
	
	//~ printf("Protein Sequence %s \n",PROSEQ);	
		
	return PROSEQ;	
}



 
int main() { 
    
    int n,m;
    printf("Enter the DNA lenght: ");
    scanf("%d",&n);
        
    printf("Enter the Protein lenght: ");
    scanf("%d",&m);
        
    
    char * DNA;
    char * Protein;
    
    DNA = malloc (sizeof (char) * 2);
    DNA = getRandomDNA(n);
    printf("DNA    : %s \n\n", DNA );    
    
    Protein = malloc (sizeof (char) * 2);
    Protein = getRandomProtein(m);
    printf("Protein: %s \n\n", Protein );    
    
    return 0; 
} 






