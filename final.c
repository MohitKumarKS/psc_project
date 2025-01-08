#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 256

// Function to encode the spaces with '+'
void new_url(char *url);

int main() {
    char query[MAX_QUERY_LENGTH];  
    char url[MAX_QUERY_LENGTH];    
    int choice;                        

    // OS selection
    printf("1. Windows\n2. MAC\n3. Linux\nChoose your OS: ");
    scanf("%d", &choice);
    // input their search query
    printf("Enter your search query: ");
    fgets(query, sizeof(query), stdin);
  	
	// Calling the function to replace spaces with '+'
   	new_url(query);
   	
	// Google search URL using the query
  	printf(url, "https://www.google.com/search?q=%s", query);
   	
	// Condition based on OS selection
   	if (choice == 1) {
    	// For Windows
       	printf("start %s", url);
    } else if (choice == 2) {
        // For MAC OS
        printf("open %s", url);
    } else if (choice == 3) {
        // For Linux OS
        printf("xdg-open %s", url);
    } else {
        // Invalid OS choice
        printf("INVALID OPTION\n");
    }

    // store the query in a file called history.txt
    FILE *history = fopen("history.txt", "a");  // open text file in append mode
    if (history == NULL) {
       	printf("Error opening the history file.\n");
    }
    fprintf(history, "%s\n", query);  // writing the query to the file
    fclose(history);  // close the file
    
	printf("Search completed. Press Enter to exit...\n");
    return 0;
}

// Function to replace spaces in the query with '+' 
void new_url(char *url) {
    char encoded[MAX_QUERY_LENGTH * 3];  // temporary array
    int j = 0;
    for (int i = 0; url[i] != '\0'; i++) {
        if (url[i] == ' ') {
            encoded[j++] = '+';  // replace space with '+'
        } else {
            encoded[j++] = url[i];
        }
    }
    encoded[j] = '\0';  
    // copy the encoded string back to the original url variable
    strcpy(url, encoded);
}
