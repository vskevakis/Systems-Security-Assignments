#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main() 
{
	int i;
	size_t bytes;
	FILE *file;
	char filenames[10][7] = {"file_0", "file_1", 
			"file_2", "file_3", "file_4",
			"file_5", "file_6", "file_7", 		
			"file_8", "file_9"};

	/* example source code */
	

	for (i = 0; i < 10; i++) {

		file = fopen(filenames[i], "w+");
		if (file == NULL) 
			printf("fopen error\n");
		else {
			bytes = fwrite(filenames[i], strlen(filenames[i]), 1, file);
			fclose(file);
		}

	}

	for (i = 0; i < 10; i++) {
		chmod(filenames[i], 0); // Revoke permissions
		file = fopen(filenames[i], "r");
		if (file == NULL) 
			printf("fopen error\n");
		else {
			bytes = fwrite(filenames[i], strlen(filenames[i]), 1, file);
			fclose(file);
		}
		chmod(filenames[i], S_IRWXU); // Return permissions
	}

	for (i = 0; i < 10; i++) {
		// chmod(filenames[i], 0); // Revoke permissions
		file = fopen(filenames[i], "a");
		if (file == NULL) 
			printf("fopen error\n");
		else {
			bytes = fwrite(filenames[i], strlen(filenames[i]), 1, file);
			fclose(file);
		}
		// chmod(filenames[i], S_IRWXU); // Return permissions
	}



	// /* add your code here */
	// file = fopen(filenames[10], "w+");
	// if (file == NULL) 
	// 	printf("fopen error\n");
	// else {
	// 	bytes = fwrite(filenames[10], strlen(filenames[10]), 1, file);
	// 	fclose(file);
	// }
	/* Setting UID to 1 */
	// int real = getuid();
	// int euid = geteuid();
	// printf("The REAL UID =: %d\n", real);
	// printf("The EFFECTIVE UID =: %d\n", euid);
	// file = fopen("test_file", "w+");
	// if (file != NULL) {
	// 	printf("Opened File");
	// }
	// fclose(file);

	/* ... */
	/* ... */
	/* ... */
	/* ... */


}
