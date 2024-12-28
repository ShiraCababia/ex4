/******************
Name: Shira Cababia
ID:
Assignment: EX4
*******************/
#include <stdio.h>
#include <string.h>

#define LEVEL_OF_PYRAMID 5
#define BOARD_DIMENSIONS 20

void task1RobotPaths(); // 1
int robotPath(int upCoordinate, int rightCoordinate);
void task2HumanPyramid(); // 2
void initializeChrldrsArr(float cheerleadersWeights[LEVEL_OF_PYRAMID][LEVEL_OF_PYRAMID]);
float weightsPyramid(int row, int cloumn, float cheerleadersWeights[LEVEL_OF_PYRAMID][LEVEL_OF_PYRAMID]);
void task3ParenthesisValidator(); // 3
int isBalanced(char closerChar, int flag);
char getCloserChar(char c);
void clearBuffer(char c);
void task4QueensBattle(); // 4
void initializeBoardArr(char boardArr[BOARD_DIMENSIONS][BOARD_DIMENSIONS], int row, int column, int boardDim);
int isSolutionForBoard(char solvedBoard[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
                       char board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], int row, int column, int boardDim);
int checkIfLocationPossible(char solvedBoard[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
                            char board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], int row, int column, int boardDim);
int isQueenInRow(char solvedBoard[BOARD_DIMENSIONS][BOARD_DIMENSIONS], int row, int column, int boardDim);
int isQueenInColumn(char solvedBoard[BOARD_DIMENSIONS][BOARD_DIMENSIONS], int row, int column, int boardDim);
int isQueenInCloseDiagonal(char solvedBoard[BOARD_DIMENSIONS][BOARD_DIMENSIONS], int row, int column, int boardDim);
int isQueenInArea(char solvedBoard[BOARD_DIMENSIONS][BOARD_DIMENSIONS], char board[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
                  char area, int row, int column, int boardDim);
void task5CrosswordGenerator(); // 5


int main()
{
    int task = -1;
    do
    {
        printf("Choose an option:\n"
               "1. Robot Paths\n"
               "2. The Human Pyramid\n"
               "3. Parenthesis Validation\n"
               "4. Queens Battle\n"
               "5. Crossword Generator\n"
               "6. Exit\n");

        if (scanf("%d", &task))
        {
            switch (task)
            {
            case 6:
                printf("Goodbye!\n");
                break;
            case 1:
                task1RobotPaths();
                break;
            case 2:
                task2HumanPyramid();
                break;
            case 3:
                task3ParenthesisValidator();
                break;
            case 4:
                task4QueensBattle();
                break;
            case 5:
                task5CrosswordGenerator();
                break;
            default:
                printf("Please choose a task number from the list.\n");
                break;
            }
        }
        else
        {
            scanf("%*s");
        }

    } while (task != 6);
}

/* Case 1 :
The func gets the coordinates from the user, use the recursive function "robotPath" and print the number of paths. */
void task1RobotPaths()
{
    int upCoordinate, rightCoordinate, numPaths;
    printf("Please enter the coordinates of the robot (column, row):\n");
    scanf(" %d %d", &upCoordinate, &rightCoordinate);
    numPaths = robotPath(upCoordinate, rightCoordinate);
    printf("The total number of paths the robot can take to reach home is: %d\n", numPaths);
}

/* The func goes through all the possible options of movements from the given coordinate to (0,0) and eventually
returns the number of possible paths to reach it. */
int robotPath(int upCoordinate, int rightCoordinate)
{
    if (upCoordinate == 0 && rightCoordinate == 0)
    {
        return 1;
    }
    else if (upCoordinate < 0 || rightCoordinate < 0)
    {
        return 0;
    }
    return (robotPath((upCoordinate - 1), rightCoordinate) + robotPath(upCoordinate, (rightCoordinate - 1)));
}

/* Case 2 :
The func initialize the cheerleaders' weights array to invalid weight (-1), gets the weights from the user,
use the recursive function "weightsPyramid" and print the total weight for every cheerleader.*/
void task2HumanPyramid()
{
    float cheerleadersWeights[LEVEL_OF_PYRAMID][LEVEL_OF_PYRAMID];
    initializeChrldrsArr(cheerleadersWeights);
    printf("Please enter the weights of the cheerleaders:\n");
    for (int i = 0; i < LEVEL_OF_PYRAMID; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            float weight;
            scanf(" %f", &weight);
            if (weight < 0)
            {
                printf("Negative weights are not supported.\n");
                return;
            }
            cheerleadersWeights[i][j] = weight;
        }
    }
    printf("The total weight on each cheerleader is:\n");
    for (int i = 0; i < LEVEL_OF_PYRAMID; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            float totalWeight = weightsPyramid(i, j, cheerleadersWeights);
            printf("%.2f ", totalWeight);
        }
        printf("\n");
    }
}

// The func initialize the values in the array contains the cheerleaders' weights.
void initializeChrldrsArr(float cheerleadersWeights[LEVEL_OF_PYRAMID][LEVEL_OF_PYRAMID])
{
    for (int i = 0; i < LEVEL_OF_PYRAMID; i++)
    {
        for (int j = 0; j < LEVEL_OF_PYRAMID; j++)
        {
            cheerleadersWeights[i][j] = -1;
        }
    }
}

/* The func sum the total weight supported by the cheerleader in the given row and column.*/
float weightsPyramid(int row, int cloumn, float cheerleadersWeights[LEVEL_OF_PYRAMID][LEVEL_OF_PYRAMID])
{
    if (row == 0 && cloumn == 0)
    {
        return cheerleadersWeights[row][cloumn];
    }
    // If there is no cheerleader in the top left / right.
    else if (row < 0 || cloumn < 0 || cheerleadersWeights[row][cloumn] < 0)
    {
        return 0;
    }
    float ownWeight = cheerleadersWeights[row][cloumn];
    return ((0.5 * weightsPyramid((row - 1), (cloumn - 1), cheerleadersWeights)) +
            (0.5 * weightsPyramid((row - 1), cloumn, cheerleadersWeights)) + ownWeight);
}

/* Case 3 :
The func prints instructions and result for the given input.*/
void task3ParenthesisValidator()
{
    int flag = 0;
    printf("Please enter a term for validation:\n");
    scanf("%*c");
    if (isBalanced('\0', flag))
    {
        printf("The parentheses are balanced correctly.\n");
    }
    else
    {
        printf("The parentheses are not balanced correctly.\n");
    }
}

// The func checks if a sequence of brackets is properly matched and balanced by examining each character recursively.
int isBalanced(char closerChar, int flag)
{
    char currentC;
    scanf("%c", &currentC);
    if (currentC == '\n' && flag == 0)
    {
        return isBalanced(closerChar, flag);
    }
    if (currentC == '\n')
    {
        return closerChar == '\0';
    }
    flag = 1;
    if ((currentC == '(' || currentC == '{' || currentC == '[' || currentC == '<') &&
        !isBalanced(getCloserChar(currentC), flag))
    {
        return 0;
    }
    if (currentC == ')' || currentC == '}' || currentC == ']' || currentC == '>')
    {
        if (currentC != closerChar)
        {
            clearBuffer(currentC);
            return 0;
        }
        return 1;
    }
    return isBalanced(closerChar, flag);
}

// The func returning the matching closer for the given char.
char getCloserChar(char c)
{
    if (c == '(')
    {
        return ')';
    }
    else if (c == '{')
    {
        return '}';
    }
    else if (c == '[')
    {
        return ']';
    }
    else if (c == '<')
    {
        return '>';
    }
    return '\0';
}

// The func clean the buffer recursively.
void clearBuffer(char c)
{
    if (scanf("%c", &c) == 1 && c != '\n')
    {
        clearBuffer(c);
    }
}

/* Case 4 :
 The func gets the board and the num of dimensions from the user, and eventually print the solved board
 if there is one.*/
void task4QueensBattle()
{
    char boardByUser[BOARD_DIMENSIONS][BOARD_DIMENSIONS] = {0};
    char solvedBoard[BOARD_DIMENSIONS][BOARD_DIMENSIONS] = {0};
    int boardDim, row = 0, column = 0;
    printf("Please enter the board dimensions:\n");
    scanf("%d", &boardDim);
    printf("Please enter a %d*%d puzzle board:\n", boardDim, boardDim);
    // Initialize the (future-) solved board to '*' as a start.
    initializeBoardArr(solvedBoard, row, column, BOARD_DIMENSIONS);
    // Insert the input entered by the user to the board.
    for (int i = 0; i < boardDim; i++)
    {
        for (int j = 0; j < boardDim; j++)
        {
            scanf(" %c", &boardByUser[i][j]);
        }
    }
    // If there is a solution - print it.
    if (isSolutionForBoard(solvedBoard, boardByUser, row, column, boardDim))
    {
        printf("Solution:\n");
        for (int i = 0; i < boardDim; i++)
        {
            for (int j = 0; j < boardDim; j++)
            {
                printf("%c ", solvedBoard[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("This puzzle cannot be solved.\n");
    }
}

// The func initializes the solved array with values of '*'.
void initializeBoardArr(char boardArr[BOARD_DIMENSIONS][BOARD_DIMENSIONS], int row, int column, int boardDim)
{
    if (row >= boardDim)
    {
        return;
    }
    if (column >= boardDim)
    {
        return initializeBoardArr(boardArr, (row + 1), 0, boardDim);
    }
    boardArr[row][column] = '*';
    initializeBoardArr(boardArr, row, (column + 1), boardDim);
}

// The func checks if there is a solution for the given board.
int isSolutionForBoard(char solvedBoard[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
                       char board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], int row, int column, int boardDim)
{
    if (row >= boardDim)
    {
        return 1;
    }
    if (column >= boardDim)
    {
        return 0;
    }
    // If there is no queen in row, column, close diagonal or area - locate the queen.
    if (checkIfLocationPossible(solvedBoard, board, row, column, boardDim))
    {
        solvedBoard[row][column] = 'X';
        // Do it for the row below. If possible - return 1.
        if (isSolutionForBoard(solvedBoard, board, row + 1, 0, boardDim))
        {
            return 1;
        }
        // If there is no place to locate the queen in the row below, Put '*' in the current and go back.
        solvedBoard[row][column] = '*';
    }
    // Move to next column.
    return isSolutionForBoard(solvedBoard, board, row, column + 1, boardDim);
}

/* The func checks if there is already a queeen in the given row, column, diagonal or area.
Returns 0 - If there *is* one (so we can't locate the queen in it). */
int checkIfLocationPossible(char solvedBoard[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
                            char board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], int row, int column, int boardDim)
{
    return isQueenInRow(solvedBoard, row, 0, boardDim) && isQueenInColumn(solvedBoard, 0, column, boardDim) &&
           isQueenInCloseDiagonal(solvedBoard, row, column, boardDim) &&
           isQueenInArea(solvedBoard, board, board[row][column], 0, 0, boardDim);
}

/* The func checks if there is already a queeen in the given row.
Returns 0 - If there *is* one (so we can't locate the queen in it). */
int isQueenInRow(char solvedBoard[BOARD_DIMENSIONS][BOARD_DIMENSIONS], int row, int column, int boardDim)
{
    if (column >= boardDim)
    {
        return 1;
    }
    if (solvedBoard[row][column] == 'X')
    {
        return 0;
    }
    return isQueenInRow(solvedBoard, row, column + 1, boardDim);
}

// The func checks if there is already a queeen in the given column.
int isQueenInColumn(char solvedBoard[BOARD_DIMENSIONS][BOARD_DIMENSIONS], int row, int column, int boardDim)
{
    if (row >= boardDim)
    {
        return 1;
    }
    if (solvedBoard[row][column] == 'X')
    {
        return 0;
    }
    return isQueenInColumn(solvedBoard, row + 1, column, boardDim);
}

// The func checks if there is already a queeen in the close diagonals.
int isQueenInCloseDiagonal(char solvedBoard[BOARD_DIMENSIONS][BOARD_DIMENSIONS], int row, int column, int boardDim)
{
    if ((row < boardDim - 1 && column < boardDim - 1 && solvedBoard[row + 1][column + 1] == 'X') ||
        (row < boardDim - 1 && column > 0 && solvedBoard[row + 1][column - 1] == 'X') ||
        (row > 0 && column < boardDim - 1 && solvedBoard[row - 1][column + 1] == 'X') ||
        (row > 0 && column > 0 && solvedBoard[row - 1][column - 1] == 'X'))
    {
        return 0;
    }
    return 1;
}

// The func checks if there is already a queeen in the area.
int isQueenInArea(char solvedBoard[BOARD_DIMENSIONS][BOARD_DIMENSIONS], char board[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
                  char area, int row, int column, int boardDim)
{
    if (row >= boardDim)
    {
        return 1;
    }
    if (column >= boardDim)
    {
        return isQueenInArea(solvedBoard, board, area, row + 1, 0, boardDim);
    }
    if (board[row][column] == area && solvedBoard[row][column] == 'X')
    {
        return 0;
    }
    return isQueenInArea(solvedBoard, board, area, row, column + 1, boardDim);
}

/* Case 5 :
 */
void task5CrosswordGenerator()
{
    // Todo
}
