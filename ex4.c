/******************
Name: Shira Cababia
ID:
Assignment: EX4
*******************/
#include <stdio.h>
#include <string.h>

#define LEVEL_OF_PYRAMID 5
// #define NUM_OF_CHEERLEADERS 15

void task1RobotPaths(); // 1
int robotPath(int upCoordinate, int rightCoordinate);
void task2HumanPyramid(); // 2
void initializeChrldrsArr(float cheerleadersWeights[LEVEL_OF_PYRAMID][LEVEL_OF_PYRAMID]);
float weightsPyramid(int row, int cloumn, float cheerleadersWeights[LEVEL_OF_PYRAMID][LEVEL_OF_PYRAMID]);
void task3ParenthesisValidator(); // 3
void task4QueensBattle();
void task5CrosswordGenerator();

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
            case 6: // Done
                printf("Goodbye!\n");
                break;
            case 1: // Done
                task1RobotPaths();
                break;
            case 2: // Done
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
            default: // Done
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

// Case 1 :
// The func gets the coordinates from the user, use the recursive function "robotPath" and print the number of paths.
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

// Case 2 :
/* The fun initialize the cheerleaders' weights array to invalid weight (-1), gets the weights from the user, 
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

// Case 3
void task3ParenthesisValidator()
{
    // Todo
}

void task4QueensBattle()
{
    // Todo
}

void task5CrosswordGenerator()
{
    // Todo
}
