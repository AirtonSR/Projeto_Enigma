#include <stdio.h>
#include <stdlib.h>

int calculate_persistence(long long number);

int main() {
	int options;
    int target_persistence;

	beginning:
	    for (target_persistence = 1; target_persistence <= 5; target_persistence++) {
	        long long number_persistence = 10;
	        int found = 0;
	
	        while (1) {
	            int persistence = calculate_persistence(number_persistence);
	
	            if (target_persistence == persistence) {
	                printf("A persistencia do numero %d eh: %lld\n\n", target_persistence, number_persistence);
	                found = 1;
	                break;
	            }
	
	            number_persistence++;
	        }
	
	        if (!found) {
	            printf("Nenhum numero com persistencia %d encontrado.\n", target_persistence);
	        }
	    }
	    
	middle:
		printf("Quer ver novamente? s - sim n - nao");
		options = toupper(getche());
		printf("\n\n\n");
		switch (options)
		{
			case 'S':
				goto beginning;
				break;
			case 'N':
				goto end;
				
			default:
				goto middle;
				break;
		}
		
	end:
		
    	return 0;
}

int calculate_persistence(long long number) {
    int persistence = 0;
    long long number_product;

    while (number >= 10) {
        number_product = 1;

        while (number > 0) {
            number_product *= number % 10;
            number /= 10;
        }

        number = number_product;
        persistence++;
    }

    return persistence;
}

