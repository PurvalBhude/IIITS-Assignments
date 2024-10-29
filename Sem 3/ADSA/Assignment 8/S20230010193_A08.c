/*
* Name: Purval Madhukar Bhude
* Roll No. S20230010193
* Assignment 8 ADSA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Question 1
#define ALPHABET_SIZE 128
#define MAX_NAMES 100

// Trie node structure
typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE]; 
    int is_end_of_name; // Flag for end of name
} TrieNode;

// Trie structure
typedef struct Trie {
    TrieNode *root; // Root of the Trie
} Trie;

// Create a new Trie node
TrieNode* create_node() {
    TrieNode *new_node = (TrieNode *)malloc(sizeof(TrieNode));
    new_node->is_end_of_name = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        new_node->children[i] = NULL; // Initialize children to NULL
    }
    return new_node;
}

// Create a new Trie
Trie* create_trie() {
    Trie *trie = (Trie *)malloc(sizeof(Trie));
    trie->root = create_node(); // Set root node
    return trie;
}

// Insert a name into the Trie
void insert_name(Trie *trie, const char *name) {
    TrieNode *current = trie->root;
    for (int i = 0; name[i] != '\0'; i++) {
        char ch = tolower(name[i]); // Convert to lowercase
        if (current->children[ch] == NULL) {
            current->children[ch] = create_node(); // Create new node if not exist
        }
        current = current->children[ch];
    }
    current->is_end_of_name = 1; // Mark end of name
}

// Collect names matching the prefix
void collect_names(TrieNode *node, char *prefix, char **suggestions, int *count) {
    if (node->is_end_of_name) {
        suggestions[(*count)++] = strdup(prefix); // Store found name
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != NULL) {
            char next_char = (char)i;
            size_t len = strlen(prefix);
            prefix[len] = next_char; // Append character to prefix
            prefix[len + 1] = '\0'; 
            collect_names(node->children[i], prefix, suggestions, count); // Recursive call
            prefix[len] = '\0'; // Backtrack
        }
    }
}

// Generate name suggestions based on prefix
char** Name_suggestions(Trie *trie, const char *prefix, int *num_suggestions) {
    TrieNode *current = trie->root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        char ch = tolower(prefix[i]); 
        if (current->children[ch] == NULL) {
            *num_suggestions = 0;
            return NULL; // No suggestions
        }
        current = current->children[ch];
    }

    char **suggestions = (char **)malloc(MAX_NAMES * sizeof(char *));
    char current_prefix[100];
    strcpy(current_prefix, prefix); // Copy prefix
    int count = 0;
    collect_names(current, current_prefix, suggestions, &count); // Collect suggestions
    *num_suggestions = count;
    
    // Sort suggestions
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(suggestions[i], suggestions[j]) > 0) {
                char *temp = suggestions[i];
                suggestions[i] = suggestions[j];
                suggestions[j] = temp;
            }
        }
    }
    return suggestions; // Return sorted suggestions
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;      
    *b = temp;  
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// Question 2
// Check if two arrays have the same set of numbers
void equalset(int *arr1, int *arr2, int n1, int n2) {
    int hash1[1000] = {0};
    int hash2[1000] = {0}; 
    for (int i = 0; i < n1; i++) {
        hash1[arr1[i]]++; // Count elements in first array
    }
    for (int i = 0; i < n2; i++) {
        hash2[arr2[i]]++; // Count elements in second array
    }
    for (int i = 0; i < 1000; i++) {
        if (hash1[i] != hash2[i]) {
            printf("The two arrays do not have the same set of numbers.\n");
            return; // Arrays are different
        }
    }
    printf("The two arrays have the same set of numbers.\n"); // Arrays are equal
}

int main() {
    int choice;
    printf("Select the question you want to run\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            // Question 1:
            Trie *trie = create_trie();
            char *names[] = {"Raju", "Sita", "Ramu", "Ravindar", "Siva", "RAVI"};
            int name_count = sizeof(names) / sizeof(names[0]);
            for (int i = 0; i < name_count; i++) {
                insert_name(trie, names[i]);
            }
            char prefix[100];
            printf("Enter a prefix for suggestions: ");
            scanf(" %[^\n]%*c", prefix);
            int num_suggestions;
            char **suggestions = Name_suggestions(trie, prefix, &num_suggestions);
            if (suggestions != NULL) {
                printf("Suggestions for '%s':\n", prefix);
                for (int i = 0; i < num_suggestions; i++) {
                    printf("%s\n", suggestions[i]);
                    free(suggestions[i]);
                }
                free(suggestions);
            } else {
                printf("No suggestions found for '%s'.\n", prefix);
            }
            break;
        }
        case 2: {
            // Question 2
            printf("Enter the size of array1: ");
            int n1;
            scanf("%d", &n1);
            int arr1[n1];
            printf("Enter values in array1: ");
            for (int i = 0; i < n1; i++) {
                scanf("%d", &arr1[i]);
            }
            printf("Enter the size of array2: ");
            int n2;
            scanf("%d", &n2);
            int arr2[n2];
            printf("Enter values in array2: ");
            for (int i = 0; i < n2; i++) {
                scanf("%d", &arr2[i]);
            }
            equalset(arr1, arr2, n1, n2);
            break;
        }
        default:
            printf("Invalid choice. Please select either 1 or 2.\n");
            break;
    }
    
    return 0;
}
