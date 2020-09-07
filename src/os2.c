#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
	int d;
	int fd;
	int pipe_fd[2];
	pid_t pid;
	char name_file[20];
	int count_process;
	int m;
	int err = 0;
	printf("\n==========\nEnter name file\n");
	scanf ("%s", name_file);
	printf("Enter n\n");
	scanf ("%d", &count_process);
	printf("Enter m\n");
	scanf ("%d", &m);

	int i = 0;

	for (i; i < count_process; ++i) {
		if(pipe(pipe_fd) == -1) {
			perror("PIPE");
			err = -2;
		}

		pid = fork();

		if(pid == -1) {
			perror("FORK");
			err = -1;
		}
		else if (pid == 0) {
			printf("Child\n");
			close(pipe_fd[1]);

			fd = open(name_file, O_CREAT | O_APPEND | O_WRONLY, S_IWUSR | S_IRUSR);
			dup2(fd, 1);

			while(read(pipe_fd[0], &d, sizeof(d)) > 0) {
				printf("%d ", d);
			}
			printf("\n");
			close(fd);
			break;
		} else {
			close(pipe_fd[0]);
			printf("Enter number\n");

			for (int i = 0; i < m; ++i)
				write(pipe_fd[1], &i, sizeof(i));

			close(pipe_fd[1]);
		}
		printf("End Enter\n");

	}

	return err;
}
