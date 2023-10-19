#include <stdio.h>
#include <unistd.h>

int main()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num_elements = sizeof(numbers) / sizeof(numbers[0]);
    int child_pid, even_sum = 0, odd_sum = 0;

    child_pid = fork();

    if (child_pid < 0)
    {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0)
    {
        // This code is executed by the child process
        for (int i = 0; i < num_elements; i++)
        {
            if (numbers[i] % 2 != 0)
            {
                odd_sum += numbers[i];
            }
        }
        printf("Child process: Sum of odd numbers = %d\n", odd_sum);
    }
    else
    {
        // This code is executed by the parent process
        for (int i = 0; i < num_elements; i++)
        {
            if (numbers[i] % 2 == 0)
            {
                even_sum += numbers[i];
            }
        }
        wait(NULL); // Wait for the child process to finish
        printf("Parent process: Sum of even numbers = %d\n", even_sum);
    }

    return 0;
}
