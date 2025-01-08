#include <stdio.h>
#include <stdlib.h>
int rows ;
int columns ;

int get_string_length(char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

void create_array(char ***matrix)
{
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        matrix[rowIndex] = (char **)malloc(columns * sizeof(char *));
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            matrix[rowIndex][columnIndex] = (char *)malloc(50 * sizeof(char));
        }
    }
}

void get_array_input(char ***matrix)
{
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            scanf("%s", matrix[rowIndex][columnIndex]);
        }
    }
}

void display_array(char ***matrix)
{
    printf("The 2D array of names is:\n");
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            printf("%s ", matrix[row][col]);
        }
        printf("\n");
    }
}

int checkIsVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
        return 1;
    }
    return 0;
}

int startingWithvowelAndLongestWord(char ***matrix, int *longest_word_row_index, int *longest_word_column_index)
{
    int maximum_length = 0;
    int vowels = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
                if ((checkIsVowel(matrix[row][col][0])))
                {
                    vowels++;
                }
                int length = get_string_length(matrix[row][col]);
                if (length > maximum_length)
                {
                    maximum_length = length;
                    *longest_word_row_index = row;
                    *longest_word_column_index= col;
                }  
        }
    }
    return vowels;
}

void print_output(char ***matrix,int longest_word_row_index,int longest_word_column_index)
{
    int count = startingWithvowelAndLongestWord(matrix, &longest_word_row_index, &longest_word_column_index);
    printf("Number of names starting with a vowel:%d\n", count);
    printf("The longest name:%s\n", matrix[longest_word_row_index][longest_word_column_index]);
}
int main()
{
    printf("Enter Rows\n");
    scanf("%d", &rows);
    
    printf("Enter Columns:\n");
    scanf("%d",&columns);
    
   char ***matrix = (char ***)malloc(rows * sizeof(char **));

    create_array(matrix);

    get_array_input(matrix);

    display_array(matrix);

    int longest_word_row_index = 0, longest_word_column_index = 0;

    print_output(matrix,longest_word_row_index,longest_word_column_index);

    return 0;
}